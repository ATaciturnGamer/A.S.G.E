#ifndef POLYGON2D_HPP
#define POLYGON2D_HPP

#include "../../Math.hpp"
#include "../GameObject.hpp"
#include <vector>

class Polygon2D : public GameObject
{
public:
    int n_pts;//No. of points
    std::vector<Point2D*> v_points;//Points in order
public:
    Polygon2D() : n_pts(0) {}
    ~Polygon2D() {}
    void pushVertex(float x,float y);
    void _update(int delta);
    void _draw();
    void rotate(float rad);
};

#endif
