#include "Timer.hpp"
Timer::Timer()
{

}

int Timer::getDelta()
{
    _now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(_now-_start).count();
}

void Timer::start()
{
    _start = std::chrono::system_clock::now();
}
