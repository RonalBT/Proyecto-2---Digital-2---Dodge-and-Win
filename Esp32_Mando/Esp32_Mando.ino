#include <PS4Controller.h>

int   salto1 = 15;
int   agacharse1 = 16;
int   Cambiar_opcionAbajo = 0;
int   Cambiar_opcionArriba = 2;
int   Seleccionar_opcion = 4;

void notify()
{
  digitalWrite(salto1,  PS4.L1());
  digitalWrite(agacharse1, PS4.R1());
  digitalWrite(Cambiar_opcionAbajo, PS4.Down());
  digitalWrite(Cambiar_opcionArriba, PS4.Up());
  digitalWrite(Seleccionar_opcion, PS4.Cross());
}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}

void setUpPinModes()
{
  pinMode(salto1, OUTPUT);
  pinMode(agacharse1, OUTPUT);
  pinMode(Cambiar_opcionAbajo, OUTPUT);
  pinMode(Cambiar_opcionArriba, OUTPUT);
  pinMode(Seleccionar_opcion, OUTPUT);
}

void setup() 
{
  setUpPinModes();
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");
}

void loop() 
{

}
