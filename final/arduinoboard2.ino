#include <Servo.h>
Servo myservo;

int pos = 0;
char ss;
void setup()
{
  myservo.attach(9);
Serial.begin(115200);
pinMode(13,OUTPUT);
}


void loop()
{
ss=Serial.read();
Serial.println(ss);
if(ss== 1)
{
  for (pos = 90; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(10000);
  for (pos = 180; pos >= 90; pos -= 2) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    delay(10000);
digitalWrite(13, HIGH);
ss=0;
delay(300);
digitalWrite(13, LOW);
delay(300);
}
//Serial.print('b');//收到‘a\'後向主機發一個’b\'
}
