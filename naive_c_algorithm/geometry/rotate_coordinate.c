#include <math.h>

typedef struct _Point{
    double x;
    double y;
} Point;

// 점 p를 점 base를 기준으로 theta 만큼 회전 한다.
// Rotate point p by theta relative to point base.
Point RotateCoordinate(Point p, double theta, Point base){
    Point ret;

    ret.x = (p.x - base.x)*cos(theta*M_PI/180) - (p.y - base.y)*sin(theta*M_PI/180) + base.x;

    ret.y = (p.x - base.x)*sin(theta*M_PI/180) + (p.y - base.y)*cos(theta*M_PI/180) + base.y;

    return ret;
}