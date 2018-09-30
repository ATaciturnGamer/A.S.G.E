#include "Polygon2D.hpp"
#include "../../../Ascii_Render_System/AsciiRenderer.hpp"

#include <math.h>
float tim=0;


void Polygon2D::_update(int delta)
{
    
}

void Polygon2D::_draw()
{
    Point2D gl_pt;
    for (int i=0; i<n_pts; i++)
    {
        gl_pt = *v_points[i] + Point2D(x,y);
        if (i<n_pts-1)
        {
            AsciiRenderer::getInstance().renderLine(gl_pt,*(v_points[i+1])+Point2D(x,y),COLOR_PAIR(2));
        }
        else AsciiRenderer::getInstance().renderLine(gl_pt,*(v_points[0])+Point2D(x,y),COLOR_PAIR(2));
        // AsciiRenderer::getInstance().render(std::vector<int> {(int)gl_pt.x,(int)gl_pt.y}, "X", COLOR_PAIR(2));
    }
}

void Polygon2D::pushVertex(float x,float y)
{
    Point2D *pt = new Point2D(x,y);
    v_points.push_back(pt);
    n_pts++;
}



void Polygon2D::rotate(float rad)
{
    int i;
    float oldx;
    for (i=0;i<n_pts;i++)
    {
        oldx=(*v_points[i]).x;
        v_points[i]->x=v_points[i]->x*cos(rad) - v_points[i]->y*sin(rad);
        v_points[i]->y=v_points[i]->y*cos(rad) + oldx*sin(rad);
    }
}
