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