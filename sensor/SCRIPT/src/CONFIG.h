#include "Arduino.h"
#include <WebServer.h>
#include <ESPAsyncWebServer.h>
extern String rootTopic;
extern String bme280TemperatureTopic;
extern String bme280PressureTopic;
extern String bme280HumidityTopic;
extern String gy1145UVTopic;
extern String gy1145IRTopic;
extern String gy1145VISTopic;
extern String motionsensorTopic;
extern char *OTAUser;
extern char *OTAPassword;
extern char *ssid;
extern char *password;
extern char *MDNSHostname;
extern char *mqtt_server;
extern char *mqttUserName;
extern char *mqttPassword;
extern char *mqttClientID;
extern int motionsensorPin;
extern WebServer server;
extern AsyncWebServer dserver;