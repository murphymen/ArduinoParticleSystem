#ifndef _ArduinoParticleSystem_h_
#define _ArduinoParticleSystem_h_

#include "ListPool.h"
#include "Particle.h"


// class particle that inherits from ListNode
class particle : public ListNode, public Particle {
public:
  void update(unsigned long deltaTime) override;
};

// Function update() for injecting into particle object
void particle::update(unsigned long deltaTime) {
    // Substract time.deltaTime from lifetime
    lifeTime -= deltaTime;
    // If lifetime is less than time.deltaTime, set active to false
    if (lifeTime < deltaTime) {
        active = false;
    }

    Serial.print(deltaTime);
}

class ArduinoParticleSystem
{
private:
  ListPool<particle> particles;
public:
  particle* p;


  ArduinoParticleSystem();
  void update(unsigned long deltaTime);
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

void ArduinoParticleSystem::update(unsigned long deltaTime)
{
    // Print all "x" values in the used list using an iterator
    for (auto it = particles.usedList.begin(); it != particles.usedList.end(); ++it) {
        p = (particle*)*it;
        p->update(deltaTime);

        if(!p->active)
        {
            particles.put(p);
            continue;
        }

        p->position.print("position");
    }
}

#endif 