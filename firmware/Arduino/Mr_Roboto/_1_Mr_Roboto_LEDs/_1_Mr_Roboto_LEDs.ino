/* SparkFun Mr. Roboto LED Example Sketch
   by: Jim Lindblom
   date: December 13, 2011
   
   license: This code is all released under the public 
   domain. It's provided as an educational example. Please 
   use it in any way you see fit.
 
   Mr. Roboto winks a lot...it can be a little creepy. He can also
   temporarily blind you if you're caught in his intense stare.
   Don't look into his eyes!
 
   This example code explains how to control Mr. Roboto's eyes.
   Using both digitalWrite() and analogWrite(). You can turn his
   eyes fully on, fully off, or anywhere in between.
*/
// Text in grey like this, or the stuff above, is called a comment.
// Arduino ignores all of your comments when it programs Mr.
// Roboto. But comments are incredibly helpful when you, or others,
// are reading through code.
// You can comment a single line with the //, or a block of lines
// using /* followed by */. Because this code is educational,
// I've really overdone it on the comments...but you can never
// have too many comments.

// Pin Definitions
// These are variables. A way to store a specific value into 
// a more easy-to-recognize name.
const int leftEyePin = 3;  // Mr. Roboto's Right LED eye is pin 3
const int rightEyePin = 9;  // Mr. Roboto's Left LED eye is pin 9

/* setup() will run once, at the very start of the program.
   At the end of setup() we'll go straight into the start of loop().*/
void setup()
{
  // Before we can use a pin, we have to tell Mr. Roboto whether
  // it's an input or output. Since we're outputting to the LEDs
  // we need to set those pins as outputs. Use the pinMode()
  // function for that.
  pinMode(leftEyePin, OUTPUT);
  pinMode(rightEyePin, OUTPUT);
  
  // At the start of the program we want both LEDs OFF.
  // To turn LEDs on and off, you can use the digitalWrite() function
  // setting the pins LOW turns the LED off. The other option
  // for digitalWrite() is HIGH. That will turn the LED on.
  digitalWrite(leftEyePin, LOW);
  digitalWrite(rightEyePin, LOW);
}

/* Once setup() is over, we'll jump into the loop() function.
   True to its namesake, loop loops. Once it gets to the }, it'll
   jump back to the line under {. */
void loop()
{
  // Loop looks really simple, but it's doing more than meets the
  // (LED) eye. Two functions are being called, which are all
  // defined towards the bottom.
  
  // blinkRightEye() and blinkLeftEye are called first.
  // Look just below the loop to see how these functions are defined.
  blinkRightEye(500);  // blink the Right eye for 500ms
  blinkLeftEye(500);  // blink the Left eye for 500ms
  
  // Then we'll blink both eyes using analogBlinkRight and LeftEye()
  analogBlinkRightEye(1000);  // analog blink right eye for 1000ms (1s)
  analogBlinkLeftEye(1000);  // analog blink left eye for 1000ms (1s)
  
  // at the end of loop we'll go back to the top and do it all
  // over again. FOR-EV-ER. Or until Mr. Roboto runs out of
  // batteries.
}

/* blinkRightEye(int blinkTime) - This function will turn Mr. Robot's
   right LED eye on for blinkTime/2, and off for blinkTime/2.
   In total, the function will take blinkTime miliseconds to complete.   
*/
void blinkRightEye(int blinkTime)
{
  digitalWrite(rightEyePin, HIGH);  // Turn the right LED ON
  delay(blinkTime/2);  // Do NOTHING for blinkTime/2 miliseconds
  digitalWrite(rightEyePin, LOW);  // Now turn the right LED OFF
  delay(blinkTime/2);  // Again do NOTHING for blinkTime/2 miliseconds
}

/* blinkLefttEye(int blinkTime) - This function will turn Mr. Robot's
   left LED eye on for blinkTime/2, and off for blinkTime/2.
   In total, the function will take blinkTime miliseconds to complete.   
*/
void blinkLeftEye(int blinkTime)
{
  digitalWrite(leftEyePin, HIGH);  // Turn the left LED ON
  delay(blinkTime/2);  // do NOTHING for blinkTime/2 miliseconds
  digitalWrite(leftEyePin, LOW);  // Turn the left LED OFF
  delay(blinkTime/2);  // do NOTHING for blinkTime/2 miliseconds
}

/* analogBlinkLeftEye(int blinkTime) - This function uses
   analogWrite() instead of digitalWrite() to turn the left LED
   eye on and off in little steps */
void analogBlinkLeftEye(int blinkTime)
{
  // we're going to divide each delay
  // into tiny fractions of blinkTime.
  // We'll use this variable later on in the function.
  long blinkIntervalMicroseconds = ((long)blinkTime*1000/512);
  
  // a for loop will run until the statement in the middle
  // (i <= 255) is untrue. Every time through it'll perform
  // the action in the third statement - i++ - which increases
  // the i variable plus one.
  for (int i=0; i<=255; i++)
  {
    // analogWrite() is like digitalWrite, except instead of just
    // using HIGH and LOW, we can give it a number between 0 (LOW)
    // and 255 (HIGH).
    analogWrite(leftEyePin, i);  // analogWrite the left LED
    delayMicroseconds(blinkIntervalMicroseconds);  // delay for some microseconds
  }
  // This for loop is like the previous one, but it's going backwards.
  // i starts at 255, and decreases by 1 every time, until it starts
  // to go negative.
  for (int i=255; i>=0; i--)
  {
    analogWrite(leftEyePin, i);// analogWrite the left LED
    delayMicroseconds(blinkIntervalMicroseconds);  // delay for some microseconds
  }
}

/* analogBlinkRightEye(int blinkTime) - This function uses
   analogWrite() instead of digitalWrite() to turn the right LED
   eye on and off in little steps */
void analogBlinkRightEye(int blinkTime)
{
  // we're going to divide each delay
  // into tiny fractions of blinkTime.
  // We'll use this variable later on in the function.
  long blinkIntervalMicroseconds = ((long)blinkTime*1000/512);

  // a for loop will run until the statement in the middle
  // (i <= 255) is untrue. Every time through it'll perform
  // the action in the third statement - i++ - which increases
  // the i variable plus one.
  for (int i=0; i<=255; i++)
  {
    analogWrite(rightEyePin, i);  // analogWrite the right LED
    delayMicroseconds(blinkIntervalMicroseconds);  // delay for some microseconds
  }
  // This for loop is like the previous one, but it's going backwards.
  // i starts at 255, and decreases by 1 every time, until it starts
  // to go negative.
  for (int i=255; i>=0; i--)
  {
    analogWrite(rightEyePin, i);  // analogWrite the left LED
    delayMicroseconds(blinkIntervalMicroseconds);  // delay for some microseconds
  }
}

