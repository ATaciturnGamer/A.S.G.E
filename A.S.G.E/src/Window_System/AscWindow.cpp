#include "AscWindow.hpp"

namespace ASGE
{
    AscWindow::AscWindow(int w, int h, int x, int y)
    {
        height = h;
        width = w;
        this->x = x;
        this->y = y;
        ncurses_window = newwin(h, w, y, x);
    }

    AscWindow::~AscWindow()
    {
        delwin(ncurses_window);
    }

    WINDOW* AscWindow::getNcursesWin()
    {
        return ncurses_window;
    }

    std::vector<int> AscWindow::getSize()
    {
        std::vector<int> v(2);
        v[0]=this->width;
        v[1]=this->height;
        return v;
    }

    std::vector<int> AscWindow::getPos()
    {
        std::vector<int> v(2);
        v[0]=this->x;
        v[1]=this->y;
        return v;
    }

}
