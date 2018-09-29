#include "Scene.hpp"

class SceneSystem
{
private:
    Scene *currentScene;
public:
    SceneSystem(){}
    ~SceneSystem(){}

    void _startUp();
    void _shutDown();

    static SceneSystem& getInstance();

    Scene* getScene();

    void loadScene(int scene_num);
};
