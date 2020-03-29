#include "MOTIONSENSOR.h"
#include "CONFIG.h"
#include "MQTT.h"
#include "Arduino.h"

bool motionChange = false;

void MOTIONSENSOR()
{
    motionChange = true;
}

void MOTIONSENSORSETUP()
{
    pinMode(motionsensorPin, INPUT);
    attachInterrupt(motionsensorPin, MOTIONSENSOR, CHANGE);
}

void MOTIONSENSORLOOP()
{
    if (motionChange)
    {
        String Htopic = rootTopic;
        Htopic.concat(motionsensorTopic);
        unsigned int Hlen = Htopic.length();
        Hlen++;
        char HtopicC[Hlen];
        Htopic.toCharArray(HtopicC, Hlen);
       
        char Hbuf[100];
        bool status = digitalRead(motionsensorPin);
        sprintf(Hbuf, "%d", status);
        client.publish(HtopicC, Hbuf);
        motionChange = false;
    }
}