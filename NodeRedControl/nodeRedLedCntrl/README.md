# **ESP32** and **NODE RED** (Wifi Control Project)
In this project we use an ESP32 DevKITC V4 and the Node-Red application 
to create an device that will control any sensor we connect to the ESP32. 
Also by using the Node-Red we make a custom User Intraface to control the
sensors on the ESP32. The User interface is built on Node-Red and the Server
hosting it runs on Hivemq.com.

The System uses a Client Server/Broker configuration where the Clients/sensors 
are publishing data to the Server/Broker. These data can be later displayed on 
another Client/Device eg A computer, Selfphone etch. 

## System Functionalities
The current working configuration of the system has connected : 
    - One LED (to control when to light or not) 
    - A potentiometer (To read analog data)
    - A dht11 sensor to monitor Temperature and Humidity

## Microcontroller used
| ESP32 DEVKITC U4 |
| ---------------- |

You can probably use any microcontroller that has the ability to connect 
to a Wifi such as a NodeMCU etch.

## Project Execution
To execute this project yourself you need to follow the steps below:
- Write the code on your microcontroller and change the PIN that the sensors are connected eg:
```sh 
    define LED_PIN 12
    define POT_PIN 34
    define DHT_PIN 14
```
- Also you need to change the _ssid_ and _password_ of the WiFi you want your 
microcontroller to connect to. Also modify the _server name_ if you are hosting 
your server somewhere else. 

```sh 
  const char *ssid = "xxxxxxxxx";  
    const char *pass = "xxxxxxxxxx";
    const char *mqtt_server = "broker.hivemq.com";
```
- Lastly change any other parameter that applies to your configuration

### Node-Red User Interface
If your device was created sucessfully on Blynk and it was connected 
to your microcontroller you can probably see the output of the image below 
and interact with the button to switch on and off your LED
<img src="https://github.com/VaggStamatis/ArduinoProjects/blob/master/NodeRedControl/nodeRedLedCntrl/UserInterface_NodeRed.png" width="800">

# Creator 
*Evagelos Stamatis* email: [evanstamatis@gmail.com]