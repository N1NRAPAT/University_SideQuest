#include <Arduino.h>

const int irSensorPin = A4; // Pin connected to the IR sensor
int irSensorValue = 0; // Variable to store the IR sensor value

void setup() {
    Serial.begin(9600);
    pinMode(irSensorPin, INPUT);
}

void loop(){
    
    for(int i = 0; i < 8; i++){
        irSensorValue = analogRead(irSensorPin);
    }
    
    irSensorValue = irSensorValue >> 3; // Average the readings to reduce noise

    Serial.println(irSensorValue);

    delay(50); // Delay for a short period before the next reading
}