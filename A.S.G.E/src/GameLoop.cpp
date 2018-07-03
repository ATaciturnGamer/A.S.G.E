#include "GameLoop.hpp"
#include <iostream>
#include <thread>
#include "Window_System/WindowSystem.hpp"
#include "Ascii_Render_System/AsciiRenderer.hpp"
#include "Input_System/InputSystem.hpp"
#include "Scene_System/SceneSystem.hpp"
#include <ncurses.h>

ASGE::AscWindow *win_render, *win_log;
Scene *currentScene;

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
    SceneSystem::getInstance()._startUp();
    win_render = ASGE::WindowSystem::getInstance().getRenderWindow();
    win_log = ASGE::WindowSystem::getInstance().getLogWindow();
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
        currentScene = SceneSystem::getInstance().getScene();
        InputSystem::getInstance().fillInputBuffer(win_log->getNcursesWin());
        if (InputSystem::getInstance().isKeyPressed(KEY_RESIZE))
        {
            ASGE::WindowSystem::getInstance().termResized();
        }
        _update(delta);
        _draw();
        InputSystem::getInstance().flushInputBuffer();
        ASGE::WindowSystem::getInstance().refreshWindows();
        AsciiRenderer::getInstance().clear();
        delta = (int)(1000/target_fps)-ticker.getDelta();
        if (delta>0) std::this_thread::sleep_for(std::chrono::milliseconds(delta));
    }
}

void GameLoop::_draw()
{
   AsciiRenderer::getInstance().draw(win_render->getNcursesWin(),100,25);
}

void GameLoop::_update(int delta)
{
    for (std::list<GameObject*>::const_iterator iter=currentScene->objectList.begin(); iter!=currentScene->objectList.end(); iter++)
    {
        (*iter)->_update(delta);
        (*iter)->_draw();
    }
}

int main(int argc, char const *argv[]) {
    GameLoop GameLoop;
    GameLoop.Run();
    return 0;
}
