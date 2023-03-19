#include "TimeManager.h"
#include "ArduinoParticleSystem.h"

TimeManager timeManager;
ArduinoParticleSystem particleSystem;

void setup() {
    
    Serial.begin(9600);
}

void loop() {
    timeManager.update();
    particleSystem.update(timeManager.deltaTime);
}