#ifndef SPRITE2D_HPP
#define SPRITE2D_HPP

#include "../GameObject.hpp"

#include <string>

class Sprite2D : public GameObject
{
private:
    std::string *ascii_sprite;

public:
    Sprite2D ();
    Sprite2D (std::string* sp);
    ~Sprite2D ();


    void setSprite(std::string* asc);
    std::string* getSprite();

    //void _update();
    void _draw();
};
#endif
