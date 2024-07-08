#include <Arduino_FreeRTOS.h>
#include <queue.h>

#define rtDelayy(v) {vTaskDelay(v/15);}
QueueHandle_t xQueue;

typedef struct sensorInit
{
  char* sensorName;
  char* sensorType;
  int sensorData;
  float sensorScaleUnit;
};


void setup() {
  Serial.begin(9600);
  xQueue = xQueueCreate(10, sizeof(sensorInit));
  xTaskCreate(txTask, "Sendner", 120, NULL, 1, NULL);
}


void loop() {
  // put your main code here, to run repeatedly:

}

void txTask(void*){
  while(1){
    sensorInit Ultrasonic;
    Ultrasonic.sensorName = "Ultrasonic";
    Ultrasonic.sensorType = "Analog";
    Ultrasonic.sensorData = 32;
    Ultrasonic.sensorScaleUnit = 4.2;

    xQueueSend(xQueue, &Ultrasonic, portMAX_DELAY);
    int msgWaitingCount = uxQueueMessagesWaiting(xQueue);
    int availableQueueSize = uxQueueSpacesAvailable(xQueue);
    Serial.print("Messages waiting: ");
    Serial.print(msgWaitingCount);
    Serial.println(" ");
    Serial.print("Available Space: ");
    Serial.println(" ");
    Serial.print("Data sent= ");
    Serial.print(Ultrasonic.sensorName);
    Serial.print(" ");
    Serial.print(Ultrasonic.sensorType);
    Serial.print(" ");
    Serial.print(Ultrasonic.sensorData);
    Serial.print(" ");
    Serial.print(Ultrasonic.sensorScaleUnit);
    Serial.println(" ");
  }
}