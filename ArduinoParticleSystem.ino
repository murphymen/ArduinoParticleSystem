#include "ArduinoParticleSystem.h"

ArduinoParticleSystem particleSystem;

void setup() {
    
    Serial.begin(9600);
}

void loop() {
    particleSystem.update();
    /*
    // Print all "x" values in the used list using an iterator
    for (auto it = pool.usedList.begin(); it != pool.usedList.end(); ++it) {
        p = (particle*)*it;
        p->position.print("position");
    }
    */
}