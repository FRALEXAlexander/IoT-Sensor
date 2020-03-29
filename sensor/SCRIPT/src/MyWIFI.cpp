#include "MyWIFI.h"
#include "Arduino.h"
#include "CONFIG.h"
#include <ESPmDNS.h>

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