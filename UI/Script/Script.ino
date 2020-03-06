#include <NeoPixelBus.h>


const uint16_t PixelCount = 5; //enter number of pixel
const uint8_t PixelPin = 18;  // make sure to set this to the correct pin, ignored for Esp8266


// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);
void setup() {
  // put your setup code here, to run once:
  strip.Begin();
  strip.Show();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < PixelCount; i++)
  {
    strip.SetPixelColor(i, RgbColor (random(254), random(254), random(254)));
  }
  strip.Show();
  delay(1000);
}
