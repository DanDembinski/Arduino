#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
RTC_DS1307 rtc;
//set led pins
int redPin = 3;
int greenPin = 5;
int bluePin = 6;
//set initial led colors
int B = 0;
int R = 0;

#define COMMON_ANODE
int G = 0;

void setup()
{
  lcd.begin(16, 2);
  
  Serial.begin(57600);
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();
  //uncomment below to reset RTC
  //rtc.adjust(DateTime(__DATE__, __TIME__));
  if (! rtc.isrunning()) 
  {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
  
   pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

void loop()
{
  DateTime now = rtc.now();

  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
 // lcd.print(':');
  //lcd.print(now.second(), DEC);
  lcd.print(' ' );
  
  lcd.setCursor(0,1);  
  
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);
  lcd.print(' ');
  


  
  while (B<255)
    {
      B++;
      setColor(R,G,B);
      delay(10);
    }
  B=0;
  while (G<255)
   {
      G++;
      setColor(R,G,B);
      delay(10);
    }
  G=0;
    while (R<255)
    {
      R++;
      setColor(R,G,B);
      delay(10);
    }
  while (B<255)
    {
      B++;
      setColor(R,G,B);
      delay(10);
    }
  while (G<255)
    {
      G++;
      setColor(R,G,B);
      delay(10);
    }
    while (R>0)
    {
      R--;
      setColor(R,G,B);
      delay(10);
    }
    while (B>0)
    {
      B--;
      setColor(R,G,B);
      delay(10);
    }
    while(R<255)
    {
      R++;
      setColor(R,G,B);
      delay(10);
    }
    R=0;
    B=0;
    G=0;
    delay(1000);
   lcd.setCursor(0,0);
   
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
  

