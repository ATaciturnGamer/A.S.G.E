#include "A.S.G.E/src/Entity/Sprite/Sprite2D.hpp"

class Ship : public Sprite2D
{
public:
    bool testIsMove;
    Ship();
    ~Ship() {}
    Ship(std::string* asc);
    void _update(int delta);
private:
    int size;
    int cells[2];
};
