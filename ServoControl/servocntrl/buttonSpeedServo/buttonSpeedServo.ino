/*
  Created by Evangleos Stamatis
    gmail : evanstamatis@gmail.com
  Date : 30/05/2024


  4 speed servo motor
  By pressing each button the servo rotates with a different speed. 
  When you press another button the old speed overides and rotates with the new speed 

  Implemented using interrupts with diodes so when one button is pressed while the movement is still executing
  we interrupt the movement, overide the speed and begin where we left with the new speed

  Prints the Button pressed so we know what speed to expect
*/

#include <Servo.h>
const int sp1 =4; // speed for pin 4
const int sp2 =5; // speed for pin
const int sp3 =6; // speed for pin
const int sp4 =7; // speed for pin
Servo cntrlServo;    //initialize a Servo obj;
volatile int button = 0;     //to distinguish which button is being pressed
volatile int delayTime = 0;  //time delay for the movement aka speed
bool mode = 0;      //boolean for the servo aka on-off

const int inter = 2; // Interrupt pin is pin 2
/* Check which button is pressed and return a number
  that coresponds to each button.
*/
void getButton(){
  if (digitalRead(sp1) == 0){
    button = 1;
  }else if(digitalRead(sp2) == 0){
    button = 2;
  }else if(digitalRead(sp3) == 0){
    button = 3;
  }else if(digitalRead(sp4) == 0){
    button = 4;
  }
  delayTime = speedOption();
  Serial.println("Pressed button #" + String(button));
}

/* Changes the Mode to on and sets the speed
  of the servo's rotation
*/
int speedOption(){
  switch(button){
    case 1:
      mode = 1;
      return 90;
    case 2: 
      mode = 1;
      return 45;
    case 3: 
      mode = 1;
      return 25;
    case 4: 
      mode = 1;
      return 5;
    default:
      mode = 0;
      return 0;
  }  
}

void setup() {
  // put your setup code here, to run once:
  cntrlServo.attach(3); // output pin for servo
  pinMode(sp1, INPUT_PULLUP);
  pinMode(sp2, INPUT_PULLUP);
  pinMode(sp3, INPUT_PULLUP);
  pinMode(sp4, INPUT_PULLUP);
  pinMode(inter, INPUT_PULLUP); //interrupt pin
  attachInterrupt(digitalPinToInterrupt(inter), getButton, FALLING ); //when the interrupt pin activates and which function it calls
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mode =1){
    for(int pos=0; pos<= 180; pos++){
      cntrlServo.write(pos);
      delay(delayTime);
    }
    for(int pos=180; pos>=0; pos--){
      cntrlServo.write(pos);
      delay(delayTime);
    }
  }
}
