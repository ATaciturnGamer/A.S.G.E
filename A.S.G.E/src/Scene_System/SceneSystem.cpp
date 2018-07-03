#include "SceneSystem.hpp"

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

void SceneSystem::loadScene(char* file)
{
    Scene *tmp = new Scene();
    delete currentScene;
    currentScene = tmp;
}
