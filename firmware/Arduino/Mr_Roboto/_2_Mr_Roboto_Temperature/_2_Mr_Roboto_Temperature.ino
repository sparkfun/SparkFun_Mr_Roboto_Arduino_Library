/* SparkFun Mr. Roboto Temperature Sensor Example Sketch
   by: Jim Lindblom
   adapted from Tom Igoe's toneMelody example
   date: December 13, 2011
   
   license: This code is all released under the public 
   domain. It's provided as an educational example. Please 
   use it in any way you see fit.

   Is it cold in here, or is it just Mr. Roboto's chilling stare?
   Mr. Roboto knows what the temperature is, it's just a matter
   of getting the information out of him.
   
   This example code will teach you how to use Mr. Roboto's right-
   ear temperature sensor. The temperature sensor is analog,
   so we'll need to use analogRead() to get its reading.
   
   To display the temperature, we'll use the Serial Monitor. You
   can send out all sorts of information and messages over serial,
   where you can read it on your computer.
   
   After you've uploaded the sketch to Mr. Roboto, click
   "Serial Monitor" in the upper-right-hand corner of Arduino.
   All of the temperature data should stream there.
   
   Try breathing into Mr. Roboto's ear, you might just raise his
   temperature.
*/

// Pin definitions
int temperaturePin = A1;  // The temperature sensor is connected to A1
// A1 is an analog input pin.

void setup()
{
  pinMode(temperaturePin, INPUT);  // Set the temperature as an input
  
  // We've also got to tell Mr. Roboto to start up his serial
  // input and output system. The 9600 in this function tells
  // Mr. Roboto how fast we'll be sending information (9600 bits per second).
  // This speed (also known as baud rate), must match the speed
  // set on your computer.
  Serial.begin(9600);
}

void loop()
{
  // First create a variable to store the temperature readings
  // We'll creatively call it temperatureReading.
  int temperatureReading;
  
  // Now we'll use analogRead() to get the analog value of the
  // temperature pin. And we'll store that value in
  // temperatureReading;
  temperatureReading = analogRead(temperaturePin);
  
  // Let's output that data over serial now. Use Serial.println()
  // to print a value to the Serial Monitor.
  Serial.println(temperatureReading);
  
  // but that value doesn't really mean anything to you. It's just
  // some number between 0 and 1023. Which actually represents a
  // voltage between 0 and 5V. Lets convert it to Celsius.
  
  // First find the voltage - divide by 1024, and multiply by 5V
  float temperatureVoltage = (float) temperatureReading * 5 / 1024;
  
  // Next allow for the temperature sensor's offset, which is 0.5V.
  temperatureVoltage = temperatureVoltage - 0.5;
  
  // Now, the temperature should be equal to 0.1V / degree C
  float celsiusTemperature = temperatureVoltage * 100;
  
  // And let's print that out now. First some text:
  Serial.print("The celsius temperature is: ");
  // Then the temperature we calculated
  Serial.print(celsiusTemperature);
  // Then print some fancy characters, and a new line.
  Serial.print(" ");  // Print a space
  Serial.write(176);  // This is the ° symbol code number
  Serial.println("C");  // and a C
  Serial.println();   // just print another line. for finality.
  
  // For some more practice, you could try converting that celsius
  // value into farenheit. If you're like me, you have know idea
  // if 25°C is room temperature, boiling or freezing.
  
  // Let's also delay for a brief moment, so this all doesn't stream
  // by faster than we can actually see.
  delay(1000);  // delay for 1000ms (1 second)
}
