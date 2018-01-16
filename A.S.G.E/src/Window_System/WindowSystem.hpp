#include <ncurses.h>
// #include "AscWindow.hpp"

namespace ASGE {
    class WindowSystem
    {
    private:
        WINDOW* render_window;
        WINDOW* log_window;
    public:
        WindowSystem();
        void _startUp();
        void _shutDown();
        static WindowSystem& getInstance();
        WINDOW* getRenderWindow();
        WINDOW* getLogWindow();
        WINDOW* createWindow(int width, int height, int startx, int starty);
        void refreshWindows();
        void destroyWindow(WINDOW* del_window);
        void termResized();
    };
} /* A.S.G.E */
