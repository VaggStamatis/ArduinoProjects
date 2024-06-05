#include <LiquidCrystal.h>

// C++ code
/*    Creator : Evangelos Stamatis
*  LCD display 
*  Reading Commands from Serial. 
*  Depicting the command on LCD display
*  Executing the command to turn ON or OFF an LED
*     Created on : 05/06/2024
*/
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);
void setup()
{
	  LCD.begin(16, 2); 
  	Serial.begin(9600);
  	pinMode(7, OUTPUT);
}

void lightLed(){
  digitalWrite(7, HIGH);
  return;
}

void unlightLed(){
  digitalWrite(7, LOW);
  return;
}
void loop()
{
  /*
	LCD.setCursor(5,0);
  LCD.print("HI");
  LCD.setCursor(0,1);
  for(int i=0; i<=500; i++){
    LCD.setCursor(0,1);
 	  LCD.print(i);
    delay(50);
  }
  */
  if(Serial.available())
  {
    String myInput = String(10);
    myInput = Serial.readString();
    if(myInput.equals("LEDON\n")){
      lightLed();
    }else if(myInput.equals("LEDOFF\n")){
      unlightLed();
    }
    for(int a=0; a<=myInput.length(); a++){
      LCD.write(myInput[a]);
   	}
    delay(2000);
    LCD.print(" ");
  }
  LCD.clear();
}