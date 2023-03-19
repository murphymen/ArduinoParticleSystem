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
  unsigned long lifeTime;
  bool active;
  //void (Particle::*update_fn)(float);
 
  virtual void update(unsigned long) = 0;

  Particle() {
    active = true;
    lifeTime = 0;
    //update_fn = nullptr;
  }

  void set(float x, float y, float dx, float dy, CHSV c, unsigned long lt) {
    position = v2d(x, y);
    speed = v2d(dx, dy);
    color = c;
    lifeTime = lt;
  }

  void clear() {
    lifeTime = 0;
  }

  //void set_update_fn(void (Particle::*fn)(float)) {
  //  update_fn = fn;
  //}

  //void call_update_fn(float dt) {
  //  if (update_fn != nullptr) {
  //    (this->*update_fn)(dt);
  //  }
  //}
};


#endif 