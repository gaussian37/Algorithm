typedef struct Point{
    double x;
    double y;
}Point;

// (p1, p2)를 이은 직선과 (p3, p4)를 이은 직선의 교차점을 구하는 함수
// Function to get intersection point with line connecting points (p1, p2) and another line (p3, p4).
Point IntersectionPoint1(const Point* p1, const Point* p2, const Point* p3, const Point* p4){

    Point ret;

    ret.x = ((p1->x*p2->y - p1->y*p2->x)*(p3->x - p4->x) - (p1->x - p2->x)*(p3->x*p4->y - p3->y*p4->x))/( (p1->x - p2->x)*(p3->y - p4->y) - (p1->y - p2->y)*(p3->x - p4->x) );

    ret.y = ((p1->x*p2->y - p1->y*p2->x)*(p3->y - p4->y) - (p1->y - p2->y)*(p3->x*p4->y - p3->y*p4->x)) / ( (p1->x - p2->x)*(p3->y - p4->y) - (p1->y - p2->y)*(p3->x - p4->x) );

    return ret;
}

// y = m1*x + b1, y = m2*x + b2 두 직선의 교차점을 구하는 함수
// Function to get intersection point of two lines y = m1*x + b1, y = m2*x + b2
Point IntersectionPoint2(double m1, double b1, double m2, double b2){
    
    Point ret;

    ret.x = (b2 - b1) / (m1 - m2);
    ret.y = m1*(b2 - b1)/(m1 - m2) + b1;    

    return ret;
}

// a1*x + b1*y + c1 = 0, a2*x + b2*y + c2 = 0 두 직선의 교차점을 구하는 함수
// Function to get intersection point of two lines a1*x + b1*y + c1 = 0, a2*x + b2*y + c2 = 0
Point IntersectionPoint3(double a1, double b1, double c1, double a2, double b2, double c2){

    Point ret;

    ret.x = (b1*c2 - b2*c1)/(a1*b2 - a2*b1);
    ret.y = -a1/b1*(b1*c2-b2*c1)/(a1*b2-a2*b1)-c1/b1;

    return ret;
}