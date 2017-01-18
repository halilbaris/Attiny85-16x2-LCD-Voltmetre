/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 2 and 74HC164 pin1,2(A,B)
 * LCD Enable pin to digital pin 4
 * LCD D0 pin to 74HC164 pin 3  (QA)
 * LCD D1 pin to 74HC164 pin 4  (QB)
 * LCD D2 pin to 74HC164 pin 5  (QC)
 * LCD D3 pin to 74HC164 pin 6  (QD)
 * LCD D4 pin to 74HC164 pin 10 (QE)
 * LCD D5 pin to 74HC164 pin 11 (QF)
 * LCD D6 pin to 74HC164 pin 12 (QG)
 * LCD D7 pin to 74HC164 pin 13 (QH)
 * LCD R/W pin to GND
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 74HC164 pin 9 (CLR) to +5V
 * 74HC164 pin 8 (CK) to digital pin 3
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 25 July 2009
 by David A. Mellis
  
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 
 library and example modified 28 May 2012
 by @maris_HY (http://100year.cocolog-nifty.com/blog/)
 */

// include the library code:
#include <LcdCore.h>
#include <Lcd74HC164.h>

// initialize the library with the numbers of the interface pins
Lcd74HC164 lcd(0, 1, 2);
//declare variables
  int analogInput =3;
  float vout = 0.0;
  float vin = 0.0;
  float R1 = 10000.0;    // !! resistance of R1 !!
  float R2 = 1000.0;     // !! resistance of R2 !!
int value = 0;
void setup() {
  // set up the LCD's number of rows and columns: 
  pinMode(analogInput, INPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Vin=");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
   // read the value on analog input
  value = analogRead(analogInput);

  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2/(R1+R2));  

  // print result to lcd display
  lcd.setCursor(4, 0);
  lcd.print(vin);
  lcd.print("V");

  // sleep...
  delay(500);
}

