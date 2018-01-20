#include "A.S.G.E/src/Core/GameObject.hpp"

class Ship : public GameObject
{
public:
    Ship() {}
    ~Ship() {}
    Ship(std::string asc);
    void _update(int delta);
private:
    int size;
    int cells[2];
};
