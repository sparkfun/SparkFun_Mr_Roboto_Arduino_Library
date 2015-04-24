/* SparkFun Mr. Roboto Photocell Example Sketch
   by: Jim Lindblom, adapted from Tom Igoe's toneMelody example
   date: December 13, 2011
   
   license: This code is all released under the public 
   domain. It's provided as an educational example. Please 
   use it in any way you see fit.
   
   Mr. Roboto doesn't actually do much 'seeing' through his eyes.
   He's got a light sensor in his left ear though! Weird? Very, but
   useful!
   
   This example sketch will once again make use of the
   analogRead() command to get read Mr. Roboto's photocell ear.
   In a brightly lit room, his LEDs should become relatively dim.
   A completely dark room should make the LEDs brighter. It's
   like Mr. Roboto is your very own, automatic flashlight!
*/

/* Pin definitions */
int lightSensorPin = A0;  // the light sensor's tied to A0
int leftEye = 3;  // the left eye's on digital pin 3
int rightEye = 9;  // the right eye's connected to digital pin 9

void setup()
{
  // We've got to setup the pin directions first
  pinMode(leftEye, OUTPUT);  // the left eye LED is an output
  pinMode(rightEye, OUTPUT);  // the right eye LED is an output
  pinMode(lightSensorPin, INPUT);  // the light-sensor ear is an input
}

void loop()
{
  // In one fell swoop, we're going to create a lightValue variable
  // and assign it to the reading of the light sensor
  int lightValue = analogRead(lightSensorPin);
  
  // now analogWrite to both left and right eyes.
  // more math in here. the map function scales a value (lightValue)
  // to numbers you can use. Since analogWrite() can only go from 0
  // to 255, we map lightValue from the 0-1023 range
  // to the 0-255 range
  analogWrite(leftEye, 255 - map(lightValue, 0, 1023, 0, 255));
  analogWrite(rightEye, 255 - map(lightValue, 0, 1023, 0, 255));

  // As the sensor sees complete darkness, the LEDs will turn 
  // fully on. If the sensor gets maxed out, and the photocell
  // sees lots of light, the LEDs will turn off.
}
