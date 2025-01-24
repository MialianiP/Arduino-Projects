#include <FastLED.h>

#define NUM_LEDS 10 // input pin Neopixel is attached to

#define DATA_PIN 2 // number of neopixels in strip

CRGB leds[NUM_LEDS]; // Create array

int i;

void setup() {
  Serial.begin(9600); // setup serial
  
  // Initialize the FastLED library.
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  Serial.println(analogRead(A0));

  // Turn the first 4 leds red
  for (i = 0; i < 4; i++){
    leds[i] = CRGB::Red;
  }

  // This sends the updated pixel color to the hardware.
  FastLED.show();
  
  delay(100);
} 
