#ifndef POINT2D_HP
#define POINT2D_HP
class Point2D {
public:
    float x;
    float y;

public:
    Point2D () : x(0), y(0) {};
    Point2D (float xi, float yi) : x(xi), y(yi) {}
    ~Point2D () {}

    Point2D operator+(const Point2D& rhs);
    Point2D operator-(const Point2D& rhs);
};
#endif
