#include "Water2D.hpp"
#include <math.h>
namespace WaterGlobals {
    long int time = 0;
    const float k = 0.30;
    const float damp = 0.08;
    const float spread = 0.01;
} /* WaterGlobals */
Water2D::Water2D(int width, int height) : Polygon2D()
{
    resolution=10;
    setPos(1.0,25-height);
    pushVertex(0.0,0.0);

    for (int i=1; i<(10-1); i++)
    {
        pushVertex((width/10)*i,0);
    }

    pushVertex(width,0.0);
    pushVertex(width,height);
    pushVertex(0.0,height);

    for (int i=0; i<10; i++)
    {
        surface[i]=0;
    }
}

void Water2D::updateSpring(float delta)
{
    for (int i=0; i<10; i++)
    {
        surface[i]+=sur_vel[i]*delta*0.01;
    }
}

void Water2D::updateSurface()
{
    for (int i=0; i<10; i++)
    {
        v_points[i]->y=surface[i];
    }
}

void Water2D::splash(int index)
{
    if (index<0 || index>=resolution) return;
    sur_vel[index]+=7;
}

void Water2D::applyHooke(int index, float delta)
{
    float x = (surface[index]);
    float accel = -WaterGlobals::k*x - WaterGlobals::damp*sur_vel[index];
    sur_vel[index]+=accel*delta*0.01;
}

void Water2D::_update(int delta)
{
    WaterGlobals::time +=delta;

    //Static WAVES
    // for (int i=0; i<10; i++)
    // {
    //     surface[i]=cos(0.002*WaterGlobals::time+i*0.3)*4;
    // }

    //Dynamic WAVES

    //Hooke's law
    for (int i=0; i<resolution; i++)
    {
        applyHooke(i,delta);
    }
    //Wave physics
    float l_delta[10];
    float r_delta[10];

    for (int i=0;i<10;i++)
    {
        for (int j=0;j<resolution;j++)
        {
            if (j>0)
            {
                l_delta[j]=WaterGlobals::spread*(surface[j]-surface[j-1]);
                sur_vel[j-1]+=l_delta[j];
            }
            if (j<resolution-1)
            {
                r_delta[j]=WaterGlobals::spread*(surface[j]-surface[j+1]);
                sur_vel[j+1]+=r_delta[j];
            }
        }

    }

    if (InputSystem::getInstance().isKeyPressed(' '))
    {
        splash(5);
    }

    updateSpring(delta);

    updateSurface();
}
