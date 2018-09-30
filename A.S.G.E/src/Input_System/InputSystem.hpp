#ifndef INPUTSYS_HPP
#define INPUTSYS_HPP

#include <list>
#include <algorithm>
#include <ncurses.h>
#include "InputEvent.hpp"

class InputSystem
{
private:
    std::list<InputEvent> inputBuffer;

public:
    static InputSystem& getInstance();
    InputSystem();
    ~InputSystem();

    void _startUp();
    void _shutDown();

    void fillInputBuffer(WINDOW* win);
    void flushInputBuffer();
    int getKeyPressed();
    bool isKeyPressed(int scancode);
    bool isMouseKeyPressed(int scancode);
};

#endif
