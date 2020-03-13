#include "CONFIG.h"
#include "ESPAsyncWebServer.h"
String rootTopic = "FRALEX/IoTSensor/";
String bme280TemperatureTopic = "BME280/temperature";
String bme280PressureTopic = "BME280/pressure";
String bme280HumidityTopic = "BME280/humidity";
String gy1145UVTopic = "GY1145/UV";
String gy1145IRTopic = "GY1145/IR";
String gy1145VISTopic = "GY1145/VIS";
String motionsensorTopic = "MOTIONSENSOR";
char *OTAUser = "admin";
char *OTAPassword = "admin";
char *ssid = "htl-IoT";
char *password = "iot..2015";
char *MDNSHostname = "fralexsensor";
char *mqtt_server = "iotmqtt.htl-klu.at";
char *mqttUserName = "htl-IoT";
char *mqttPassword = "iot..2015";
char *mqttClientID = "DEMOfralex";
int motionsensorPin = 32;
WebServer server(2000);
AsyncWebServer dserver(80);
