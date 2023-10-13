#include "Point.hpp"

Fixed sign (Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const pt)
{
    bool b1, b2, b3;
 
    b1 = sign(pt, a, b) < 0;
    b2 = sign(pt, b, c) < 0;
    b3 = sign(pt, c, a) < 0;
 
    return ((b1 == b2) && (b2 == b3));
}