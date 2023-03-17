#include "ArduinoParticleSystem.h"

ArduinoParticleSystem particleSystem;

void setup() {
    
    Serial.begin(9600);
}

void loop() {
    particleSystem.update();
}