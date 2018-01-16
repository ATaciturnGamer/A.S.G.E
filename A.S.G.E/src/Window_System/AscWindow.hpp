#include <ncurses.h>
#include <vector>

namespace ASGE
{
    class AscWindow
    {
    private:
        int x,y;
        int width;
        int height;
        WINDOW* ncurses_window;
    public:
        AscWindow(int w, int h, int y, int x);
        ~AscWindow();
        WINDOW* getNcursesWin();
        std::vector<int> getSize();
        std::vector<int> getPos();

    };
}
