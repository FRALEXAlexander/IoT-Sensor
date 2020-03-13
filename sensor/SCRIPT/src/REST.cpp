#include "REST.h"
#include "CONFIG.h"
#include "BME280.h"
#include "GY1145.h"
void ADDRESTROUTES()
{
    server.on("/BME280", HTTP_GET, []() {
        float *data = BME280MEASURE();
        char out[100];
        sprintf(out, "{\"temperature\":%f,\"pressure\":%f,\"humidity\":%f,\"altitude\":%f}", data[0],data[1],data[2],data[3]);
        Serial.println(out);
        server.sendHeader("Access-Control-Allow-Origin","*");
        server.sendHeader("Connection", "close");
        server.send(200, "text/html", out);
    });
    server.on("/GY1145", HTTP_GET, []() {
        float *data = GY1145MEASURE();
        char out[100];
        sprintf(out, "{\"IR\":%f,\"UV\":%f,\"VIS\":%f,\"PROX\":%f}", data[0],data[1],data[2],data[3]);
        Serial.println(out);
        server.sendHeader("Connection", "close");
         server.sendHeader("Access-Control-Allow-Origin","*");
        server.send(200, "text/html", out);
          
           
    });
}