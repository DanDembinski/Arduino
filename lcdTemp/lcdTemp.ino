#include <dht.h>
#include <LiquidCrystal.h>
dht DHT;

#define DHT11_PIN 2

LiquidCrystal lcd(7,8,9,10,11,12);
int temp;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  int chk=DHT.read11(DHT11_PIN);
  lcd.print("Temp: ");
  temp = DHT.temperature;
  temp= temp*9/5+32;
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(DHT.humidity,1);
  
  delay(2000);
  lcd.setCursor(0,0);
}
