#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <PubSubClient.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#include <ESPmDNS.h>
#include <NeoPixelBus.h>
#include <WiFi.h>

String rootTopic = "FRALEX/IoTSensor/";
char* bme280TemperatureTopic = "FRALEX/IoTSensor/BME280/temperature";
char* bme280PressureTopic = "FRALEX/IoTSensor/BME280/pressure";
char* bme280HumidityTopic = "FRALEX/IoTSensor/BME280/humidity";
char* gy1145UVTopic = "FRALEX/IoTSensor/GY1145/UV";
char* gy1145IRTopic = "FRALEX/IoTSensor/GY1145/IR";
char* gy1145VISTopic = "FRALEX/IoTSensor/GY1145/VIS";
char* motionsensorTopic = "FRALEX/IoTSensor/MOTIONSENSOR";
char *OTAUser = "admin";
char *OTAPassword = "admin";
char *ssid = "htl-IoT";
char *password = "iot..2015";
char *MDNSHostname = "fralexsensor";
char *mqtt_server = "iotmqtt.htl-klu.at";
char *mqttUserName = "htl-IoT";
char *mqttPassword = "iot..2015";
char *mqttClientID = "DEMOfralex2";

void read_taster(void);
int item;
const uint16_t PixelCount = 5; //enter number of pixel
const uint8_t PixelPin = 18;  // make sure to set this to the correct pin, ignored for Esp8266

//Var. für Taster
boolean s1, s2, s3, s4, s5, s1_old, s2_old, s3_old, s4_old, s5_old;

long millis_old;

int s2_press_count, s4_press_count; //Wieviel Lesezyklen hintereinander

// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void WIFISETUP()
{

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  /*use mdns for host name resolution*/
  if (!MDNS.begin(MDNSHostname))
  {
    Serial.println("Error setting up MDNS responder!");
    while (1)
    {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MDNS: ");
  Serial.print(MDNSHostname);
  Serial.println(".local");
}

void setup() {
  pinMode(34, INPUT);
  pinMode(35, INPUT);

  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  WIFISETUP();
  MQTTSETUP();
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello, world!");
  display.display();
  strip.Begin();
  strip.Show();
}

void loop() {
  MQTTLOOP();
  if (millis() > millis_old + 100) {

    millis_old = millis();
    read_taster();

    if (s2 > s2_old) {
      item++;  //inkrement
      display.clearDisplay();
    }
    if (s4 > s4_old) {
      item--;   //dekrement
      display.clearDisplay();
    }
  }


  if (item <= -1) {
    item = 2;
  }
  if (item >= 3) {
    item = 0;
  }

  //Serial.println(item);

  for (int i = 0; i < PixelCount; i++)
  {
    strip.SetPixelColor(i, RgbColor (random(10), random(10), random(10)));
  }
  strip.Show();
  //delay(1000);

  switch (item) {
    case 0:
      //Serial.println("BME280");
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 10);
      // Display static text

      display.println("BME280");
      display.display();
      break;
    case 1:
      // Serial.println("GY4511");
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 10);
      // Display static text

      display.println("GY1145");
      display.display();
      break;
    case 2:
      //Serial.println("MOTION");
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 10);
      // Display static text

      display.println("MOTION");
      display.display();
      break;
  }

}

void read_taster(void) {

  //Alten werte speichern
  s1_old = s1;
  s2_old = s2;
  s3_old = s3;
  s4_old = s4;
  s5_old = s5;



  //Wartezeit(wird nicht unbedingt benötigt)
  delay(1);

  //Taster einlesen

  s4 = !digitalRead(34);
  s2 = !digitalRead(35);



}


WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String out;
  for (int i = 0; i < length; i++)
  {
    out.concat((char)payload[i]);
    //Serial.print((char)payload[i]);

  }
  Serial.println(out);

  switch (item) {
    case 0:
      if (String(topic).indexOf("BME280") > 0) {


        //Serial.println("BME280");
        display.clearDisplay();
        display.setCursor(0, 10);
        display.println("BME280");
        display.println(out);
        display.display();
      }
      break;
    case 1:
      if (String(topic).indexOf("GY1145") > 0) {
        display.clearDisplay();
        display.setCursor(0, 10);
        display.println("GY1145");
        display.println(out);
        display.display();
      }
      // Serial.println("GY4511");

      break;
    case 2:
      if (String(topic).indexOf("MOTION") > 0) {
        display.clearDisplay();
        display.setCursor(0, 10);
        display.println("MOTION");
        display.println(out);
        display.display();
      }
      //Serial.println("MOTION");

      break;
  }

}
void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID

    // Attempt to connect
    if (client.connect(mqttClientID, mqttUserName, mqttPassword))
    {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.subscribe(bme280TemperatureTopic);
      client.subscribe(bme280PressureTopic);
      client.subscribe(bme280HumidityTopic);
      client.subscribe(gy1145UVTopic);
      client.subscribe(gy1145IRTopic);
      client.subscribe(gy1145VISTopic);
      client.subscribe(motionsensorTopic);

    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void MQTTSETUP()
{
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void MQTTLOOP() {
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}
