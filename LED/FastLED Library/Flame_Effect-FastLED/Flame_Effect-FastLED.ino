#include <FastLED.h>

#define NUM_LEDS 15 // input pin Neopixel is attached to

#define DATA_PIN 2 // number of neopixels in strip

CRGB leds[NUM_LEDS]; // Create array

int i;

void setup() {
  // Initialize the FastLED library.
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {

  // Turn leds 1-4 orange
  for (i = 0; i < 4; i++){
    leds[i] = CRGB::Orange;
  }

    // Turn leds 8-12 purple
  for (i = 8; i < 12; i++){
    leds[i] = CRGB::Purple;
  }

  // This sends the updated pixel color to the hardware.
  FastLED.show();
}
