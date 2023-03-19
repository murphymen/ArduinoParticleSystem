#ifndef _TimeManager_h_
#define _TimeManager_h_

#include "Arduino.h"

class TimeManager {
  public:
    unsigned long prevTime;
    unsigned int frameCount;
    int fps;
    unsigned long deltaTime;

    TimeManager() {
      prevTime = 0;
      frameCount = 0;
      fps = 0;
      deltaTime = 0;
    }

    void update() {
      unsigned long currentTime = millis();
      deltaTime = currentTime - prevTime;

      if (deltaTime > 1000) {
        fps = frameCount;
        prevTime = currentTime;
        frameCount = 0;
      }

      frameCount++;
    }

    int get_fps() {
      return 1000/deltaTime;
    }
};


#endif