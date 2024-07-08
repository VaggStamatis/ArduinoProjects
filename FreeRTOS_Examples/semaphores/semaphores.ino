#include <Arduino_FreeRTOS.h>
#include "semphr.h"
#define rtDelay(v) {vTaskDelay(v/15);}

SemaphoreHandle_t Binary_Semaphore;
void setup() {
  // put your setup code here, to run once:
  xTaskCreate(
    taskSerial1,
    "Serial1",
    128,
    NULL,
    2,
    NULL
  );
  xTaskCreate(
    taskSerial2,
    "Serial2",
    128,
    NULL,
    0,
    NULL
  );

  Serial.begin(9600);
  Binary_Semaphore = xSemaphoreCreateBinary();  //this creates the lock  // can create a murtex like xSemaphoreCreateMutex();
  xSemaphoreGive(Binary_Semaphore);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void taskSerial1(void*){
  while(1){
    xSemaphoreTake(Binary_Semaphore, portMAX_DELAY); //trying to take the semaphore in order to print
    Serial.println("Task Serial ONE");
    xSemaphoreGive(Binary_Semaphore);
    rtDelay(30);
  }
}

void taskSerial2(void*){
  while(1){
    xSemaphoreTake(Binary_Semaphore, portMAX_DELAY); //trying to take the semaphore in order to print
    Serial.println("Task Serial Twoo");
    xSemaphoreGive(Binary_Semaphore);
    rtDelay(30);
  }
}
