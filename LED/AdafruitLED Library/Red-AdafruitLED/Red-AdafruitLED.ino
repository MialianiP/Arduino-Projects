#include <Adafruit_NeoPixel.h>

#define PIN 2   // input pin Neopixel is attached to

#define NUMPIXELS 4 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // Initialize the NeoPixel library.
  pixels.begin();
}

void loop() {

  pixels.clear(); // Set all pixel colors to 'off'

  // pixel.fill(color, start LED, # of LED to light)
  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  pixels.fill(pixels.Color(255, 0, 0),0,4);

  // This sends the updated pixel color to the hardware.
  pixels.show();

  // Delay for a period of time (in milliseconds).
  delay(delayval);
}
