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
  ListPool<particle> particles;
public:
  particle* p;


  ArduinoParticleSystem();
  void update();
};

ArduinoParticleSystem::ArduinoParticleSystem()
{
  particles.setup(5);
  for(int i = 0; i < 5; i++)
  {
    p = particles.get();
    p->position.set(i, i);
  }
}

void ArduinoParticleSystem::update()
{
    // Print all "x" values in the used list using an iterator
    for (auto it = particles.usedList.begin(); it != particles.usedList.end(); ++it) {
        p = (particle*)*it;
        p->position.print("position");
    }
}

#endif 