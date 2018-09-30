#ifndef ASCRENDER_HPP
#define ASCRENDER_HPP

#include <vector>
#include <string>
#include <ncurses.h>

#include "../Core/Math.hpp"

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

    void putSym(std::vector<int> pos, char sym, int attrs);
    void render(std::vector<int> pos, std::string fr, int attrs);
    void renderLine(const Point2D p1,const Point2D p2, int attrs);
    void draw(WINDOW* win, int width, int height);
};

#endif
