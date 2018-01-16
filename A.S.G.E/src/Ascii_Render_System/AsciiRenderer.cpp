#include "AsciiRenderer.hpp"

AsciiRenderer::AsciiRenderer()
{
	_startUp();
}

AsciiRenderer::~AsciiRenderer()
{
	_shutDown();
}

void AsciiRenderer::_startUp()
{
	initscr();
	raw();
	keypad(stdscr,TRUE);
	noecho();
	nodelay(stdscr,TRUE);
}

void AsciiRenderer::_shutDown()
{
	endwin();
}

AsciiRenderer& AsciiRenderer::getInstance()
{
	static AsciiRenderer *instance = new AsciiRenderer();
	return *instance;
}

void AsciiRenderer::clear()
{
    for (int i=0;i<25;i++)
    {
        for (int j=0;j<100;j++)
        {
            frame[i][j]=' ';
        }
    }
}

void AsciiRenderer::render(std::vector<int> pos, std::string obj)
{
    unsigned int ctr = 0;
    int i=pos[0];//X coord
    int j=pos[1];//Y coord
    char c = obj[ctr];
    while(ctr<obj.length() and j<25)
    {
        if (i<100)
        {
            frame[j][i++]=c;
        }
        c=obj[++ctr];
        if (c=='\n')
        {
            i=pos[0];
            j++;
        }
    }
}

void AsciiRenderer::drawAll()
{
	for (int y = 0; y < 25; ++y) {
        for (int x = 0; x < 100; ++x) {
			mvwaddch(stdscr,y, x, frame[y][x]);
		}
	}
	refresh();
}
