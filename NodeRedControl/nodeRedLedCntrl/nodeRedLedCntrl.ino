#include <DHT.h>

#include <PubSubClient.h>

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


#define LED_PIN 12
#define POT_PIN 34
#define DHT_PIN 14
#define DHTTYPE DHT11
unsigned long lastPub = 0;
int pubTime = 3000;

void callback(char *topic, byte *payload, unsigned int len){
  Serial.print("Mqtt message was received [");
  Serial.print(topic);
  Serial.println("]");
  Serial.println(payload[0]);
  if(payload[0] == 50){  //ascii code of the char "2" assigned to ON button
    digitalWrite(LED_PIN, HIGH);
  }else if(payload[0] == 49){ //ascii code of the char "1" assigned to OFF button
    digitalWrite(LED_PIN, LOW);
  }
}

const char *ssid = "CYBERSPACE 2.4GHZ";  //since it is a charachter of many chars (and not a string) we need a pointer
const char *pass = "40174066";
const char *mqtt_server = "broker.hivemq.com";
WiFiClient Esp32Client;                 // creates a client that will connect Esp32 as a wifi client
PubSubClient client(mqtt_server, 1883, callback, Esp32Client);  // My Esp32 is now an mqtt Client . With the Broker name the port etch
DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  delay(10);
  Serial.println("Connecting to ....." + String(ssid));
  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.println("Wifi Connected");

  //connect the mqtt server
  int Status = client.connect("73d9cc01248c4e6099848f7bc6b0afa2.s1.eu.hivemq.cloud"); //0 for client not connected to server else 1
  if (Status == 1){
    Serial.println("Mqtt is Connected");
    client.subscribe("msg.led_cntrl");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if(!client.connected()){
    int Status = client.connect("73d9cc01248c4e6099848f7bc6b0afa2.s1.eu.hivemq.cloud"); //0 for client not connected to server else 1
    if (Status == 1){
    Serial.println("Mqtt is Connected");
    client.subscribe("msg.led_cntrl");
    }
  }
  client.loop();
  unsigned long now = millis();
  dht.begin();
  //publish every 3 seconds
  if (now - lastPub >= pubTime){
    lastPub = now;
    bool ledStatus = digitalRead(LED_PIN);
    int pot = analogRead(POT_PIN);
    float h = dht.readHumidity();
    delay(10);
    float t = dht.readTemperature();
    t=t * (9/5) + 32;
    if(isnan(t)){
    Serial.println("Failed to read DHT Temperature ");
    }
    if(isnan(h)){
    Serial.println("Failed to read DHT Humidity ");
    }

    client.publish("tempValue", String(t).c_str());
    client.publish("humValue", String(h).c_str());
    client.publish("potValue", String(pot).c_str()); // convert the int into a C++ string and then to C string so it can cooperate with the publish method
    client.publish("ledValue", String(ledStatus).c_str());
  }
}
