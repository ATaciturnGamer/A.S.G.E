#include "../../A.S.G.E/include/Game.hpp"

class Water2D : public Polygon2D
{
private:
    int resolution;
    float surface[10];
    float sur_vel[10];
private:
    void applyHooke(int index, float delta);
    void splash(int index);

    void updateSpring(float delta);
    void updateSurface();
public:
    Water2D () {}
    Water2D (int w, int h);
    ~Water2D () {}
    void _update(int delta);
};
