#include <chrono>

class Clock
{
    private:
        std::chrono::duration<double>  elapsedTime; //The elapsed time on a single iteration
        std::chrono::duration<double>  interpolatedTime; //The elapsed time on a single iteration
        std::chrono::time_point<std::chrono::high_resolution_clock> lastTime; //The elapsed time amounted
        std::chrono::time_point<std::chrono::high_resolution_clock> lastInterpolatedTime; //The elapsed time amounted
    public:
        Clock();
        float getElapsedTime();
        float getInterpolated();
        bool canContinue();


};

Clock::Clock()
{
    lastTime = std::chrono::high_resolution_clock::now();
}

float Clock::getElapsedTime()
{
    return elapsedTime.count();
}

float Clock::getInterpolated()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();

    interpolatedTime = currentTime - lastInterpolatedTime;
    lastInterpolatedTime = currentTime;
    return interpolatedTime.count();
}

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