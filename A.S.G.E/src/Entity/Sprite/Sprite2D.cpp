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
    AsciiRenderer::getInstance().render(std::vector<int> {tx,ty}, *ascii_sprite, COLOR_PAIR(1));
}
