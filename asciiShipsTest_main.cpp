#include <fstream>
#include <ncurses.h>
#include "A.S.G.E/src/Input_System/InputSystem.hpp"
#include "A.S.G.E/src/GameLoop.hpp"
#include "A.S.G.E/src/Ascii_Render_System/AsciiRenderer.hpp"

// #include <conio.h>
//
// #include <Windows.h>

int state;
std::string art;
std::vector<float> rpos(2);
std::vector<int> spos(2);
// HANDLE wHnd;    // Handle to write to the console.
// HANDLE rHnd;    // Handle to read from the console.


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
    rpos[0]=0;
    rpos[1]=0;

    // //TESTING Window
    // wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    // rHnd = GetStdHandle(STD_INPUT_HANDLE);
    //
    // SetConsoleTitle(TEXT("Win32 Console Control Demo"));
    //
    // // Set up the required window size:
    // SMALL_RECT windowSize = {0, 0, 100, 26};
    //
    // // Change the console window size:
    // SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    // // Create a COORD to hold the buffer size:
    // COORD bufferSize = {101, 27};
    //
    // // Change the internal buffer size:
    // SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void GameLoop::_update(int delta)
{
    if (InputSystem::getInstance().isKeyPressed(KEY_RIGHT))
    {
        rpos[0]=rpos[0]+30*(delta/1000.0);
    }
    if (InputSystem::getInstance().isMouseKeyPressed(BUTTON1_PRESSED))
    {
        rpos[1]=rpos[1]+30*(delta/1000.0);
    }
    spos[0]=(int)rpos[0];
    spos[1]=(int)rpos[1];
    AsciiRenderer::getInstance().clear();
    AsciiRenderer::getInstance().render(spos,art);
}
