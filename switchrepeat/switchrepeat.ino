char msg;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
 if(Serial.available() > 0) 
 {
   msg = Serial.read();
   Serial.println(msg);
   delay(2000);
  }
}
