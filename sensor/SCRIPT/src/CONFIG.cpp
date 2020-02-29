#include "CONFIG.h"

String rootTopic = "IoTSensor/";
String bme280TemperatureTopic = "BME280/temperature";
String bme280PressureTopic = "BME280/pressure";
String bme280HumidityTopic = "BME280/humidity";
String gy1145UVTopic = "GY1145/UV";
String gy1145IRTopic = "GY1145/IR";
String gy1145VISTopic = "GY1145/VIS";
String motionsensorTopic = "MOTIONSENSOR";
char *OTAUser = "admin";
char *OTAPassword = "admin";
char *ssid = "ssid";
char *password = "pw";
char* MDNSHostname = "esp32";
char *mqtt_server = "ip";
char *mqttUserName = "user";
char *mqttPassword = "passwd";
char *mqttClientID = "DEMO";
int motionsensorPin = 32;