#ifndef WINDOWSYS_HPP
#define WINDOWSYS_HPP

#include <ncurses.h>
#include "AscWindow.hpp"

namespace ASGE {
    class WindowSystem
    {
    private:
        AscWindow* render_window;
        AscWindow* log_window;
    public:
        WindowSystem();
        void _startUp();
        void _shutDown();
        static WindowSystem& getInstance();
        AscWindow* getRenderWindow();
        AscWindow* getLogWindow();
        AscWindow* createWindow(int width, int height, int startx, int starty);
        void refreshWindows();
        void destroyWindow(AscWindow* del_window);
        void termResized();
    };
} /* A.S.G.E */

#endif
