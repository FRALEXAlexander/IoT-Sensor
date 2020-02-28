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

Adafruit_BME280 bme;

// Update these with values suitable for your network.

const char *ssid = "htl-IoT";
const char *password = "iot..2015";
const char *mqtt_server = "iotmqtt.htl-klu.at";
const char *mqttUserName = "htl-IoT";
const char *mqttPassword = "iot..2015";

const char *mqttClientID = "DEMO";

String rootTopic = "IoTSensor/";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

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

     // String topic = rootTopic;
      //topic.concat("outTopic");
      //unsigned int len = topic.length();
      //len++;
      //char topicC[len];
      //topic.toCharArray(topicC, len);
      //Serial.println(topicC);
      //client.publish(topicC, "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
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
  Serial.println(TtopicC);
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
  Serial.println(PtopicC);
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
  Serial.println(HtopicC);
  char Hbuf[100];
  sprintf(Hbuf, "%f", bme.readHumidity());
  //Serial.println(buf);
  //Serial.println(bme.readTemperature());
  client.publish(HtopicC, Hbuf);
}

void setup()
{
  pinMode(2, OUTPUT); // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  bme.begin(0x76);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
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
  }
}