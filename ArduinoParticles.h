#ifndef _ArduinoParticles_h_
#define _ArduinoParticles_h_

#include <PooledList.h>
#include "Particle.h"



class ArduinoParticles
{
private:
  PooledList<Particle> particles;
public:

  ArduinoParticles();
  void update();
};

ArduinoParticles::ArduinoParticles()
{
  
}

void ArduinoParticles::update()
{
  
}

#endif 