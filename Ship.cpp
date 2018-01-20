#include "Ship.hpp"

#include "A.S.G.E/src/Input_System/InputSystem.hpp"


Ship::Ship(std::string asc)
{
    setSprite(asc);
}

void Ship::_update(int delta)
{
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
