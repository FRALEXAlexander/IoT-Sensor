#include "Arduino.h"
#include "MQTT.h"
#include "CONFIG.h"

WiFiClient espClient;
PubSubClient client(espClient);

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

void MQTTSETUP()
{
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
}

void MQTTLOOP(){
    if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}