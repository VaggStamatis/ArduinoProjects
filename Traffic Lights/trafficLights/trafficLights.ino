/*
  Created by Evangleos Stamatis
    gmail : evanstamatis@gmail.com
  Date : 05/29/2024

    Sketch implements The usage of Traffic Lights with a state machine. 
    State zero : Red Light  <----|
    State one : Green Light      |
    State two : Orange Light ----|

*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}
int var =0;
void loop() {
  // put your main code here, to run repeatedly:

  switch(var){
     case 0:
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(7 , LOW);
      var = 1;
      Serial.println("Next State is : " + String(var));
      delay(6000);
      break;
    case 1:
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(7, HIGH);
      var = 2;
      Serial.println("Next State is : " + String(var));
      delay(7000);
      break;
    case 2:
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(7, LOW);
      var = 0;
      Serial.println("Next State is : " + String(var));
      delay(2000);
      break;
    default:
      var = 0;
  }
   
}