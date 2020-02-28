#include <Arduino.h>
/*
 Basic ESP8266 MQTT example

 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.

 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic" every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off

 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.

 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"

*/

#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_SI1145.h>

Adafruit_BME280 bme;
Adafruit_SI1145 uv = Adafruit_SI1145();
// Update these with values suitable for your network.

const char *ssid = "FRALEX2.4Ghz";
const char *password = "Martin1927";
const char *mqtt_server = "10.0.0.10";
const char *mqttUserName = "fralex";
const char *mqttPassword = "Franzpichler1";

const char *mqttClientID = "DEMO";

String rootTopic = "IoTSensor/";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
bool motionChange = false;

void setup_wifi()
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

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1')
  {
    digitalWrite(2, LOW); // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  }
  else
  {
    digitalWrite(2, HIGH); // Turn the LED off by making the voltage HIGH
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
void BME280LOOP()
{
  String Ttopic = rootTopic;
  Ttopic.concat("BME280/temperature");
  unsigned int Tlen = Ttopic.length();
  Tlen++;
  char TtopicC[Tlen];
  Ttopic.toCharArray(TtopicC, Tlen);
  //Serial.println(TtopicC);
  char Tbuf[100];
  sprintf(Tbuf, "%f", bme.readTemperature());
  //Serial.println(buf);
  //Serial.println(bme.readTemperature());
  client.publish(TtopicC, Tbuf);

  String Ptopic = rootTopic;
  Ptopic.concat("BME280/pressure");
  unsigned int Plen = Ptopic.length();
  Plen++;
  char PtopicC[Plen];
  Ptopic.toCharArray(PtopicC, Plen);
  //Serial.println(PtopicC);
  char Pbuf[100];
  sprintf(Pbuf, "%f", bme.readPressure());
  //Serial.println(buf);
  //Serial.println(bme.readTemperature());
  client.publish(PtopicC, Pbuf);

  String Htopic = rootTopic;
  Htopic.concat("BME280/humidity");
  unsigned int Hlen = Htopic.length();
  Hlen++;
  char HtopicC[Hlen];
  Htopic.toCharArray(HtopicC, Hlen);
  //Serial.println(HtopicC);
  char Hbuf[100];
  sprintf(Hbuf, "%f", bme.readHumidity());
  //Serial.println(buf);
  //Serial.println(bme.readTemperature());
  client.publish(HtopicC, Hbuf);
}
void GY1145LOOP()
{

  float UVindex = uv.readUV();
  // the index is multiplied by 100 so to get the
  // integer index, divide by 100!
  UVindex /= 100.0;

  String Ttopic = rootTopic;
  Ttopic.concat("GY1145/UV");
  unsigned int Tlen = Ttopic.length();
  Tlen++;
  char TtopicC[Tlen];
  Ttopic.toCharArray(TtopicC, Tlen);
  //Serial.println(TtopicC);
  char Tbuf[100];
  sprintf(Tbuf, "%f", UVindex);
  //Serial.println(buf);
  //Serial.println(bme.readTemperature());
  client.publish(TtopicC, Tbuf);

  String Ptopic = rootTopic;
  Ptopic.concat("GY1145/VIS");
  unsigned int Plen = Ptopic.length();
  Plen++;
  char PtopicC[Plen];
  Ptopic.toCharArray(PtopicC, Plen);
  //Serial.println(PtopicC);
  char Pbuf[100];
  sprintf(Pbuf, "%d", uv.readVisible());
  //Serial.println(buf);
  //Serial.println(bme.readTemperature());
  client.publish(PtopicC, Pbuf);

  String Htopic = rootTopic;
  Htopic.concat("GY1145/IR");
  unsigned int Hlen = Htopic.length();
  Hlen++;
  char HtopicC[Hlen];
  Htopic.toCharArray(HtopicC, Hlen);
  //Serial.println(HtopicC);
  char Hbuf[100];
  sprintf(Hbuf, "%d", uv.readIR());
  //Serial.println(buf);
  //Serial.println(bme.readTemperature());
  client.publish(HtopicC, Hbuf);
}
void IRAM_ATTR MOTIONSENSOR()
{
  motionChange = true;
}

void setup()
{

  pinMode(32, INPUT);
  pinMode(2, OUTPUT); // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  bme.begin(0x76);
  uv.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  attachInterrupt(32, MOTIONSENSOR, CHANGE);
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 2000)
  {
    lastMsg = now;

    BME280LOOP();
    GY1145LOOP();
  }

  if (motionChange)
  {

    Serial.println(millis());
    String Htopic = rootTopic;
    Htopic.concat("MOTIONSENSOR");
    unsigned int Hlen = Htopic.length();
    Hlen++;
    char HtopicC[Hlen];
    Htopic.toCharArray(HtopicC, Hlen);
    Serial.println(HtopicC);
    char Hbuf[100];
    bool status = digitalRead(32);
    sprintf(Hbuf, "%d", status);
    Serial.println(Hbuf);
     Serial.println(bme.readTemperature());
    client.publish(HtopicC, Hbuf);
    motionChange = false;
  }
}