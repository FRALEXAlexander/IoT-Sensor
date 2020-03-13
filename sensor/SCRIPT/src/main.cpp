#include <Arduino.h>
#include "CONFIG.h"
#include "MyWIFI.h"
#include "BME280.h"
#include "GY1145.h"
#include "MQTT.h"
#include "MOTIONSENSOR.h"
#include "OTA.h"
#include "REST.h"
#include "DASHBOARD.h"
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
  ADDRESTROUTES();
  ADDDASHBOARDROUTES();
  MQTTSETUP();
  dserver.begin();
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
   server.handleClient();
   
}