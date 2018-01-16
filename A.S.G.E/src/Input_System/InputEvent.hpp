#pragma once

#include <vector>
#include <ncurses.h>

#ifndef MOUSE_CONFIG
#define MOUSE_CONFIG BUTTON1_CLICKED|BUTTON2_CLICKED|BUTTON3_CLICKED|BUTTON1_PRESSED|BUTTON1_RELEASED|BUTTON2_PRESSED|BUTTON2_RELEASED|BUTTON3_PRESSED|BUTTON3_RELEASED|REPORT_MOUSE_POSITION
#endif


class InputEvent
{
public:
    int type;
    int mbutton_state;
    std::vector<int> mpos;
    InputEvent(){}
};
