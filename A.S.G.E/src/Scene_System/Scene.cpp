#include "Scene.hpp"

Scene::Scene()
{
    no_objects = 0;
}

void Scene::addObject(GameObject *obj)
{
    std::list<GameObject*>::const_iterator iter;
    for (iter = objectList.begin(); iter!=objectList.end(); iter++)
    {
        if ((*iter)->z>obj->z) break;
    }
    objectList.insert(iter,obj);
    no_objects++;
}
