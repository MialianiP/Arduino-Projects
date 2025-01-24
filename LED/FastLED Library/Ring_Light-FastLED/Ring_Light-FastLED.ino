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

    // Turn leds 20-30 white
  for (i = 0; i < 20; i++){
    leds[i] = CRGB::White;
  }

  // This sends the updated pixel color to the hardware.
  FastLED.show();
}
