/* Mr. Roboto Demo Code
  by: Jim Lindblom
  SparkFun Electronics
  date: December 13, 2011
  
  license: This code is all released under the public 
  domain. It's provided as an educational example. Please 
  use it in any way you see fit.
  
  This code takes a little bit from all previous Mr. Roboto 
  example sketches, and jumbles them together. Now Mr. Roboto
  will tell you what temperature and light reading's he's
  reading. He'll also do some crazy stuff with his eyes.
  
  As in the LCD example sketch, you'll need the LiquidCrystal440
  installed. It should be included with this code pack, 
  or you can download it from here:
  http://code.google.com/p/liquidcrystal440/downloads/list
  The library should be installed in the 'libraries' folder of your
  Arduino sketchbook (go to File > Preferences to see where that is).
*/

// First, include the LiquidCrystal440 library.
#include <LiquidCrystal.h>

// Digital Pin Definitions
int leftEye = 3;  // Left eye LED is pin 3
int rightEye = 9;  // right eye LED is pin 9
int nosePin = 6;  // Buzzer nose is pin 6

// Analog Pin definitions
int lightPin = A0; // photocell is attached to A0
int tempPin = A1; // the temperature sensor is attached to A1

// LCD Pin Definitions
int lcdRSPin = 13;  // Register select pin
int lcdENPin = 12;  // Enable pin
int lcdD4Pin = 11;  // Data bus line 4
int lcdD5Pin = 8;  // Data bus line 5
int lcdD6Pin = 7;  // Data bus line 6
int lcdD7Pin = 4;  // Data bus line 7
int lcdBacklightPin = 5;  // LCD Backlight control pin

// Global Variables
int counter = 0;  // We use this to keep track of what Mr. Roboto's eyes are doing
float temperature;  // This is where we store temperature
int brightness;  // This is where we store brightness

// initialize lcd
LiquidCrystal lcd(lcdRSPin, 255, lcdENPin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

void setup()
{
  // Let's set up the pin modes first:
  pinMode(leftEye, OUTPUT);  // Left eye LED is an output
  pinMode(rightEye, OUTPUT);  // Right eye LED is an output
  pinMode(nosePin, OUTPUT);  // The buzzer nose is an output
  pinMode(lcdBacklightPin, OUTPUT);  // The LCD backlight LED is an output
  pinMode(lightPin, INPUT);  // light sensor is an input
  pinMode(tempPin, INPUT);  // Temperature sensor is an input

  // Tone out the nose to make sure it's working
  tone(nosePin, 440, 100);  // This'll play an A440 for 100ms
  
  lcd.begin(8, 2);  // Start up the LCD, 8 columns, 2 rows
  // Now print a warm-up message:
  lcd.print(" Hi I'm ");  // "Hi I'm" on the top row, notice spaces are used to center it
  lcd.print("MrRoboto");  // "MrRoboto", we had to get creative with the name to fit it on one line
  analogWrite(lcdBacklightPin, 255);  // Turn the backlight fully on
  delay(2000);  // delay to provide time to read
}

void loop()
{
  // This first if statement is where we update the text on the LCD
  // It will be called once every 500ms.
  // the millis() function returns the number of miliseconds that
  // a program has been running.
  // The % (mod) operator produces the remainder of a division between
  // two numbers.
  // So the if conditional is true when millis is 500, 1000, 1500, etc.
  if ((millis()%500) == 0)  // Do this once every 500ms
  {
    // In this if statement, we'll read the temperature and
    // brightness and print them out to the LCD
    temperature = analogRead(tempPin);  // analogRead temperature
    brightness = analogRead(lightPin);  // analogRead the photocell
    // Below we'll convert to celsius:
    temperature = 100.0 * ((temperature * 5.0 / 1024.0) - 0.5);
    // Want that to be in farenheit? If not comment the below out
    temperature = (temperature * 9.0 / 5.0) + 32;
    lcd.clear();  // Clear the display
    lcd.setCursor(0, 0);  // set the cursor to top left
    lcd.print("T=");  // Print "T="  (temp = )
    lcd.print(temperature);  // print the temperature
    lcd.setCursor(0, 1);  // set the cursor to bottom left
    lcd.print("L=");  // print "L=" (light = )
    lcd.print(brightness);  // print the brightness reading
  }
  
  // This if statement gives Mr. Roboto shifty eyes
  // It should run every 50ms.
  if ((millis() % 50) == 0)  // Do this once every 50ms
  {
    counter++;  // Increase counter by one
    if (counter >= 512)  // we need counter to stay within the 0-511 range
      counter = 0;  // reset counter if it gets too large
    if (counter <= 255)  // right eye going down, left eye going up
    {
      analogWrite(leftEye, counter);  // outputs 0-255 to left eye
      analogWrite(rightEye, 255-counter);  // outputs 255-0 to right eye
    }
    else if (counter <= 511)  // Right eye up, left eye down
    {
      analogWrite(leftEye, 511-counter);  // outputs 255-0 to left eye
      analogWrite(rightEye, counter-256);  // outputs 0-255 to right eye
    }
  }
}
