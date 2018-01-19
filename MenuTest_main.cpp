#include <fstream>
#include <ncurses.h>
#include "A.S.G.E/src/Input_System/InputSystem.hpp"
#include "A.S.G.E/src/Window_System/WindowSystem.hpp"
#include "A.S.G.E/src/GameLoop.hpp"
#include "A.S.G.E/src/Ascii_Render_System/AsciiRenderer.hpp"

int state;
std::string opt1,opt2;
std::string menu1,menu2;
std::vector<int> spos1(2);
std::vector<int> spos2(2);
std::vector<int> menupos(2);


void menuUp()
{
    if (state==1) state=0;
}
void menuDown()
{
    if (state==0) state=1;
}
void menuEnter()
{
    if (state==0)    state = 2;
    else state=3;
}
void menuBack()
{
    if (state==2 || state==3) state = 0;
}

void GameLoop::_init()
{
    is_running=true;
    target_fps = 30;
    state = 0;
    spos1[0] = 45;
    spos1[1] = 7;
    spos2[0] = 45;
    spos2[1] = 15;
    menupos[0] = 34;
    menupos[1] = 7;

    opt1 = "/---------\\\n|  OPT 1  |\n\\---------/";
    opt2 = "/---------\\\n|  OPT 2  |\n\\---------/";
    menu1 = "/------------------------------\\\n\
|           MENU 1             |\n\
|                              |\n\
|    That's what you chose     |\n\
|                              |\n\
|                              |\n\
|           Right?             |\n\
|                              |\n\
|                              |\n\
\\------------------------------/";
    menu2 = "/------------------------------\\\n\
|           MENU 2             |\n\
|                              |\n\
|          Welcome!            |\n\
|                              |\n\
|     Do you come in peace?    |\n\
|                              |\n\
|       \\ [][]--[][] /         |\n\
|        \\____||____/          |\n\
\\------------------------------/";
}

void GameLoop::_update(int delta)
{
    if (InputSystem::getInstance().isKeyPressed(KEY_DOWN))
    {
        menuDown();
    }
    else if (InputSystem::getInstance().isKeyPressed(KEY_UP))
    {
        menuUp();
    }
    else if (InputSystem::getInstance().isKeyPressed((int)'\n'))
    {
        menuEnter();
    }
    else if (InputSystem::getInstance().isKeyPressed(KEY_BACKSPACE))
    {
        menuBack();
    }
    AsciiRenderer::getInstance().clear();
    if (state==0)
    {
        AsciiRenderer::getInstance().render(spos1,opt1,COLOR_PAIR(2),ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin());
        AsciiRenderer::getInstance().render(spos2,opt2,-1,ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin());
    }
    else if (state==1)
    {
        AsciiRenderer::getInstance().render(spos1,opt1,-1,ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin());
        AsciiRenderer::getInstance().render(spos2,opt2,COLOR_PAIR(2),ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin());
    }
    else if (state==2)
    {
        AsciiRenderer::getInstance().render(menupos,menu1,-1,ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin());
    }
    else if (state==3)
    {
        AsciiRenderer::getInstance().render(menupos,menu2,-1,ASGE::WindowSystem::getInstance().getLogWindow()->getNcursesWin());
    }
}
