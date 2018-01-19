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
            frame[i][j]='~';
			attrarr[i][j]=-1;
        }
    }
}

void AsciiRenderer::render(std::vector<int> pos, std::string obj, int attrs, WINDOW* log)
{
    unsigned int ctr = 0;
    int i=pos[0];//X coord
    int j=pos[1];//Y coord
	int k = -j;
    char c = obj[ctr];
	mvwprintw(log,2,1," %d ",j);
	while (j<0 && ctr<obj.length())
	{
		while (c!='\n')
		{
			c=obj[++ctr];
		}
		c=obj[++ctr];
		j = j + 1;
		mvwprintw(log,3,j+1+k,"%d",ctr);
	}
    while(ctr<obj.length() and j<25)
    {
        if (i>=0 && i<100)
        {
            frame[j][i]=c;
			attrarr[j][i]=attrs;
        }
        c=obj[++ctr];
		i++;
        if (c=='\n')
        {
            i=pos[0];
            j++;
	        c=obj[++ctr];
        }
    }
}

void AsciiRenderer::draw(WINDOW* win, int width, int height)
{
	for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
			if (attrarr[y][x]!=-1)
				wattron(win,attrarr[y][x]);
			mvwaddch(win,y, x, frame[y][x]);
			wattroff(win,attrarr[y][x]);
		}
	}
}
