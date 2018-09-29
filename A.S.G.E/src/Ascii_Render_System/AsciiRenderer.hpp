#include <vector>
#include <string>
#include <ncurses.h>

#include "../Math.hpp"

class AsciiRenderer
{
private:
public:
    static AsciiRenderer& getInstance();
    char frame[25][100];
    int attrarr[25][100];
    AsciiRenderer();
    ~AsciiRenderer();

    static void _startUp();
    void _shutDown();
    void clear();
    void render(std::vector<int> pos, std::string fr, int attrs);
    void renderLine(const Point2D p1,const Point2D p2, int attrs);
    void draw(WINDOW* win, int width, int height);
};
