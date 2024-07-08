#include <Arduino_FreeRTOS.h>
#include <queue.h>

#define rtDelay(v) {vTaskDelay(v/15);}
QueueHandle_t xQueue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xQueue = xQueueCreate(8, sizeof(char*));
  xTaskCreate(txTask, "Sender", 128, NULL, 1, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

}


void txTask(void*){
  //int data = 123;
  char* data[] = {"This", "is", "a", "String", "being", "transfered"};

  while(1){
    for(int i=0; i<6; i++){

      xQueueSend(xQueue, &data[i], portMAX_DELAY);
      int messagesWaitingCount = uxQueueMessagesWaiting(xQueue);
      int availableQueueSize = uxQueueSpacesAvailable(xQueue);

      Serial.print("Messages waiting : ");
      Serial.print(messagesWaitingCount);
      Serial.print(" ");
      Serial.print("Available Space : ");
      Serial.println(availableQueueSize);

      Serial.print("Data sent =  ");
      Serial.println(data[i]);
      rtDelay(1000);
    }
  }
}
