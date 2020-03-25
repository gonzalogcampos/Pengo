#include <chrono>

class Clock
{
    private:
        std::chrono::duration<double>  elapsedTime; //The elapsed time on a single iteration
        std::chrono::time_point<std::chrono::high_resolution_clock> lastTime; //The elapsed time amounted
    public:
        Clock();
        float getElapsedTime();
        bool canContinue();


};

Clock::Clock()
{
    lastTime = std::chrono::high_resolution_clock::now();
};

float Clock::getElapsedTime()
{
    return elapsedTime.count();
};

bool Clock::canContinue()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();

    elapsedTime = currentTime - lastTime;

    double minTime = 1.0/60;
    if(elapsedTime.count() > minTime)
    {
        lastTime = currentTime;
        return true;
    }
    return false;
};