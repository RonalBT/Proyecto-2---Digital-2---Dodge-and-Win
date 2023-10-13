#include <stdint.h>
#include <stdbool.h>
#include <TM4C123GH6PM.h>
#include "pitches.h"


/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/Tone

*/
const int entrada1 = 3;
const int entrada2 = 4;
int contadormusica = 0;


// notes in the melody:
int melody[] = {

  NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_C3, NOTE_C3,
  NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_A2,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  1, 8, 8, 8, 1, 8, 8, 8, 1, 8, 8, 8, 1, 2, 1, 4, 4, 4, 1, 8
};
int melody2[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};
void setup() {
  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  // iterate over the notes of the melody:

}

void loop() {
  if ( digitalRead(entrada1) == HIGH){     
     contadormusica++;
      if (contadormusica > 19){
        contadormusica = 0;
      }

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[contadormusica];

    tone(35, melody[contadormusica], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(35);

  
  // no need to repeat the melody.
  }

  if ( digitalRead(entrada2) == HIGH){     
     contadormusica++;
      if (contadormusica > 7){
        contadormusica = 0;
      }

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations2[contadormusica];

    tone(35, melody2[contadormusica], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(35);

  
  // no need to repeat the melody.
  }
}
