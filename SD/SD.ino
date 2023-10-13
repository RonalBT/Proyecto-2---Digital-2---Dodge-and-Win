//***************************************************************************************************************************************
/* Librería para el uso de la pantalla ILI9341 en modo 8 bits
 * Basado en el código de martinayotte - https://www.stm32duino.com/viewtopic.php?t=637
 * Adaptación, migración y creación de nuevas funciones: Pablo Mazariegos y José Morales
 * Con ayuda de: José Guerra
 * IE3027: Electrónica Digital 2 - 2019
 */
//***************************************************************************************************************************************
#include <stdint.h>
//***************************************************************************************************************************************
/* Librería para el uso de la pantalla ILI9341 en modo SPI
 * Basado en el código de martinayotte - https://www.stm32duino.com/viewtopic.php?t=637
 * Adaptación, migración y creación de nuevas funciones: Pablo Mazariegos y José Morales
 * Con ayuda de: José Guerra
 * IE3027: Electrónica Digital 2 - 2019
 */
//***************************************************************************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <TM4C123GH6PM.h>
//#include <iostream>
//#include <string>
#include <SPI.h>
#include <SD.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

#include "bitmaps.h"
#include "font.h"
#include "lcd_registers.h"

File myFile;

extern unsigned char fondoVolcan[];
extern unsigned char Bloquelava[];

unsigned char maps[640];          //Se crea arreglo vació para guardar el mapeo

const int Button1 = 2; //Saltar
int salto = 0;
int agacharse = 0;
const int Button2 = 18; //Agacharse
int PosYMasterchief = 0;
int PosBola = 320;
int PosBola1 = 320;
int PosBola2 = 320;
int PuntajeJuego = 0;
bool IMPACTO = false;
bool IMPACTO1 = false;
bool IMPACTO2 = false;
int Muerte = 0;
int Patron = 0;


// El SPI es el 0
//MOSI va a PA_5
//MISO va a PA_4
//SCK va a PA_2

#define LCD_RST PD_0
#define LCD_DC PD_1
#define LCD_CS PA_3

const int chipSelectLCD = 12;
//***************************************************************************************************************************************
// Functions Prototypes
//***************************************************************************************************************************************
void LCD_Init(void);
void LCD_CMD(uint8_t cmd);
void LCD_DATA(uint8_t data);
void SetWindows(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void LCD_Clear(unsigned int c);
void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c);
void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c);
void Rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c);
void FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c);
void LCD_Print(String text, int x, int y, int fontSize, int color, int background);

void LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]);
void LCD_Sprite(int x, int y, int width, int height, unsigned char bitmap[],int columns, int index, char flip, char offset);
void printDirectory(File dir, int numTabs);
void BolaFuego(void);
bool Impacto(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
void Perdedor(void);
int ascii2hex(int a);
void mapeo_SD (char doc[],int x, int y, int w, int h);
void mostrarImagen(const char *nombreArchivo);

//***************************************************************************************************************************************
// Inicialización
//***************************************************************************************************************************************
void setup() {   
  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
  Serial.begin(115200);

  pinMode(Button1, INPUT);     
  pinMode(Button2, INPUT);  

  pinMode(12, OUTPUT); 
  pinMode(32, OUTPUT); 
  SPI.setModule(0);
  digitalWrite(12, LOW);
  delay(10);
  Serial.println("Inicio");
  LCD_Init();
  LCD_Clear(0x00);
  
  digitalWrite(12, HIGH);
  delay(1000);

  digitalWrite(32, LOW);
  delay(10);
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.

  if (!SD.begin(32)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  mapeo_SD("Fondo.txt", 0, 0, 320, 240);
  mapeo_SD("Bloque.txt", 0, 208, 320, 32);

  Serial.println("Inicio");
  delay(10);
  digitalWrite(32, HIGH);
  delay(1000);

  Serial.println("Inicio");
  delay(5000);
}
//***************************************************************************************************************************************
// Loop Infinito
//***************************************************************************************************************************************
void loop() {
  //Serial.println("Inicio");
  if(digitalRead(Button1) == HIGH){
    salto = 1;
  }

  if(digitalRead(Button1) == LOW){
    //salto = 0;
  }

  if(digitalRead(Button2) == HIGH){
    agacharse = 1;
  }

  if(digitalRead(Button2) == LOW){
    agacharse = 0;
  }


  if(salto == 1 && agacharse == 0 && Muerte == 0){
    for(int y = 175; y > 128; y--){
      //delay(2);
      //int anim2 = (y/11)%1;
      LCD_Bitmap(20, y, 32, 32, MasterSalto);
      //LCD_Sprite(20, y, 32, 32, MasterSalto,1, anim2,0, 0);
      H_line(20, y+32, 31, 0x1841);
      BolaFuego();

      PuntajeJuego++;

      char Puntaje[]= {};
      sprintf(Puntaje, "%d", PuntajeJuego);
      LCD_Print(Puntaje, 240, 20, 2, 0xffff, 0x421b);
      
      if(Patron == 0){
        IMPACTO = Impacto(PosBola, 197, 16, 9, 22, y, 31, 32);
        IMPACTO1 = Impacto(PosBola1, 192, 16, 9, 22, y, 31, 32);
        IMPACTO2 = Impacto(PosBola2, 171, 16, 9, 22, y, 31, 32);
      }
      else if(Patron == 1){
        IMPACTO = Impacto(PosBola, 197, 16, 9, 22, y, 31, 32);
        IMPACTO1 = Impacto(PosBola1, 171, 16, 9, 22, y, 31, 32);
        IMPACTO2 = Impacto(PosBola2, 188, 16, 9, 22, y, 31, 32);
      }
      
      if(IMPACTO == true | IMPACTO1 == true | IMPACTO2 == true){
        LCD_Bitmap(20, 128, 32, 48, PedazoSalto);
        LCD_Bitmap(20, 176, 32, 32, PedazoInferiorSalto);
        Muerte = 1;
        Perdedor();
        break;
      }
    }
    
    for(int y = 129; y < 176; y++){
      //delay(2);
      int anim2 = (y/11)%1;
      LCD_Bitmap(20, y, 32, 32, MasterSalto);
      //LCD_Sprite(20, y, 32, 32, MasterSalto,1, anim2,0, 0);
      H_line(20, y-1, 31, 0x1841);
      BolaFuego();
      
      PuntajeJuego++;

      char Puntaje[]= {};
      sprintf(Puntaje, "%d", PuntajeJuego);
      LCD_Print(Puntaje, 240, 20, 2, 0xffff, 0x421b);

      if(Patron == 0){
        IMPACTO = Impacto(PosBola, 197, 16, 9, 22, y, 31, 32);
        IMPACTO1 = Impacto(PosBola1, 192, 16, 9, 22, y, 31, 32);
        IMPACTO2 = Impacto(PosBola2, 171, 16, 9, 22, y, 31, 32);
      }
      else if(Patron == 1){
        IMPACTO = Impacto(PosBola, 197, 16, 9, 22, y, 31, 32);
        IMPACTO1 = Impacto(PosBola1, 171, 16, 9, 22, y, 31, 32);
        IMPACTO2 = Impacto(PosBola2, 188, 16, 9, 22, y, 31, 32);
      }
      
      if(IMPACTO == true | IMPACTO1 == true | IMPACTO2 == true){
        LCD_Bitmap(20, 128, 32, 48, PedazoSalto);
        LCD_Bitmap(20, 176, 32, 32, PedazoInferiorSalto);
        Muerte = 1;
        Perdedor();
        break;
      }
    }
    salto = 0;
  }

  if(agacharse == 1 && salto == 0 && Muerte == 0){
    //delay(1);
    LCD_Bitmap(20, 176, 32, 32, MasterAgacharse);
    BolaFuego();
    PuntajeJuego++;

    char Puntaje[]= {};
    sprintf(Puntaje, "%d", PuntajeJuego);
    LCD_Print(Puntaje, 240, 20, 2, 0xffff, 0x421b);
    
    if(Patron == 0){
      IMPACTO = Impacto(PosBola, 197, 16, 9, 21, 180, 31, 32);
      IMPACTO1 = Impacto(PosBola1, 192, 16, 9, 21, 180, 31, 32);
      IMPACTO2 = Impacto(PosBola2, 171, 16, 9, 21, 180, 31, 32);
    }
    else if (Patron == 1){
      IMPACTO = Impacto(PosBola, 197, 16, 9, 21, 180, 31, 32);
      IMPACTO1 = Impacto(PosBola1, 171, 16, 9, 21, 180, 31, 32);
      IMPACTO2 = Impacto(PosBola2, 188, 16, 9, 21, 180, 31, 32);
    }
    
    if(IMPACTO == true | IMPACTO1 == true | IMPACTO2 == true){
      Muerte = 1;
      Perdedor();
    }
  }
  
  if(salto == 0 && agacharse == 0 && Muerte == 0){
    for(int x = 0; x < 10; x++){
       int anim3 = (x/4)%4;
       //int anim2 = (x/4)%4;
       LCD_Sprite(20, 176, 32, 32, MasterChief,4, anim3,1, 0);
       LCD_Sprite(63, 176, 32, 32, MasterChief2,4, anim3,1, 0);
       //LCD_Sprite(63, 176, 32, 32, Master2 ,4, anim2,1, 0);
       LCD_Bitmap(20, 128, 32, 48, PedazoSalto);
       BolaFuego();
       BolaFuego();

       PuntajeJuego++;

       char Puntaje[]= {};
       sprintf(Puntaje, "%d", PuntajeJuego);
       LCD_Print(Puntaje, 240, 20, 2, 0xffff, 0x421b);

       if(Patron == 0){
         IMPACTO = Impacto(PosBola, 197, 16, 9, 21, 176, 31, 32);
         IMPACTO1 = Impacto(PosBola1, 192, 16, 9, 21, 176, 31, 32);
         IMPACTO2 = Impacto(PosBola2, 171, 16, 9, 21, 176, 31, 32);
       }
       else if(Patron == 1){
         IMPACTO = Impacto(PosBola, 197, 16, 9, 21, 176, 31, 32);
         IMPACTO1 = Impacto(PosBola1, 171, 16, 9, 21, 176, 31, 32);
         IMPACTO2 = Impacto(PosBola2, 188, 16, 9, 21, 176, 31, 32);
       }
      
       if(IMPACTO == true | IMPACTO1 == true | IMPACTO2 == true){
        Muerte = 1;
        Perdedor();
       }
    }
  }
}

//***************************************************************************************************************************************
// Función para inicializar LCD
//***************************************************************************************************************************************
void BolaFuego(){

  if (Patron == 0){
    LCD_Bitmap(PosBola, 197, 16, 9, bolaFuego);
    PosBola--;
    V_line(PosBola+17, 197, 9, 0x1841);
    
    if(PosBola < 180){
      LCD_Bitmap(PosBola1, 192, 16, 9, bolaFuego);
      V_line(PosBola1+17, 192, 9, 0x1841);
      PosBola1--;
    }
    if(PosBola < 60){
      LCD_Bitmap(PosBola2, 171, 16, 9, bolaFuego);
      V_line(PosBola2+17, 171, 9,  0x1841);
      PosBola2--;
    }
  } 
  else if (Patron == 1){
    LCD_Bitmap(PosBola, 197, 16, 9, bolaFuego);
    PosBola--;
    V_line(PosBola+17, 197, 9, 0x1841);
    
    if(PosBola < 180){
      LCD_Bitmap(PosBola1, 171, 16, 9, bolaFuego);
      V_line(PosBola1+17, 171, 9, 0x1841);
      PosBola1--;
    }
    if(PosBola < 60){
      LCD_Bitmap(PosBola2, 188, 16, 9, bolaFuego);
      V_line(PosBola2+17, 188, 9,  0x1841);
      PosBola2--;
    }
    //Patron = -1;
  }
  
  if (PosBola2 == 0){
    Patron = !Patron;
    LCD_Bitmap(0, 168, 20, 40, PedazoBolaFuego);
    PosBola = 252; 
    PosBola1 = 320; 
    PosBola2 = 320; 
  }

  /*if (PosBola2 == 59){
    Patron+=1;
  }*/
}

//***************************************************************************************************************************************
// Función para comprobar impacto
//***************************************************************************************************************************************
bool Impacto(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
  return (x1 < x2 + w2) && (x1 + w1 > x2) && (y1 < y2 + h2) && (y1 + h1 > y2);
}

void Perdedor(void){
  String text1 = "Muerto";
  LCD_Print(text1, 10, 100, 2, 0xffff, 0x421b);
  //LCD_Bitmap(20, 176, 32, 32, AnimacionMuerte);
  //}*/
  for(int x = 0; x < 30; x++){
    int anim3 = (x/16)%4;
    //LCD_Sprite(20, 176, 32, 32, AnimacionMuerte,4, anim3,0, 0);
  }
}


//***************************************************************************************************************************************
// Función para mostrar las imagenes desde SD
//***************************************************************************************************************************************
void mapeo_SD (char doc[], int x, int y, int w, int h){
  myFile = SD.open(doc, FILE_READ); //Se toma el archivo de la imagen
  int hex1 = 0; 
  int val1 = 0;
  int val2 = 0;
  int mapear = 0;
  int vertical = y;
  
  if(myFile){
    while (myFile.available()){     //Se leen los datos mientras esté disponible
      mapear = 0;
      while(mapear < 640){          //Se limita el rango
        hex1 = myFile.read();       //Se lee el archivo con la imagen
        if(hex1 == 120){
          val1 = myFile.read();      //Se lee el primer valor hexadecimal del bitmap
          val2 = myFile.read();      //Se lee el segundo valor hexadecimal del bitmap
          val1 = ascii2hex(val1);    //Se mapea el primer valor hexadecimal
          val2 = ascii2hex(val2);    //Se mapea el segundo valor hexadecimal
          maps[mapear] = val1 * 16 + val2; //Se coloca en el nuevo arreglo
          mapear++;
        }
      }
      LCD_Bitmap(x, vertical, w, 1, maps);
      vertical++;
      if (vertical == y + h){
        return;
      }
    }
    Serial.println("Fin");
    myFile.close();
  }
  else{
    Serial.println("No se pudo abrir la imagen, prueba nuevamente");
    myFile.close();
  }
}

//***************************************************************************************************************************************
// Función para mapear los valores Hex del bitmap a decimales
//***************************************************************************************************************************************
int ascii2hex(int a){
  switch(a){
    case (48): //caso 0
      return 0;
    case (49): //caso 1
      return 1;
    case (50): //caso 2
      return 2;
    case (51): //caso 3
      return 3;
    case (52): //caso 4
      return 4;
    case (53): //caso 5
      return 5;
    case (54): //caso 6
      return 6;
    case (55): //caso 7
      return 7;
    case (56): //caso 8
      return 8;
    case (57): //caso 9
      return 9;
    case (97): //caso A
      return 10;
    case (98): //caso B
      return 11;
    case (99): //caso C
      return 12;
    case (100): //caso D
      return 13;
    case (101): //caso E
      return 14;
    case (102): //caso F
      return 15;
  }
}

void printDirectory(File dir, int numTabs){
  while (true){

    File entry = dir.openNextFile();
    if(! entry){
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++){
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if(entry.isDirectory()){
      Serial.println(" ");
    } else {
    Serial.print("\t\t");
    Serial.println(entry.size());
    }
    entry.close();
  }
}

//***************************************************************************************************************************************
// Función para inicializar LCD
//***************************************************************************************************************************************
void LCD_Init(void) {
  pinMode(LCD_RST, OUTPUT);
  pinMode(LCD_CS, OUTPUT);
  pinMode(LCD_DC, OUTPUT);
  //****************************************
  // Secuencia de Inicialización
  //****************************************
  digitalWrite(LCD_CS, HIGH);
  digitalWrite(LCD_DC, HIGH);
  digitalWrite(LCD_RST, HIGH);
  delay(5);
  digitalWrite(LCD_RST, LOW);
  delay(20);
  digitalWrite(LCD_RST, HIGH);
  delay(150);
  digitalWrite(LCD_CS, LOW);
  //****************************************
  LCD_CMD(0xE9);  // SETPANELRELATED
  LCD_DATA(0x20);
  //****************************************
  LCD_CMD(0x11); // Exit Sleep SLEEP OUT (SLPOUT)
  delay(100);
  //****************************************
  LCD_CMD(0xD1);    // (SETVCOM)
  LCD_DATA(0x00);
  LCD_DATA(0x71);
  LCD_DATA(0x19);
  //****************************************
  LCD_CMD(0xD0);   // (SETPOWER) 
  LCD_DATA(0x07);
  LCD_DATA(0x01);
  LCD_DATA(0x08);
  //****************************************
  LCD_CMD(0x36);  // (MEMORYACCESS)
  LCD_DATA(0x40|0x80|0x20|0x08); // LCD_DATA(0x19);
  //****************************************
  LCD_CMD(0x3A); // Set_pixel_format (PIXELFORMAT)
  LCD_DATA(0x05); // color setings, 05h - 16bit pixel, 11h - 3bit pixel
  //****************************************
  LCD_CMD(0xC1);    // (POWERCONTROL2)
  LCD_DATA(0x10);
  LCD_DATA(0x10);
  LCD_DATA(0x02);
  LCD_DATA(0x02);
  //****************************************
  LCD_CMD(0xC0); // Set Default Gamma (POWERCONTROL1)
  LCD_DATA(0x00);
  LCD_DATA(0x35);
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0x02);
  //****************************************
  LCD_CMD(0xC5); // Set Frame Rate (VCOMCONTROL1)
  LCD_DATA(0x04); // 72Hz
  //****************************************
  LCD_CMD(0xD2); // Power Settings  (SETPWRNORMAL)
  LCD_DATA(0x01);
  LCD_DATA(0x44);
  //****************************************
  LCD_CMD(0xC8); //Set Gamma  (GAMMASET)
  LCD_DATA(0x04);
  LCD_DATA(0x67);
  LCD_DATA(0x35);
  LCD_DATA(0x04);
  LCD_DATA(0x08);
  LCD_DATA(0x06);
  LCD_DATA(0x24);
  LCD_DATA(0x01);
  LCD_DATA(0x37);
  LCD_DATA(0x40);
  LCD_DATA(0x03);
  LCD_DATA(0x10);
  LCD_DATA(0x08);
  LCD_DATA(0x80);
  LCD_DATA(0x00);
  //****************************************
  LCD_CMD(0x2A); // Set_column_address 320px (CASET)
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0x3F);
  //****************************************
  LCD_CMD(0x2B); // Set_page_address 480px (PASET)
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0xE0);
//  LCD_DATA(0x8F);
  LCD_CMD(0x29); //display on 
  LCD_CMD(0x2C); //display on

  LCD_CMD(ILI9341_INVOFF); //Invert Off
  delay(120);
  LCD_CMD(ILI9341_SLPOUT);    //Exit Sleep
  delay(120);
  LCD_CMD(ILI9341_DISPON);    //Display on
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para enviar comandos a la LCD - parámetro (comando)
//***************************************************************************************************************************************
void LCD_CMD(uint8_t cmd) {
  digitalWrite(LCD_DC, LOW);
  SPI.transfer(cmd);
}
//***************************************************************************************************************************************
// Función para enviar datos a la LCD - parámetro (dato)
//***************************************************************************************************************************************
void LCD_DATA(uint8_t data) {
  digitalWrite(LCD_DC, HIGH);
  SPI.transfer(data);
}
//***************************************************************************************************************************************
// Función para definir rango de direcciones de memoria con las cuales se trabajara (se define una ventana)
//***************************************************************************************************************************************
void SetWindows(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
  LCD_CMD(0x2a); // Set_column_address 4 parameters
  LCD_DATA(x1 >> 8);
  LCD_DATA(x1);   
  LCD_DATA(x2 >> 8);
  LCD_DATA(x2);   
  LCD_CMD(0x2b); // Set_page_address 4 parameters
  LCD_DATA(y1 >> 8);
  LCD_DATA(y1);   
  LCD_DATA(y2 >> 8);
  LCD_DATA(y2);   
  LCD_CMD(0x2c); // Write_memory_start
}
//***************************************************************************************************************************************
// Función para borrar la pantalla - parámetros (color)
//***************************************************************************************************************************************
void LCD_Clear(unsigned int c){  
  unsigned int x, y;
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_DC, HIGH);
  digitalWrite(LCD_CS, LOW);   
  SetWindows(0, 0, 319, 239); // 479, 319);
  for (x = 0; x < 320; x++)
    for (y = 0; y < 240; y++) {
      LCD_DATA(c >> 8); 
      LCD_DATA(c); 
    }
  digitalWrite(LCD_CS, HIGH);
} 
//***************************************************************************************************************************************
// Función para dibujar una línea horizontal - parámetros ( coordenada x, cordenada y, longitud, color)
//*************************************************************************************************************************************** 
void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c) {  
  unsigned int i, j;
  LCD_CMD(0x02c); //write_memory_start
  digitalWrite(LCD_DC, HIGH);
  digitalWrite(LCD_CS, LOW);
  l = l + x;
  SetWindows(x, y, l, y);
  j = l;// * 2;
  for (i = 0; i < l; i++) {
      LCD_DATA(c >> 8); 
      LCD_DATA(c); 
  }
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para dibujar una línea vertical - parámetros ( coordenada x, cordenada y, longitud, color)
//*************************************************************************************************************************************** 
void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c) {  
  unsigned int i,j;
  LCD_CMD(0x02c); //write_memory_start
  digitalWrite(LCD_DC, HIGH);
  digitalWrite(LCD_CS, LOW);
  l = l + y;
  SetWindows(x, y, x, l);
  j = l; //* 2;
  for (i = 1; i <= j; i++) {
    LCD_DATA(c >> 8); 
    LCD_DATA(c);
  }
  digitalWrite(LCD_CS, HIGH);  
}
//***************************************************************************************************************************************
// Función para dibujar un rectángulo - parámetros ( coordenada x, cordenada y, ancho, alto, color)
//***************************************************************************************************************************************
void Rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c) {
  H_line(x  , y  , w, c);
  H_line(x  , y+h, w, c);
  V_line(x  , y  , h, c);
  V_line(x+w, y  , h, c);
}
//***************************************************************************************************************************************
// Función para dibujar un rectángulo relleno - parámetros ( coordenada x, cordenada y, ancho, alto, color)
//***************************************************************************************************************************************
void FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c) {
  unsigned int i;
  for (i = 0; i < h; i++) {
    H_line(x  , y  , w, c);
    H_line(x  , y+i, w, c);
  }
}
//***************************************************************************************************************************************
// Función para dibujar texto - parámetros ( texto, coordenada x, cordenada y, color, background) 
//***************************************************************************************************************************************
void LCD_Print(String text, int x, int y, int fontSize, int color, int background) {
  int fontXSize ;
  int fontYSize ;
  
  if(fontSize == 1){
    fontXSize = fontXSizeSmal ;
    fontYSize = fontYSizeSmal ;
  }
  if(fontSize == 2){
    fontXSize = fontXSizeBig ;
    fontYSize = fontYSizeBig ;
  }
  
  char charInput ;
  int cLength = text.length();
  Serial.println(cLength,DEC);
  int charDec ;
  int c ;
  int charHex ;
  char char_array[cLength+1];
  text.toCharArray(char_array, cLength+1) ;
  for (int i = 0; i < cLength ; i++) {
    charInput = char_array[i];
    Serial.println(char_array[i]);
    charDec = int(charInput);
    digitalWrite(LCD_CS, LOW);
    SetWindows(x + (i * fontXSize), y, x + (i * fontXSize) + fontXSize - 1, y + fontYSize );
    long charHex1 ;
    for ( int n = 0 ; n < fontYSize ; n++ ) {
      if (fontSize == 1){
        charHex1 = pgm_read_word_near(smallFont + ((charDec - 32) * fontYSize) + n);
      }
      if (fontSize == 2){
        charHex1 = pgm_read_word_near(bigFont + ((charDec - 32) * fontYSize) + n);
      }
      for (int t = 1; t < fontXSize + 1 ; t++) {
        if (( charHex1 & (1 << (fontXSize - t))) > 0 ) {
          c = color ;
        } else {
          c = background ;
        }
        LCD_DATA(c >> 8);
        LCD_DATA(c);
      }
    }
    digitalWrite(LCD_CS, HIGH);
  }
}
//***************************************************************************************************************************************
// Función para dibujar una imagen a partir de un arreglo de colores (Bitmap) Formato (Color 16bit R 5bits G 6bits B 5bits)
//***************************************************************************************************************************************
void LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]){  
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_DC, HIGH);
  digitalWrite(LCD_CS, LOW); 
  
  unsigned int x2, y2;
  x2 = x+width;
  y2 = y+height;
  SetWindows(x, y, x2-1, y2-1);
  unsigned int k = 0;
  unsigned int i, j;

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      LCD_DATA(bitmap[k]);
      LCD_DATA(bitmap[k+1]);
      //LCD_DATA(bitmap[k]);    
      k = k + 2;
     } 
  }
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para dibujar una imagen sprite - los parámetros columns = número de imagenes en el sprite, index = cual desplegar, flip = darle vuelta
//***************************************************************************************************************************************
void LCD_Sprite(int x, int y, int width, int height, unsigned char bitmap[],int columns, int index, char flip, char offset){
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_DC, HIGH);
  digitalWrite(LCD_CS, LOW); 

  unsigned int x2, y2;
  x2 =   x+width;
  y2=    y+height;
  SetWindows(x, y, x2-1, y2-1);
  int k = 0;
  int ancho = ((width*columns));
  if(flip){
  for (int j = 0; j < height; j++){
      k = (j*(ancho) + index*width -1 - offset)*2;
      k = k+width*2;
     for (int i = 0; i < width; i++){
      LCD_DATA(bitmap[k]);
      LCD_DATA(bitmap[k+1]);
      k = k - 2;
     } 
  }
  }else{
     for (int j = 0; j < height; j++){
      k = (j*(ancho) + index*width + 1 + offset)*2;
     for (int i = 0; i < width; i++){
      LCD_DATA(bitmap[k]);
      LCD_DATA(bitmap[k+1]);
      k = k + 2;
     } 
  }
    }
  digitalWrite(LCD_CS, HIGH);
}
