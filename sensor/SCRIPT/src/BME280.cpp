#include "Arduino.h"
#include "BME280.h"
#include "CONFIG.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "MQTT.h"

Adafruit_BME280 bme;

void BME280SETUP()
{
    bme.begin(0x76);
}

float* BME280MEASURE(){
    float* out = new float[4];
    out[0] = bme.readTemperature();
    out[1] = bme.readPressure();
    out[2] = bme.readHumidity();
    out[3] = bme.readAltitude(1030.25);
    return  out;
}


void BME280LOOP()
{

    String Ttopic = rootTopic;
    Ttopic.concat(bme280TemperatureTopic);
    unsigned int Tlen = Ttopic.length();
    Tlen++;
    char TtopicC[Tlen];
    Ttopic.toCharArray(TtopicC, Tlen);
    
    char Tbuf[100];
    sprintf(Tbuf, "%f", bme.readTemperature());
    
    client.publish(TtopicC, Tbuf);

    String Ptopic = rootTopic;
    Ptopic.concat(bme280PressureTopic);
    unsigned int Plen = Ptopic.length();
    Plen++;
    char PtopicC[Plen];
    Ptopic.toCharArray(PtopicC, Plen);
    
    char Pbuf[100];
    sprintf(Pbuf, "%f", bme.readPressure());
   
    client.publish(PtopicC, Pbuf);

    String Htopic = rootTopic;
    Htopic.concat(bme280HumidityTopic);
    unsigned int Hlen = Htopic.length();
    Hlen++;
    char HtopicC[Hlen];
    Htopic.toCharArray(HtopicC, Hlen);
   
    char Hbuf[100];
    sprintf(Hbuf, "%f", bme.readHumidity());
    
    client.publish(HtopicC, Hbuf);
}