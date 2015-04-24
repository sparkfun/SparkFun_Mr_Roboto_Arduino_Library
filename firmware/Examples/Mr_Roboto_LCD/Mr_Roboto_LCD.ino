/* SparkFun Mr. Roboto LED Example Sketch
   by: Jim Lindblom
   date: December 13, 2011
   
   license: This code is all released under the public 
   domain. It's provided as an educational example. Please 
   use it in any way you see fit.
   
   Aside from whistling music through his nose Mr. Roboto is
   pretty mute. When he has something to say, he'll usually
   spit it out using his 16-character (2 row, 8 column) LCD-mouth.
   
   This example sketch will show how you can control Mr. Roboto
   to say all kinds of crazy things. Once Mr. Roboto has run through
   some demo stuff, he'll go into copycat mode. You can open up the
   Serial Monitor and anything you type and send will be echoed
   on Mr. Roboto's LCD mouth.
   
   This sketch uses a modified version of the LiquidCrystal library.
   You'll need to install that in order for the LCD to work 
   correctly. It should be included with this code pack, 
   or you can download it from here:
   http://code.google.com/p/liquidcrystal440/downloads/list
   The library should be installed in the 'libraries' folder of your
   Arduino sketchbook (go to File > Preferences to see where that is).
*/

/* We must tell Arduino to include the LiquidCrystal440
   library. Make sure it's installed (see above).
*/
#include <LiquidCrystal.h>

/* Pin Definitions */
// Don't worry about the functionality of these pins
// The LiquidCrystal440 library takes care of all control on these pins
int lcdRSPin = 13;  // Register select pin
int lcdENPin = 12;  // Enable pin
int lcdD4Pin = 11;  // Data bus line 4
int lcdD5Pin = 8;  // Data bus line 5
int lcdD6Pin = 7;  // Data bus line 6
int lcdD7Pin = 4;  // Data bus line 7
// We will make use of this pin though:
// Use it just like you would an LED
int lcdBacklightPin = 5;  // LCD Backlight control pin

/* We've got to tell Mr. Roboto to set up the LCD first
   This next line of code tells him which pins to use for the LCD.
   And it tells him we're going to call the lcd... "lcd". */
LiquidCrystal lcd(lcdRSPin, 255, lcdENPin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

void setup()
{
  /* First, let's start the LCD up. We've got to tell Mr. Roboto
     how many columns the LCD has (8) as well as how many rows (2). */
  lcd.begin(8, 2);  // Begin the LCD, this will also clear it
  /* The LCD's backlight is actually an LED, just like Mr. Roboto's
     eyes. analogWrite()'ing it to 255 will turn the backlight
     fully on. You could also digitalWrite() it HIGH */
  analogWrite(lcdBacklightPin, 255);  // Turn the backlight ON
  
  /* You can't see it, but Mr. Roboto's LCD has a cursor, just
     like this Arduino sketch editor, which advances one space
     each time it prints a character. The cursor starts at the
     very first character cell (0, 0) (top-left)*/
  lcd.print("Mr."); // This will print "Mr." beginning at the top left (0, 0)
  // The cursor is now on column 3, row 0. But what if you want to
  // move it down a line?
  lcd.setCursor(0, 1);  // This will set the cursor to column 0, row 1 (
  lcd.print("Roboto!");  // Now print "Roboto!" on the bottom line
  delay(2000);  // Delay for some visibility
  
  // Let's blink the LCD to show it's functionality
  digitalWrite(lcdBacklightPin, LOW);  // this will turn the LCD OFF
  lcd.clear();  // Clear the screen
  lcd.setCursor(3, 0);  // set the cursor to 3, 0
  lcd.print("OFF");  // Print "OFF"
  delay(2000);  // delay for 2 seconds
  
  analogWrite(lcdBacklightPin, 127);  // this will set the backlight to half intensity
  lcd.clear();
  lcd.setCursor(3, 0);  // Set cursor to 0, 0
  lcd.print("MED");  // Print "MEDIUM"
  delay(2000);  // delay for 2 seconds
  
  digitalWrite(lcdBacklightPin, HIGH);  // turn the backlight on high
  lcd.clear();
  lcd.setCursor(2, 0);  // Set cursor to 0, 0
  lcd.print("HIGH");   // Print "HIGH"
  delay(2000);  // delay for 2 seconds
  // Let's leave it like that, the backlight is great for readability
  // but it's bad for battery life. Turn it off if you don't need it

  // There are lots of other functions you can use on the lcd too:
  // Need to shut Mr. Roboto up? run an lcd.clear();
  lcd.clear();  // Clear the LCD screen
  delay(1000);  // wait for a second
  
  // Did you lose the cursor? Here's how you make it visible
  lcd.setCursor(0, 0);
  lcd.print("See the cursor?");
  lcd.cursor();  // turn the visible cursor on
  delay(2000);
  // Usually the cursor is a '_', but you can make it a blinky box
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Blinky!");
  lcd.blink();  // make the visible cursor a blinky box
  delay(2000);
  // Or you can go back to the _:
  lcd.noBlink();  // turn the blinky box off, back to underscore
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Underscore");
  delay(2000);
  // And if you want to turn it all off:
  lcd.noCursor();  // turn visible cursor off
  lcd.setCursor(0, 0);
  lcd.print("Cursor off!");
  delay(2000);
  
  Serial.begin(9600);  // Onto the loop(), we're going to use serial
  // So open up the serial monitor...
  
  lcd.clear();  // clear the LCD first
  lcd.setCursor(0, 0);  // and reset the cursor  
}

void loop()
{
  // In the loop we're going to have Mr. Roboto echo whatever you
  // type in the Serial Monitor.
  
  // This is a while loop, it'll continously run around this loop
  // until the statement at the beginning is proven false.
  // Here were looping until something was received in the 
  // Serial buffer.
  while (Serial.available() == 0)
  {
    ;  // do nothing
  }
  
  // once something was sent serially, we'll end up here. Now 
  // we have to do something with that serial stuff.
  
  char serialInput = Serial.read();  // read one character off the buffer
  lcd.print(serialInput);  // output it to the LCD
}
