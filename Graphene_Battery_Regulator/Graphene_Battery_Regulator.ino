#include <Arduino.h>
// MCP4162 is used in this program
const int buttonPin = 2;    // GPIO pin connected to the push-button
const int ledPin = 2;       // ESP32 built-in LED pin
const int voltagePin = 34;  // GPIO pin connected to the voltage divider

int voltageLevel = 0;  // The voltage level (0-3)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Use the internal pull-up resistor for the button
  pinMode(ledPin, OUTPUT);
  pinMode(voltagePin, INPUT);

  // Other initialization code for the digital potentiometer, voltage divider, and ADC

  // Initialize the LED state
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    // Button is pressed
    voltageLevel = (voltageLevel + 1) % 4; // Cycle through 0-3

    // Set the voltage using the digital potentiometer
    setVoltage(voltageLevel);

    // Blink the LED based on the voltage level
    blinkLED(voltageLevel);

    delay(200);
  }
}

void setVoltage(int level) {
  // Code to set the digital potentiometer to the desired level (2V, 4V, 6V, or 12V)
  // You need to implement this based on the specific hardware you are using.
  // Refer to the datasheet of the digital potentiometer for how to control it.

  // Example: Change the voltage level based on a potentiometer setting
  // You may need to replace this with actual code to control your voltage source.
  float voltage = 0;
  switch (level) {
    case 0: voltage = 2.0; break;
    case 1: voltage = 4.0; break;
    case 2: voltage = 6.0; break;
    case 3: voltage = 12.0; break;
  }
  // Set the voltage using your hardware
}

void blinkLED(int level) {
  // Code to blink the LED based on the voltage level
  // For example, you can make the LED blink faster as the voltage level increases.
  int delayTime = 1000 / (level + 1);  // Adjust the LED blink delay
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}
