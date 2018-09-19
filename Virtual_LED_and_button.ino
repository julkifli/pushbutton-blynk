/*******************************************
 * Virtual Led n Push button
 * By Maker's Hub Politeknik Kota Kinabalu
 *******************************************/
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "auth token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "pass";

int PULL_UP = D1;

WidgetLED led1(V1);

SimpleTimer timer;

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(PULL_UP, INPUT_PULLUP);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, readBut);
}

void loop()
{
  Blynk.run();
  timer.run();

}

void readBut()
{

  if (digitalRead(PULL_UP) == LOW) {
  led1.on();
  }
  else {
    led1.off();
  }
}
