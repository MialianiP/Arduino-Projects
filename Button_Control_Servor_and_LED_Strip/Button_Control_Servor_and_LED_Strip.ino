
#include <Servo.h>
#include <FastLED.h>

#define NUM_LEDS 4 // input pin Neopixel is attached to

#define DATA_PIN 2 // number of neopixels in strip

CRGB leds[NUM_LEDS]; // Create array

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO1_PIN = 9; // Arduino pin connected to servo1's pin
const int SERVO2_PIN = 10; // Arduino pin connected to servo2's pin
const int SERVO3_PIN = 11; // Arduino pin connected to servo3's pin

Servo servo1; // create servo object to control servo1
Servo servo2; // create servo object to control servo2
Servo servo3; // create servo object to control servo3

// variables will change:
int angle = 0;          // the current angle of servo motor
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  
  //servo.attach(pin, min pulse width, max pulse width)  pulse width in microseconds 
  servo1.attach(SERVO1_PIN, 500, 2500);           // attaches servo variable to pin 9
  servo2.attach(SERVO2_PIN, 500, 2500);           // attaches servo variable to pin 10
  servo3.attach(SERVO3_PIN, 500, 2500);           // attaches servo variable to pin 11

  currentButtonState = digitalRead(BUTTON_PIN);
  // Initialize the FastLED library.
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  //servo1.write(angle);
  //servo2.write(angle);
  //servo3.write(angle);

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if(angle == 0) {
      angle = 25;
      
      // control servo motor arccoding to the angle
      servo1.write(angle);
      servo2.write(angle);
      servo3.write(angle);
    
      // Turn the first led red
      leds[0] = CRGB::Red;
      // This sends the updated pixel color to the hardware.
      FastLED.show();
    }
    
    else if(angle == 25) {
      angle = 0;
      
      // control servo motor according to the angle
      servo1.write(angle);
      servo2.write(angle);
      servo3.write(angle);
      
      // Turn the first led white
      FastLED.clear();
      // This sends the updated pixel color to the hardware.
      FastLED.show();
  }
  }
}
