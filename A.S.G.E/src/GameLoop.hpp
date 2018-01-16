#pragma once
#include "Timer.hpp"

class GameLoop{
private:
    bool is_running;
    Timer ticker;
    int target_fps = 30;

    void _init();
    void _processInput();

    void _update(int delta);
    void _draw();
    void _startUp();
    void _shutDown();
public:
    GameLoop();
    void Run();
};
