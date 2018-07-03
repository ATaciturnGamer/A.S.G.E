#include <fstream>
#include <list>
#include <ncurses.h>
#include "A.S.G.E/src/Input_System/InputSystem.hpp"
#include "A.S.G.E/src/GameLoop.hpp"
#include "A.S.G.E/src/Ascii_Render_System/AsciiRenderer.hpp"
// #include "A.S.G.E/src/Scene_System/Scene.hpp"
#include "A.S.G.E/src/Scene_System/SceneSystem.hpp"
#include "Ship.hpp"

int state;
std::string art;
std::vector<float> rpos(2);
std::vector<int> spos(2);


Scene *thisScene;
Ship ship;
Ship ship2;


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
    std::ifstream Reader ("ascii_assets/ship1.asa");
    art = getFileContents (Reader);
    ship = Ship(art);
    ship2 = Ship(art);
    ship.setPos(20,1);
    ship2.setPos(10,1,4);
    ship2.testIsMove=true;
    thisScene = SceneSystem::getInstance().getScene();
    thisScene->addObject(&ship);
    thisScene->addObject(&ship2);
}
