#include <stdint.h>
#include <stdbool.h>
#include <TM4C123GH6PM.h>
#include "pitches.h"


//Definimos variables 
const int entrada1 = 3;
const int entrada2 = 4;
int contadormusica = 0;


// Definimos notas a utilizar en la melodía
int melody[] = {

  NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_C3, NOTE_C3,
  NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_A2,
};

//Definimos el tiempo de cada nota en la melodía
int noteDurations[] = {

  1, 8, 8, 8, 1, 8, 8, 8, 1, 8, 8, 8, 1, 2, 1, 4, 4, 4, 1, 8
};

int melody2[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};


int noteDurations2[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  // iterate over the notes of the melody:

}

void loop() {
  //Activación de bandera para primera canción
  if ( digitalRead(entrada1) == HIGH){     
     contadormusica++;
      if (contadormusica > 19){
        contadormusica = 0;
      }
    
    int noteDuration = 1000 / noteDurations[contadormusica];

    tone(35, melody[contadormusica], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    noTone(35);

  
  }
//Activación de bandera para la segunda canción
  if ( digitalRead(entrada2) == HIGH){     
     contadormusica++;
      if (contadormusica > 7){
        contadormusica = 0;
      }

    int noteDuration = 1000 / noteDurations2[contadormusica];

    tone(35, melody2[contadormusica], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    noTone(35);

  }
}
