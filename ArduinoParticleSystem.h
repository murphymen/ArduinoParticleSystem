#ifndef _ArduinoParticleSystem_h_
#define _ArduinoParticleSystem_h_

#include "ListPool.h"
#include "Particle.h"


// class particle that inherits from ListNode
class particle : public ListNode, public Particle {
public:
};

class ArduinoParticleSystem
{
private:
  ListPool<Particle> particles();
public:
  particle* p;


  ArduinoParticleSystem();
  void update();
};

ArduinoParticleSystem::ArduinoParticleSystem()
{
  
}

void ArduinoParticleSystem::update()
{
  
}

#endif 