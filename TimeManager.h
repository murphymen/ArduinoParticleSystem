#ifndef _TimeManager_h_
#define _TimeManager_h_

// Class TimeManager checks time passed since last TimeManager::update()
// also calculate frames per second
class TimeManager
{
private:
    unsigned long lastTime;
    unsigned long currentTime;
    unsigned long deltaTime;
    unsigned long fpsTime;
    unsigned long fpsDeltaTime;
    unsigned long fps;
    unsigned long fpsCounter;
public:
    TimeManager();
    void update();
    unsigned long getDeltaTime();
    unsigned long getFps();
};

TimeManager::TimeManager()
{
    lastTime = 0;
    currentTime = 0;
    deltaTime = 0;
    fpsTime = 0;
    fpsDeltaTime = 0;
    fps = 0;
    fpsCounter = 0;
}

void TimeManager::update()
{
    currentTime = millis();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    fpsDeltaTime = currentTime - fpsTime;
    if (fpsDeltaTime >= 1000)
    {
        fps = fpsCounter;
        fpsCounter = 0;
        fpsTime = currentTime;
    }
    fpsCounter++;
}

unsigned long TimeManager::getDeltaTime()
{
    return deltaTime;
}

unsigned long TimeManager::getFps()
{
    return fps;
}

#endif