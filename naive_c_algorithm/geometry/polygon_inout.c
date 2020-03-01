#include <stdio.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct Point{
    int x;
    int y;
}Point;

typedef struct Line{
    Point p1;
    Point p2;
}Line;

/*
- input : p1 = (p1.x, p1.y), p2 = (p2.x, p2.y), p3 = (p3.x, p3.y)
- output : 1 (counter clockwise), 0 (collinear), -1 (clockwise)
※ vector v1 = (p2 - p1), vector v2 = (p3 - p1)       
*/
int ccw(Point p1, Point p2, Point p3){
    int cross_product = (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);

    if (cross_product > 0){
        return 1;
    }
    else if (cross_product < 0){
        return -1;
    }
    else{
        return 0;
    }
}

// right가 left 보다 크면 true를 반환합니다.
// if right is greater than left, it is true
int comparator(Point left, Point right){
    int ret;
    if(left.x == right.x){
        ret = (left.y <= right.y);
    }
    else{
        ret = (left.x <= right.x);
    }
    return ret;
}

// 입력받은 Point 구조체의 값을 교환합니다.
// Exchanges the value of the input Point structure.
void swap(Point* p1, Point* p2){
    Point temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// 두 선분이 교차하면 1을 교차하지 않으면 0을 반환합니다.
// If the two segments intersect, they will return 1 if they do not intersect 0.
int LineIntersection(Line l1, Line l2){
    int ret;
    // l1을 기준으로 l2가 교차하는 지 확인한다.
    // Check if l2 intersects based on l1.
    int l1_l2 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    // l2를 기준으로 l1이 교차하는 지 확인한다.
    // Check if l1 intersects based on l2.
    int l2_l1 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);


    // l1 과 l2가 일직선 상에 있는 경우
    // l1 and l2 are in same line.
    if(l1_l2 == 0 && l2_l1 == 0){
        // Line1의 점의 크기 순서를 p1 < p2 순서로 맞춘다.
        // Set the order of the points on Line1 in the order p1 < p2.
        if(comparator(l1.p2, l1.p1)) swap(&l1.p1, &l1.p2);
        // Line2의 점의 크기 순서를 p1 < p2 순서로 맞춘다.
        // Set the order of the points on Line2 in the order p1 < p2.
        if(comparator(l2.p2, l2.p1)) swap(&l2.p1, &l2.p2);

        // l1.p1 -----------l1.p2
        //         l2.p1 -----------l2.p2
        // 위 조건을 만족하는 지 살펴본다.
        // See if the above conditions are met.
        ret = (comparator(l2.p1, l1.p2)) && (comparator(l1.p1, l2.p2));
    }
    // l1과 l2가 일직선 상에 있지 않는 경우
    // l1 and l2 are not in same line.
    else{
        ret = (l1_l2 <= 0) && (l2_l1 <= 0);
    }
    return ret;
}

int PolygonInOut(Point p, int num_vertex, Point* vertices){

    int ret = 0;

    // 마지막 꼭지점과 첫번째 꼭지점이 연결되어 있지 않다면 오류를 반환한다.
    // If the last vertex and the first vertex are not connected, an error is returned.
    if (vertices[0].x != vertices[num_vertex].x || vertices[0].y != vertices[num_vertex].y){
        printf("Last vertex and first vertex are not connected.")
        return -1;
    }

    for(int i = 0; i < num_vertex; ++i){
        
        // 점 p가 i번째 꼭지점과 i+1번째 꼭지점을 이은 선분 위에 있는 경우
        // If point p is on the line connecting the i and i + 1 vertices
        if( ccw(vertices[i], vertices[i+1], p) == 0 ){
            int min_x = MIN(vertices[i].x, vertices[i+1].x);
            int max_x = MAX(vertices[i].x, vertices[i+1].x);
            int min_y = MIN(vertices[i].y, vertices[i+1].y);
            int max_y = MAX(vertices[i].y, vertices[i+1].y);

            // 점 p가 선분 내부의 범위에 있는 지 확인
            // Determine if point p is in range within line segment
            if(min_x <= p.x && p.x <= max_x && min_y <= p.y && p.y <= max_y){
                return 1;
            }
        }
        else{;}
    }

    // 다각형 외부에 임의의 점과 점 p를 연결한 선분을 만든다.
    // Create a line segment connecting a random point outside the polygon and point p.
    Point outside_point;
    outside_point.x = 1; outside_point.y = 1234567;
    Line l1;
    l1.p1 = outside_point;
    l1.p2 = p;

    // 앞에서 만든 선분과 다각형을 이루는 선분들이 교차되는 갯수가 센다.
    // Count the number of intersections between the previously created line segments and the polygonal segments.
    for(int i = 0; i < num_vertex; ++i){
        Line l2;
        l2.p1 = vertices[i];
        l2.p2 = vertices[i+1];
        ret += LineIntersection(l1, l2);
    }

    // 교차한 갯수가 짝수인지 홀수인지 확인한다.
    // Check if the number of crossings is even or odd.
    ret = ret % 2;
    return ret;
}