/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 3;
int greenPin = 5;
int bluePin = 6;

int B = 0;
int R = 0;
int G = 0;
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{
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
