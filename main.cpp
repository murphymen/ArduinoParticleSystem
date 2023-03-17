#include "ListPool.h"
#include "Particle.h"


// class particle that inherits from ListNode
class particle : public ListNode, public Particle {
public:
    //int x;
    //int y;
};

particle* p;
ListPool<particle> pool(5);

void setup() {
    for(int i = 0; i <3; i++) {
        p = pool.get();
        p->position.set(i,i);
    }
    
    Serial.begin(9600);
}

void loop() {
    // Print all "x" values in the used list using an iterator
    for (auto it = pool.usedList.begin(); it != pool.usedList.end(); ++it) {
        p = (particle*)*it;
        p->position.print("position");
    }
}