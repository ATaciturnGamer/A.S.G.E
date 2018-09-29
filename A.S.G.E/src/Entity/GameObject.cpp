#include "GameObject.hpp"
#include "../Ascii_Render_System/AsciiRenderer.hpp"


void GameObject::_draw()
{
    printf("!!dfdfdgege!!");
    //AsciiRenderer::getInstance().render(std::vector<int> {(int)x,(int)y}, ascii_sprite, COLOR_PAIR(1));
}


void GameObject::setPos(float x, float y)
{
    this->x = x;
    this->y = y;
}
void GameObject::setPos(float x, float y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

std::vector<float> GameObject::getPos()
{
    std::vector<float> r(2);
    r[0]=x;
    r[1]=y;
    return r;
}


void GameObject::setZOrder(int z)
{
    this->z = z;
}
int GameObject::getZOrder()
{
    return z;
}
