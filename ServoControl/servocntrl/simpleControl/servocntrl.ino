/*
  Created by Evangleos Stamatis
    gmail : evanstamatis@gmail.com
  Date : 05/29/2024
*/
#include <Servo.h>

// servo is used in order to control angles. 0 to 180 degrees
Servo cntrlServo; // obj named cntrlServo
//int position = 0; // determines the angle

void setup() {
  // put your setup code here, to run once:
  cntrlServo.attach(3); // configuring cntrlServo and attaching it to pin #3 
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  cntrlServo.write(50); //rotate my motor to angle of 50 degrees
  delay(2000);
  cntrlServo.write(180);
  delay(2000);
  cntrlServo.write(10);
  delay(2000);
  */
  int position = 0;
  for (position; position<=180;  position++){
    cntrlServo.write(position);
    delay(50);
  }
  for (position; position>=0;  position--){
    cntrlServo.write(position);
    delay(50);
  }
}
