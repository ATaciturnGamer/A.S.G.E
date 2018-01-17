#include "GameLoop.hpp"
#include <iostream>
#include <thread>
#include "Window_System/WindowSystem.hpp"
#include "Ascii_Render_System/AsciiRenderer.hpp"
#include "Input_System/InputSystem.hpp"
#include <ncurses.h>

ASGE::AscWindow *win_render, *win_log;

GameLoop::GameLoop()
{
    //Initialize certain values maybe
    ticker = Timer();
    _startUp();
}


void GameLoop::_startUp()
{
    ASGE::WindowSystem::getInstance()._startUp();
    AsciiRenderer::getInstance();
    InputSystem::getInstance();
    win_render = ASGE::WindowSystem::getInstance().getRenderWindow();
    win_log = ASGE::WindowSystem::getInstance().getLogWindow();
}

void GameLoop::_shutDown()
{
    // wprintw(ASGE::WindowSystem::getInstance().getRenderWindow(),"sssfdsdfs\n");
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
        // wrefresh(ASGE::WindowSystem::getInstance().getLogWindow());
        // wrefresh(ASGE::WindowSystem::getInstance().getRenderWindow());
        InputSystem::getInstance().fillInputBuffer(win_log->getNcursesWin());
        if (InputSystem::getInstance().isKeyPressed(KEY_RESIZE))
        {
            ASGE::WindowSystem::getInstance().termResized();
        }
        _update(delta);
        _draw();
        InputSystem::getInstance().flushInputBuffer();
        ASGE::WindowSystem::getInstance().refreshWindows();
        delta = (int)(1000/target_fps)-ticker.getDelta();
        if (delta>0) std::this_thread::sleep_for(std::chrono::milliseconds(delta));
    }
}

void GameLoop::_draw()
{
   AsciiRenderer::getInstance().draw(win_render->getNcursesWin(),100,25);
}



int main(int argc, char const *argv[]) {
    GameLoop GameLoop;
    GameLoop.Run();
    return 0;
}
