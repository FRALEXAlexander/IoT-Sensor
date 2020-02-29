#include <Arduino.h>
#include "MyWIFI.h"
#include "BME280.h"
#include "GY1145.h"
#include "MQTT.h"
#include "CONFIG.h"
#include "MOTIONSENSOR.h"
#include "OTA.h"

long lastMsg = 0;
char msg[50];
int value = 0;

void setup()
{
  BME280SETUP();
  GY1145SETUP();
  MOTIONSENSORSETUP();

  Serial.begin(115200);

  WIFISETUP();
  OTASETUP();
  MQTTSETUP();
}

void loop()
{

  long now = millis();
  if (now - lastMsg > 2000)
  {
    lastMsg = now;
    BME280LOOP();
    GY1145LOOP();
  }

  MOTIONSENSORLOOP();
  MQTTLOOP();
  OTALOOP();
}