#include "GY1145.h"
#include "CONFIG.h"
#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_SI1145.h>
#include "MQTT.h"

Adafruit_SI1145 uv = Adafruit_SI1145();

void GY1145SETUP()
{
    uv.begin();
}

float *GY1145MEASURE()
{
    float *out = new float[4];
    out[0] = uv.readIR();
    out[1] = uv.readUV();
    out[2] = uv.readVisible();
    out[3] = uv.readProx();
    return out;
}

void GY1145LOOP()
{

    float UVindex = uv.readUV();
    String Ttopic = rootTopic;
    Ttopic.concat(gy1145UVTopic);
    unsigned int Tlen = Ttopic.length();
    Tlen++;
    char TtopicC[Tlen];
    Ttopic.toCharArray(TtopicC, Tlen);

    char Tbuf[100];
    sprintf(Tbuf, "%f", UVindex);

    client.publish(TtopicC, Tbuf);

    String Ptopic = rootTopic;
    Ptopic.concat(gy1145VISTopic);
    unsigned int Plen = Ptopic.length();
    Plen++;
    char PtopicC[Plen];
    Ptopic.toCharArray(PtopicC, Plen);

    char Pbuf[100];
    sprintf(Pbuf, "%d", uv.readVisible());

    client.publish(PtopicC, Pbuf);

    String Htopic = rootTopic;
    Htopic.concat(gy1145IRTopic);
    unsigned int Hlen = Htopic.length();
    Hlen++;
    char HtopicC[Hlen];
    Htopic.toCharArray(HtopicC, Hlen);

    char Hbuf[100];
    sprintf(Hbuf, "%d", uv.readIR());

    client.publish(HtopicC, Hbuf);
}