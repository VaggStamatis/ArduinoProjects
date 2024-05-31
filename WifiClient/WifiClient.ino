#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>



const char* ssid = "CYBERSPACE 2.4GHZ";
const char* password = "40174066";

const uint16_t port = 8090;
const char * host = "192.168.1.13";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid , password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("...");
  }
  Serial.print("Wifi is connected with IP: ");
  Serial.print(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;
  if(!client.connect(host,port)){
    Serial.println("Connecion to host failed");
    delay(1000);
    return;
  }
  Serial.print("Connected to Server Successful !");
  client.print("Sup from my ESP32 !");
  Serial.println("Disconnecting ...");
  client.stop();
  delay(1000);

}
