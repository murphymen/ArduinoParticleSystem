#ifndef _TimeManager_h_
#define _TimeManager_h_

#include "Arduino.h"

class TimeManager {
public:
    TimeManager() {
        lastTime = 0;
        deltaTime = 0.0f;
        fps = 0;
        frames = 0;
    }

    void update() {
        long currentTime = millis();
        if (lastTime == 0) {
            lastTime = currentTime;
            return;
        }
        deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        frames++;
    }

    void printFPS() {
        if (frames == 0) {
            fps = 0;
        } else {
            fps = (int)(1.0f / deltaTime);
        }
        Serial.print("FPS: ");
        Serial.println(fps);
        frames = 0;
    }

private:
    long lastTime;
    float deltaTime;
    int fps;
    int frames;
};



#endif