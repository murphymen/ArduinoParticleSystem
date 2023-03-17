#ifndef _ListPool_h_
#define _ListPool_h_

#include "IntrusiveList.h"


// This is a pool of objects that can be used to store data.
// Has two lists, one for free objects and one for used objects.
// When an object is requested, it is removed from the free list and added to the used list.
// When an object is returned, it is removed from the used list and added to the free list.

template <class T>
class ListPool {
private:
    IntrusiveList freeList;
public:
    IntrusiveList usedList;

    ListPool(){};
    ListPool(int size) {
        for (int i = 0; i < size; i++) {
            T *p = new T();
            freeList.push_back(p);
        }
    }

    T* get() {
        if (freeList.size > 0) {
            T *p = (T*)freeList.head;
            freeList.pop_front();
            usedList.push_back(p);
            return p;
        }
        return nullptr;
    }

    void put(T *p) {
        usedList.remove(p);
        freeList.push_back(p);
    }

    void clear() {
        while (usedList.size > 0) {
            T *p = (T*)usedList.head;
            usedList.pop_front();
            freeList.push_back(p);
        }
    }

    void clearAll() {
        clear();
        while (freeList.size > 0) {
            T *p = (T*)freeList.head;
            freeList.pop_front();
            delete p;
        }
    }

    int size() {
        return freeList.size + usedList.size;
    }

    int freeSize() {
        return freeList.size;
    }

    int usedSize() {
        return usedList.size;
    }

    void print() {
        Serial.print("Free: ");
        Serial.print(freeList.size);
        Serial.print(" Used: ");
        Serial.println(usedList.size);
    }

    
};


#endif