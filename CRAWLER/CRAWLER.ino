/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <Servo.h>

const int a1 = 0;
const int a2 = 16;
const int b1 = 5;
const int b2 = 14;
const int apwm = 12;
const int bpwm = 4;

Servo yatay;
Servo dikey;

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e645f17c636e43bcbffcd4b789f6610b";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "kayanet";
char pass[] = "ahmet2002";

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(apwm,OUTPUT);
  pinMode(bpwm,OUTPUT);
  yatay.attach(13);
  dikey.attach(15);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)  
{
  int pinValue = param.asInt();
  if (pinValue == 1){
    digitalWrite(a1,1);
    digitalWrite(a2,0);
    digitalWrite(apwm,1);
    Serial.println("ileri");
  }
  else{
    digitalWrite(a1,0);
    digitalWrite(a2,1);
    digitalWrite(apwm,1);
    Serial.println("geri");
  }
}

BLYNK_WRITE(V1)  
{
  int pinValue = param.asInt();
  if (pinValue == 1){
    digitalWrite(b1,1);
    digitalWrite(b2,0);
    digitalWrite(bpwm,1);
  }
  else{
    digitalWrite(b1,0);
    digitalWrite(b2,1);
    digitalWrite(bpwm,1);
  }
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  pinValue = map(pinValue, 0, 255, 0, 180);
  yatay.write(pinValue);
}

BLYNK_WRITE(V5)
{
  int pinValue = param.asInt();
  pinValue = map(pinValue, 0, 255, 0, 180);
  dikey.write(pinValue);
}
