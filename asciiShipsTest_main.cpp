#include <fstream>
#include <ncurses.h>
#include "A.S.G.E/src/Input_System/InputSystem.hpp"
#include "A.S.G.E/src/Window_System/WindowSystem.hpp"
#include "A.S.G.E/src/GameLoop.hpp"
#include "A.S.G.E/src/Ascii_Render_System/AsciiRenderer.hpp"

int state;
std::string art;
std::vector<float> rpos(2);
std::vector<int> spos(2);


std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    std::string TempLine;                  //Temp line
	    std::getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character

	    Lines += TempLine;                     //Add newline
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
    rpos[0]=16;
    rpos[1]=0;
}

void GameLoop::_update(int delta)
{
    if (InputSystem::getInstance().isKeyPressed(KEY_RIGHT))
    {
        rpos[0]=rpos[0]+30*(delta/1000.0);
    }
    else if (InputSystem::getInstance().isKeyPressed(KEY_DOWN))
    {
        rpos[1]=rpos[1]+30*(delta/1000.0);
    }
    else if (InputSystem::getInstance().isKeyPressed(KEY_UP))
    {
        rpos[1]=rpos[1]-30*(delta/1000.0);
    }
    else if (InputSystem::getInstance().isKeyPressed(KEY_LEFT))
    {
        rpos[0]=rpos[0]-30*(delta/1000.0);
    }

    spos[0]=(int)rpos[0];
    spos[1]=(int)rpos[1];
    AsciiRenderer::getInstance().render(spos,art,-1,ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin());
}
