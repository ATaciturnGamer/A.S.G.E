#include "Ship.hpp"

#include "A.S.G.E/include/Game.hpp"

Ship::Ship() : Sprite2D()
{
    testIsMove=false;
}

Ship::Ship(std::string* asc) : Sprite2D(asc)
{
    testIsMove=false;
}

void Ship::_update(int delta)
{
    if (testIsMove==false) return;
    if (InputSystem::getInstance().isKeyPressed(KEY_RIGHT))
    {
        x = x + 30*(delta/1000.0);
    }
    else if (InputSystem::getInstance().isKeyPressed(KEY_DOWN))
    {
         y = y + 30*(delta/1000.0);
    }
    else if (InputSystem::getInstance().isKeyPressed(KEY_UP))
    {
         y = y - 30*(delta/1000.0);
    }
    else if (InputSystem::getInstance().isKeyPressed(KEY_LEFT))
    {
        x = x - 30*(delta/1000.0);
    }
}
