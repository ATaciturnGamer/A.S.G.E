#include "SceneSystem.hpp"

#include <typeinfo>


#include "../Window_System/WindowSystem.hpp"//LOG purposes only

void SceneSystem::_startUp()
{
    currentScene = new Scene();
}

SceneSystem& SceneSystem::getInstance()
{
    static SceneSystem *instance = new SceneSystem();
    return *instance;
}

Scene* SceneSystem::getScene()
{
    return currentScene;
}
void SceneSystem::loadScene(int n)
{
    Scene *tmp = new Scene();
    delete currentScene;
    currentScene = tmp;
}
