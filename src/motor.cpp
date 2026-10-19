#include <Arduino.h>

/*
  TB6612FNG Motor Driver
  Potentiometer Speed and Direction Control
*/

// Pin allocation
const int pinBI1 = 7;
const int pinBI2 = 8;
const int pinPWM = 5;
const int potPin = A5;

// Motor control variables
boolean BI1 = 0;
boolean BI2 = 0;
boolean standBy = 1;  // STBY connected to +5V

unsigned char pwmValue = 0;
int potReading = 0;

void setup() {

  // Set pin directions
  pinMode(pinBI1, OUTPUT);
  pinMode(pinBI2, OUTPUT);
  pinMode(pinPWM, OUTPUT);

  // Initialise serial communication
  Serial.begin(9600);

  // Motor initially stopped
  digitalWrite(pinBI1, LOW);
  digitalWrite(pinBI2, LOW);
  analogWrite(pinPWM, 0);
}

void loop() {

  // Read potentiometer ADC (0 - 1023)
  potReading = analogRead(potPin);

  if (potReading < 512) {

    // Counter-clockwise direction
    BI1 = 0;
    BI2 = 1;

    // Map ADC 0-512 to PWM 255-0
    pwmValue = map(potReading, 0, 512, 255, 0);

  }
  else if (potReading > 512) {

    // Clockwise direction
    BI1 = 1;
    BI2 = 0;

    // Map ADC 512-1023 to PWM 0-255
    pwmValue = map(potReading, 512, 1023, 0, 255);

  }
  else {

    // Centre position - Motor stopped
    BI1 = 0;
    BI2 = 0;
    pwmValue = 0;
  }

  // Write motor direction
  digitalWrite(pinBI1, BI1);
  digitalWrite(pinBI2, BI2);

  // Write PWM to motor
  analogWrite(pinPWM, pwmValue);

  // Serial Monitor diagnostics
  Serial.print("ADC = ");
  Serial.print(potReading);

  Serial.print(" | PWM = ");
  Serial.print(pwmValue);

  Serial.print(" | Standby = ");
  Serial.print(standBy);

  Serial.print(" | BI1 = ");
  Serial.print(BI1);

  Serial.print(" | BI2 = ");
  Serial.println(BI2);

  delay(50);
}
