# **ESP32** and **Blynk** (Wifi Led Control Project)
In this project we use an ESP32 DevKITC V4 and the Blynk IOT application 
to create an device that will control an LED through WiFi. In that way we
will be able to switch ON and OFF the LED through either ou Smartphone or 
our Computer using the Blynk IoT or Blynk Console acordingly. 

## Microcontroller used
| ESP32 DEVKITC U4 |
| ---------------- |

You can probably use any microcontroller that has the ability to connect 
to a Wifi.

## Project Execution
To execute this project yourself you need to follow the steps below:
- Write the code on your microcontroller and change the _parameters_ below 
```sh 
    define BLYNK_TEMPLATE_ID "xxxxxxxxxxxxxx"
    define BLYNK_TEMPLATE_NAME "xxxxxxxxxxxx"
    define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxx" 
    define LED_PIN XX
```
Also you need to change the _ssid_ and _password_ of the WiFi you want your 
microcontroller to connect to.

```sh 
  const char *ssid = "xxxxxxxxx";  
    const char *pass = "xxxxxxxxxx";
```

### Blynk Output
If your device was created sucessfully on Blynk and it was connected 
to your microcontroller you can probably see the output of the image below 
and interact with the button to switch on and off your LED
![Alt text] https://github.com/VaggStamatis/ArduinoProjects/blob/master/NodeMCUcontrol/wifiConnectNode/BlynkConsoleDevice.png "Blynk Console Devices")

# Creator 
*Evagelos Stamatis* email: [evanstamatis@gmail.com]