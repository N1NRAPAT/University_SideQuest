
#include <Arduino.h>

// LED pins
const int LED1 = 11;
const int LED2 = 12;
const int LED3 = 13;

// Input pins
const int POT = A5;
const int BUTTON = 4;

int sensorVal = 0;

void setup() {
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    // HIGH when pressed, LOW when released
    // Requires external pull-down resistor
    pinMode(BUTTON, INPUT);

    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i < 8; i++) {

        // Pause if button is pressed
        while (digitalRead(BUTTON) == HIGH) {
            // Wait for release
        }

        // Read potentiometer
        sensorVal = analogRead(POT);

        // Binary counting
        digitalWrite(LED1, (i >> 0) & 1);
        digitalWrite(LED2, (i >> 1) & 1);
        digitalWrite(LED3, (i >> 2) & 1);

        // Debug output
        Serial.print("Index: ");
        Serial.print(i);
        Serial.print(" ADC: ");
        Serial.println(sensorVal);

        // Adjustable pattern speed
        delay(sensorVal);
    }
}
