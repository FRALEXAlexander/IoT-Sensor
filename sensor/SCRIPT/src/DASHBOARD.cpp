#include "DASHBOARD.h"
#include "CONFIG.h"
#include "SPIFFS.h"
#include "ESPAsyncWebServer.h"

void ADDDASHBOARDROUTES()
{
    dserver.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        Serial.println("load root");
        request->send(SPIFFS, "/index.html", String(), false);
    });
}