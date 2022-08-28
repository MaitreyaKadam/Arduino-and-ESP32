#include <ESP32Servo.h>
Servo servo;
int obstaclePin=4;
int hasObstacle=LOW;
int red=16;
int green=19;




void setup()
{
  Serial.begin(115200);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(obstaclePin,INPUT);
  servo.attach(17);


}

void loop() 
{
  hasObstacle=digitalRead(obstaclePin);
//  Serial.println(hasObstacle);
  if (hasObstacle==LOW)
    {
      Serial.println("Opening the Dustbin");
        digitalWrite(red,LOW);
        digitalWrite(green,HIGH);
        servo.write(90);
        delay(5000);
//        servo.write(0);
        
        
    }
   else
   {
      Serial.println("Closing the Dustbin");
      digitalWrite(green,LOW);
      servo.write(0);
      digitalWrite(red,HIGH);

      
   }
   delay(100);
  

}
