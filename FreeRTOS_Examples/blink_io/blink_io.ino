#include <Arduino_FreeRTOS.h>
#define rtDelay(v) {vTaskDelay(v/portTICK_PERIOD_MS);} //replacing a statmenntt with a smaller one

/*First Arduino RTOS program
  Blinkinng annd Handling IO 
  Build for Arduino UNO.
*/

const int blinkLed = 7;

void setup() {

    xTaskCreate
    (
      task_Led_Blink, 
      "Blink", 
      128, 
      NULL,
      2,
      NULL
    );
    pinMode(blinkLed, OUTPUT);

    xTaskCreate
    (
      task_Serial, 
      "Serial", 
      128, 
      NULL,
      1,
      NULL
    );

    Serial.begin(9600);
}

void loop(){
  
}

void task_Led_Blink(){
  
  digitalWrite(blinkLed,HIGH);
  rtDelay(500);
  digitalWrite(blinkLed,LOW);
  rtDelay(500);
}

void task_Serial(){
  Serial.println("Blinking is Happening as a Multi Thread");
  rtDelay(800);
}