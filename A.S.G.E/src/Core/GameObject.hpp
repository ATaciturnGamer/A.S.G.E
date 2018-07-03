#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <string>

class GameObject
{
private:
    std::string ascii_sprite;
public:
    float x;
    float y;
    int z;

    GameObject() : x(0), y(0), z(0) {}
    ~GameObject() {}

    void setPos(float x, float y);
    void setPos(float x, float y, int z);
    std::vector<float> getPos();

    void setZOrder(int z);
    int getZOrder();

    void setSprite(std::string asc);

    virtual void _update(int delta) = 0;
    void _draw();

};

#endif
