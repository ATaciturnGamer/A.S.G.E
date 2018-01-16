#include "GameLoop.hpp"
#include <iostream>
#include <thread>
#include "Ascii_Render_System/AsciiRenderer.hpp"
#include <ncurses.h>
#include "Input_System/InputSystem.hpp"

GameLoop::GameLoop()
{
    //Initialize certain values maybe
    ticker = Timer();
    _startUp();
}


void GameLoop::_startUp()
{
    AsciiRenderer::getInstance();
    InputSystem::getInstance();
}

void GameLoop::_shutDown()
{
    is_running=false;
}

void GameLoop::Run()
{
    int delta;
    this->_init();
    ticker.start();
    while(is_running)
    {
        delta = ticker.getDelta();
        ticker.start();
        InputSystem::getInstance().fillInputBuffer();
        _update(delta);
        _draw();
        InputSystem::getInstance().flushInputBuffer();
        delta = (int)(1000/target_fps)-ticker.getDelta();
        if (delta>0) std::this_thread::sleep_for(std::chrono::milliseconds(delta));
    }
}

void GameLoop::_draw()
{
   AsciiRenderer::getInstance().drawAll();
}



int main(int argc, char const *argv[]) {
    GameLoop GameLoop;
    GameLoop.Run();
    return 0;
}
