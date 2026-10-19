
#include <Arduino.h>
#include <Servo.h>

#define pinServo1 9

Servo servo1;

// LED pins
const int LED1 = 11;
const int LED2 = 12;
const int LED3 = 13;

// Input pins
const int POT = A5;
const int BUTTON = 4;

int sensorVal = 0;
int angle = 90;


void setup() {

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    // HIGH when pressed, LOW when released
    // Requires external pull-down resistor
    pinMode(BUTTON, INPUT);

    // Servo setup this is gonna bring servo to 90 degrees position
    servo1.attach(pinServo1);
    servo1.write(90);
   
    Serial.begin(9600);
}

void loop() {

    for (int i = 0; i < 8; i++) {

        // Pause if button is pressed
         if (digitalRead(BUTTON) == HIGH) {

        // Move 1 degree left
        if (angle > 0) {
            angle--;
            servo1.write(angle);
        }

        delay(500);
    }
        else {
        // Return to middle
          angle = 90;
          servo1.write(angle);
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
