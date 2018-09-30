#include "Sprite2D.hpp"
#include "../../Ascii_Render_System/AsciiRenderer.hpp"

Sprite2D::Sprite2D()
{
    ascii_sprite=NULL;
}
Sprite2D::Sprite2D(std::string* asc)
{
    setSprite(asc);
}
Sprite2D::~Sprite2D()
{

}

void Sprite2D::setSprite(std::string* asc)
{
    ascii_sprite=asc;
}

std::string* Sprite2D::getSprite()
{
    return ascii_sprite;
}


void Sprite2D::_draw()
{
    int tx=(int)getPos()[0];
    int ty=(int)getPos()[1];
    // AsciiRenderer::getInstance().render(std::vector<int> {tx,ty}, *ascii_sprite, COLOR_PAIR(1));

    unsigned int ctr = 0;
    int i=tx;//X coord
    int j=ty;//Y coord
    char c = (*ascii_sprite)[ctr];
    while (j<0 && ctr<(*ascii_sprite).length())
    {
        while (c!='\n')
        {
            c=(*ascii_sprite)[++ctr];
        }
        c=(*ascii_sprite)[++ctr];
        j = j + 1;
    }
    while(ctr<(*ascii_sprite).length() and j<25)
    {
        if (i>=0 && i<100)
        {
            if (c!=' ' && c!='$')
            {
                AsciiRenderer::getInstance().putSym(std::vector<int>{i,j},c,COLOR_PAIR(1));
            }
            else if (c=='$')
            {
                AsciiRenderer::getInstance().putSym(std::vector<int>{i,j},' ',COLOR_PAIR(1));
            }
        }
        c=(*ascii_sprite)[++ctr];
        if (c=='\n')
        {
            if (i<100)
            {
                // frame[j][i]=' ';
            }
            i=tx;
            j++;
            c=(*ascii_sprite)[++ctr];
        }
        else i++;
    }
}
