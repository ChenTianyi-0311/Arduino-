#include <Servo.h>
Servo myservo;
void setup()
{
  myservo.attach(9);
  myservo.write(90);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  Serial.print("Welcome to Chen Tianyi Arduino!\n\rPrint 'a' to turn on the led\n\rPrint 'b' to turn off the led\n\rPrint 'c' to turn on the red led\n\rPrint 'd' to turn off the red led\n\rPrint 'e' to turn the servo 45 degrees to the right\n\rPrint 'g' to turn the servo to the center\n\rPrint 'h' to turn the servo 45 degrees to the left\n");
}
void loop()
{
  char c;
  if(Serial.available() > 0)
  {
    c = Serial.read();
    if(c == 'a')
    {
      Serial.print("\rTurn on !\n\n");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(c == 'b')
    {
      Serial.print("\rTurn off !\n\n");
      digitalWrite(LED_BUILTIN, LOW);  
    }
    else if(c == 'c')
    {
      digitalWrite(10, HIGH);
    }
    else if(c == 'd')
    {
      digitalWrite(10, LOW);
    }
    else if(c == 'e')
    {
          myservo.write(45);
    }
    else if(c == 'g')
    {
          myservo.write(90);
    }
    else if(c == 'h')
    {
          myservo.write(135);
    }
    else
    {
      Serial.print("\rWrong\n\n");
    }
  }
}
