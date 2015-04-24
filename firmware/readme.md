# Mr. Roboto Example Code Suite

## Installation

Unzip this entire directory into your Arduino sketchbook. Don't know where your sketchbook is? Open Arduino, go to File > Preferences. It should be listed in at the top of that dialog. Make sure you close Arduino, before installing the library.

Once unzipped your sketch folder should look like this (assuming your sketchbook were located in the My Documents folder):

	C:/.../My Documents/Arduino/Mr_Roboto - This is where the example code lives
	C:/.../My Documents/Arduino/libraries/LiquidCrystal - This installs the LiquidCrystal400 library, used for the LCD.

Or, on more recent versions of Windows (7 & 8) it might look like:

	C:/Users/yourUserNamerHere/Arduino/Mr_Roboto
	C:/Users/yourUserNamerHere/Arduinolibraries/LiquidCrystal

## The Example Code Listing

This listing is ordered by simplest code to the most advanced.

1. [Mr&#95;Roboto&#95;LEDs](https://github.com/sparkfun/SparkFun_Mr_Roboto_Arduino_Library/tree/master/firmware/Examples/Mr_Roboto_LEDs): Mr. Robotos red eyes will stare straight into your soul. He'll creepily wink to you. What's not to love!? 

	This bit of example code will explain some basics of coding (comments, functions, variables, 
	even for loops). And will focus on teaching you how to use digitalWrite() and analogWrite() functions. Which are the building blocks of most Arduino sketches.

2. [Mr&#95;Roboto&#95;Temperature](https://github.com/sparkfun/SparkFun_Mr_Roboto_Arduino_Library/tree/master/firmware/Examples/Mr_Roboto_Temperature): Does Mr. Roboto look sick to you? Better take his temperature.

	This example code will explain how to use analogRead() and the Serial library, so you can
	read Mr. Roboto's temperature sensor, and output the information to your computer. Once the code is uploaded, you'll need to open the Serial Monitor, where you'll see all of the data streaming by.

3. [Mr&#95;Roboto&#95;Buzzer](https://github.com/sparkfun/SparkFun_Mr_Roboto_Arduino_Library/tree/master/firmware/Examples/Mr_Roboto_Buzzer): Mr. Roboto sings through his nose. It sounds about as awful as you might expect a nose-whislter to sound, but don't tell him. He thinks he has a lovely voice.

	This example code shows how you can program Mr. Roboto to sing. It includes an additional file "pitches.h" which defines a ton of notes. By default Mr. Roboto will sing his theme song. See what else you can program him to sing.

4. [Mr&#95;Roboto&#95;Photocell](https://github.com/sparkfun/SparkFun_Mr_Roboto_Arduino_Library/tree/master/firmware/Examples/Mr_Roboto_Photocell): Not only is Mr. Robotos voicebox in his nose. His corneas are in his right ear. He's very color blind, but Mr. Roboto is a great sensor of light and dark.

	In this example code, you'll again use analogRead(), this time to gauge the value of Mr. Roboto's photocell (light sensor) right ear. Instead of outputing the data over serial though, we'll use the light-reading to control how bright Mr. Roboto's eyes need to be. This turns him into something of a light-sensing flashlight.

5. [Mr&#95;Roboto&#95;LCD](https://github.com/sparkfun/SparkFun_Mr_Roboto_Arduino_Library/tree/master/firmware/Examples/Mr_Roboto_LCD): Aside from whistling music through his nose Mr. Roboto is pretty mute. When he has something to say, he'll usually spit it out using his 16-character (2 row, 8 column) LCD-mouth.
   
	This example sketch will show how you can control Mr. Roboto to say all kinds of crazy things. Once Mr. Roboto has run through some demo stuff, he'll go into copycat mode. You can open up the Serial Monitor and anything you type and send will be echoed on Mr. Roboto's LCD mouth.

6. [Mr&#95;Roboto&#95;Demo](https://github.com/sparkfun/SparkFun_Mr_Roboto_Arduino_Library/tree/master/firmware/Examples/Mr_Roboto_Demo): Now to put it all together, load up this demo code. This code will do some crazy flickering of the eyes, and it'll announce Mr. Roboto's temperature and light readings on his LCD mouth.

## License

All of this code is released under the beerware license. I want you to use this code in any way you see fit, if you find it useful, buy me a beer (root or otherwise). :)

## Resources

Hope that helps get you started with Arduino. Your bound to have questions, and when you do there are a number of resources for you to check:
* Post a comment on the Mr. Roboto product page: We're happy to help, and will monitor the comments like hawks to try and get your question answered as quickly as possible.
* Post in our forums (http://forum.sparkfun.com/): With all of the technical diversity on this board, you're bound to get your question answered.
* Post in the Arduino forums (http://arduino.cc/forum/): None better at answering your Arduino-related questions than the huge Arduino community.
* Scour the Arduino.cc documentation (http://arduino.cc/en/Reference/HomePage): The Arduino Reference section is a great place to discover all things Arduino. This should answer most code questions.

---

Thanks for reading!
	
	Jim Lindblom
	SparkFun Electronics
	January 26, 2012
