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
			attrarr[i][j]=-1;
        }
    }
}

void AsciiRenderer::putSym(std::vector<int> pos, char sym, int attrs)
{
	frame[pos[1]][pos[0]]=sym;
	attrarr[pos[1]][pos[0]]=attrs;
}

void AsciiRenderer::renderLine(const Point2D pt1, const Point2D pt2, int attrs)
{
	float dx=(pt2.x-pt1.x);
	float dy=(pt2.y-pt1.y);
	float limit;
	if (abs(dx)>=abs(dy)) limit=abs(dx);
	else limit=abs(dy);
	dx=dx/limit;dy=dy/limit;
	int xdir,ydir;
	if (pt2.x>pt1.x) xdir=1; else xdir=-1;
	if (pt2.y>pt1.y) ydir=1; else ydir=-1;
	int i=1;
	float tx,ty;
	tx=pt1.x;ty=pt1.y;
	while (i<=limit)
	{
		if (((int)tx<100 && (int)tx>=0) && ((int)ty<25 && (int)ty>=0))
		{
			if (abs(dx)<1)
			{
				frame[(int)ty][(int)tx]='|';
			}
			else
			{
				if ((int)ty>(int)(ty+dy))// || (int)ty!=(int)(ty-dy))
				{
					if (xdir*ydir==1) frame[(int)ty][(int)tx]='\\';
					else  frame[(int)ty][(int)tx]='/';
				}
				else if ((int)ty>(int)(ty-dy))// || (int)ty!=(int)(ty-dy))
				{
					if (xdir*ydir==1) frame[(int)ty][(int)tx]='\\';
					frame[(int)ty][(int)tx]='/';
				}
				else frame[(int)ty][(int)tx]='_';
			}
			attrarr[(int)ty][(int)tx]=attrs;
		}
		tx=tx+dx;
		ty=ty+dy;
		i++;
	}
}

void AsciiRenderer::draw(WINDOW* win, int width, int height)
{
	for (int y = 0; y < height; ++y)
	{
        for (int x = 0; x < width; ++x)
		{
			if (attrarr[y][x]!=-1)
				wattron(win,attrarr[y][x]);
			mvwaddch(win,y, x, frame[y][x]);
			wattroff(win,attrarr[y][x]);
		}
	}
}
