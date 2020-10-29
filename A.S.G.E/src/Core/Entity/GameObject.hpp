#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <string>

class GameObject
{
public:
    float x;
    float y;
    int z;

public:
    GameObject() : x(0), y(0), z(0) {}
    virtual ~GameObject() {}

    void setPos(float x, float y);
    void setPos(float x, float y, int z);
    std::vector<float> getPos();

    void setZOrder(int z);
    int getZOrder();

    virtual void _update(int delta) = 0;
    virtual void _draw();

};

#endif
