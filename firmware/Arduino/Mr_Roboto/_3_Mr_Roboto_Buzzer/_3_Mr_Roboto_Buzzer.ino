/* SparkFun Mr. Roboto Buzzer Example Sketch
   by: Jim Lindblom, adapted from Tom Igoe's toneMelody example
   date: December 13, 2011
   
   license: This code is all released under the public 
   domain. It's provided as an educational example. Please 
   use it in any way you see fit.
   
   Did you know Mr. Roboto sings through his nose? Give him a 
   tune and he'll nose-whistle it to his best ability. It doesn't
   sound all that great, but don't tell him that.
   
   This example code shows how you can use the tone() function, in
   conjunction with the pitches.h file included.
*/
/* pitches.h gives us nicely pre-defined notes. If you want to
   look at what notes are available, click the "pitches.h" tab
   right under the toobar up there. */
#include "pitches.h"  

/* Pin Definitions */
const int buzzerPin = 6;  // we'll only use the buzzer in this example

/* Here we'll define our song's 
   speed, notes and note durations: */
// beatsPerMinute controls how fast the song plays
// bigger number = faster tune
const float beatsPerMinute = 60;

// domoAregatoLength indicates the number of notes in
// our song.
const int domoAregatoLength = 12;

// domoAregotoNotes is an array, which contains the
// sequence of notes Mr. Roboto will play.
int domoAregatoNotes[domoAregatoLength] = {
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_DS4, NOTE_REST,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_DS4};

// domoAregatoDurations contains the duration of each
// note, which we defined in domoAregatoNotes
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int domoAregatoDurations[domoAregatoLength] = {
  8, 8, 8, 8, 8, 4, 0,// do-mo-ar-e-ga-to-
  4, 4, 8, 8, 4 };  // mis-ter-ro-bot-o

void setup()
{
  // you have to set the buzzer as an output
  pinMode(buzzerPin, OUTPUT);
  
  /* Each time we go through this for loop it'll output one
     note. It'll run through the for loop 12 times (or whatever
     you've got domoAregatoLength set to */
  for (int thisNote = 0; thisNote < domoAregatoLength; thisNote++) 
  {
    /* to calculate the note duration in ms divide beatsPerMinute
       into 60000 (1000 ms/s * 60 s/m).
       Then divide it by the note type.
       e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc. */
    int noteDuration = (60000/beatsPerMinute)/domoAregatoDurations[thisNote];
    
    /* tone is what makes the magic happen. This is how Mr. Roboto 
       makes noise.
       The first parameter in tone() is the pin.
       The second parameter is the note.
       The third parameter is the duration of the note. */
    tone(buzzerPin, domoAregatoNotes[thisNote],noteDuration);
  
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  delay(2000);  // pause, let Mr. Roboto take a breath
  
  // Now lets show off Mr. Roboto's range, cover your ears
  // Run a for loop, ranging from 20Hz to 10000Hz, going up
  // in steps of 5.
  for (int frequency = 20; frequency <= 10000; frequency++)
    tone(buzzerPin, frequency, 50);  // output the sounds
}

void loop()
{
  /* We're not going to do anything in the loop.
     You may need to invest in earplugs if you listen to
     Mr. Roboto sing too much. */
}

