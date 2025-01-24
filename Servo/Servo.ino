
#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO1_PIN = 9; // Arduino pin connected to servo1's pin

Servo servo1; // create servo object to control servo1

// variables will change:
int angle = 30;          // the current angle of servo motor
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  
  //servo.attach(pin, min pulse width, max pulse width)  pulse width in microseconds 
  servo1.attach(SERVO1_PIN, 500, 2500);           // attaches servo variable to pin 9
  servo1.write(angle);
  
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if(angle == 30) {
      angle = 0;
      
      // control servo motor arccoding to the angle
      servo1.write(angle);
    }
    
    else if(angle == 0) {
      angle = 30;
      
      // control servo motor according to the angle
      servo1.write(angle);
  }
  }
}
