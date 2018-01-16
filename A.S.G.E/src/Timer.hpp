#include <chrono>
class Timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> _start;
    std::chrono::time_point<std::chrono::system_clock> _now;

public:
    Timer();
    void start();
    int getDelta();
};
