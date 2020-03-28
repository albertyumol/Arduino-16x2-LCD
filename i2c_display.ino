/*============================ albert yumol ===================================//

Demonstration on how to use 16x2 LCD display with an arduino board

You need to install the LiquidCrystal_I2C.h library.
sda-a4
scl-a5
//============================ albert yumol ===================================*/

#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address, if it's not working try 0x27.
//#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

long randNumber1;                                                            // the variable which is supposed to hold the random number
long randNumber2;
long randNumber3;
long randNumber4;
const int analogOutPin1 = 6;                                                 // Analog output pin where the LED is attached to
const int analogOutPin2 = 7;
const int analogOutPin3 = 8;
const int analogOutPin4 = 9;


void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("MOZILLA FESTIVAL");
  lcd.setCursor(0, 1);
  lcd.print("  RANDOM NUMBER ");
  // initialize the serial port
  Serial.begin(9600);
  // initialize the pseudo-random number generator
  randomSeed(analogRead(0));
}

void loop()
{
  randNumber1 = random(0, 255);                                              // generate a random number
  randNumber2 = random(0, 255);
  randNumber3 = random(0, 255);
  randNumber4 = random(0, 255);
  Serial.print(randNumber1);                                               // send the random number to the serial port
  Serial.print(randNumber2);
  Serial.print(randNumber3);
  Serial.println(randNumber4);
  analogWrite(analogOutPin1, randNumber1);                                    // vary the brightness of the LED according to the random number
  analogWrite(analogOutPin2, randNumber2);
  analogWrite(analogOutPin3, randNumber3);
  analogWrite(analogOutPin4, randNumber4);
  delay(300);
}
