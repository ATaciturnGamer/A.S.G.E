#include <list>
#include <vector>
#include "../Core/GameObject.hpp"

struct zCompare
{
    bool operator() (GameObject *l, GameObject *r)
    {
        return (l->z<r->z);
    }
};

class Scene
{
public:
    std::list<GameObject*> objectList;
    int no_objects;
public:
    Scene();
    void addObject(GameObject *obj);
};
