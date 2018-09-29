#include <fstream>
#include <list>
#include <ncurses.h>
#include "A.S.G.E/src/Input_System/InputSystem.hpp"
#include "A.S.G.E/src/GameLoop.hpp"
#include "A.S.G.E/src/Ascii_Render_System/AsciiRenderer.hpp"
// #include "A.S.G.E/src/Scene_System/Scene.hpp"
#include "A.S.G.E/src/Scene_System/SceneSystem.hpp"

#include "A.S.G.E/src/Entity/Shape2D/Polygon2D.hpp"
#include "A.S.G.E/src/Window_System/WindowSystem.hpp"

#include "Ship.hpp"

int state;
std::string art;
std::vector<float> rpos(2);
std::vector<int> spos(2);


Scene *thisScene;
Ship *ship;
// Ship ship2;
Polygon2D *plgn;


std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";

    if (File)
    {
	while (File.good ())
	{
	    std::string TempLine;
	    std::getline (File , TempLine);        //Get temp line
	    TempLine += "\n";

	    Lines += TempLine;
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
}

void GameLoop::_init()
{
    is_running=true;
    target_fps = 30;
    state = 0;
    thisScene = SceneSystem::getInstance().getScene();
    std::ifstream Reader ("ascii_assets/b_ship1.asa");
    art = getFileContents (Reader);
    ship = new Ship();
    ship->setSprite(&art);
    // ship2 = Ship(art);
    ship->setPos(10,5);
    // ship2.setPos(10,1,4);
    ship->testIsMove=true;
    thisScene->addObject(ship);
    // thisScene->addObject(&ship2);
    plgn = new Polygon2D();
    plgn->pushVertex(-5.0,5.0);
    plgn->pushVertex(5.0,5.0);
    plgn->pushVertex(0.0,-7.0);
    plgn->setPos(50.0,12.0);
    thisScene->addObject(plgn);
    mvwprintw(ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin(),1,2,"Log: ");
}
