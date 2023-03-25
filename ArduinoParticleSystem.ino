#include "TimeManager.h"
#include "ArduinoParticleSystem.h"

ArduinoParticleSystem particleSystem;
unsigned long l = 1;

void setup() {
    
    Serial.begin(115200);
}

void loop() {
    timeManager.update();
    timeManager.printFPS();
    particleSystem.update(timeManager.deltaTime);
}