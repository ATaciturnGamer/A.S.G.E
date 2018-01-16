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


// void GameLoop::_update(int delta)
// {
//     //MUST BE OVERRIDEN
//     //Do stuff
//     printf("%d\n",delta);;
// }

// void GameLoop::_draw()
// {
//     //Draw GameLoop board
// }

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
   // CHAR_INFO consoleBuffer[100 * 27];
   // // We'll fill the console buffer with random data:
   // for (int y = 0; y < 25; ++y) {
   //     for (int x = 0; x < 100; ++x) {
   //
   //         // An ANSI character is in the range 0-255,
   //         // so use % to keep it in this range.
   //         if (AsciiRenderer::getInstance().frame[y][x]!='\n')
   //         {
   //             consoleBuffer[x + 100 * y].Char.AsciiChar = (int)AsciiRenderer::getInstance().frame[y][x];
   //             // The colour is also in the range 0-255,
   //             // as it is a pair of 4-bit colours.
   //             consoleBuffer[x + 100 * y].Attributes = 4;
   //         }
   //         else
   //         {
   //             consoleBuffer[x + 100 * y].Char.AsciiChar = 0;
   //             consoleBuffer[x + 100 * y].Attributes = 4;
   //         }
   //     }
   // }
   //
   // // Set up the positions:
   // COORD charBufSize = {100,25};
   // COORD characterPos = {0,0};
   // SMALL_RECT writeArea = {0,0,99,24};
   //
   // // Write the characters:
   // WriteConsoleOutputA(wHnd, consoleBuffer, charBufSize, characterPos, &writeArea);
   AsciiRenderer::getInstance().drawAll();
}



int main(int argc, char const *argv[]) {
    GameLoop GameLoop;
    GameLoop.Run();
    return 0;
}
