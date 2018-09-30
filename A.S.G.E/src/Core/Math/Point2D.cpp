#include "Point2D.hpp"

Point2D Point2D::operator+(const Point2D& rhs)
{
    Point2D pt(this->x+rhs.x,this->y+rhs.y);
    return pt;
}

Point2D Point2D::operator-(const Point2D& rhs)
{
    Point2D pt(this->x-rhs.x,this->y-rhs.y);
    return pt;
}
