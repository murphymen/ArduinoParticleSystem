#ifndef _Particle_h_
#define _Particle_h_

#include <FastLED.h>
#include "v2d.h"


// Define the Particle class
class Particle {
public:
  v2d position;
  v2d speed;
  CHSV color;
  uint16_t life_time;
  void (Particle::*update_fn)(float);

  Particle() {
    life_time = 0;
    update_fn = nullptr;
  }

  void set(float x, float y, float dx, float dy, CHSV c, uint16_t lt) {
    position = v2d(x, y);
    speed = v2d(dx, dy);
    color = c;
    life_time = lt;
  }

  void clear() {
    life_time = 0;
  }

  void update(float dt) {
    // Update the particle's position and speed based on the elapsed time
    position.x += speed.x * dt;
    position.y += speed.y * dt;
    speed.y += 9.8f * dt;
  }

  void set_update_fn(void (Particle::*fn)(float)) {
    update_fn = fn;
  }

  void call_update_fn(float dt) {
    if (update_fn != nullptr) {
      (this->*update_fn)(dt);
    }
  }
};


#endif 