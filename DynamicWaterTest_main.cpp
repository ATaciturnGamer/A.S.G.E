#include <ncurses.h>

#include "A.S.G.E/include/Game.hpp"
#include "tests/Dynamic_Water/Water2D.hpp"

Water2D *dy_water;


void GameLoop::_init()
{
    is_running=true;
    target_fps = 30;
    Scene *thisScene = SceneSystem::getInstance().getScene();
    dy_water = new Water2D(97,13);
    thisScene->addObject(dy_water);
    mvwprintw(ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin(),1,2,"Log: ");

}
