typedef struct Point{
    int x;
    int y;
}Point;

long long dist(const Point* p1, const Point* p2){
    return (long long)(p1->x - p2->x)*(p1->x - p2->x) + (long long)(p1->y - p2->y)*(p1->y - p2->y);
}

int ccw(const Point* p1, const Point* p2, const Point* p3){
    
    int cross_product = (p2->x - p1->x)*(p3->y - p1->y) - (p3->x - p1->x)*(p2->y - p1->y);

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

// right가 left의 반시계 방향에 있으면 true이다.
// true if right is counterclockwise to left.
Point p;
int comparator(const Point* left, const Point* right){
    int ret;
    int direction = ccw(&p, left, right);
    if(direction == 0){        
        ret = (dist(&p, left) < dist(&p, right));
    }
    else if(direction == 1){
        ret = 1;
    }
    else{
        ret = 0;
    }
    return ret;
}

/*
퀵정렬 함수의 입력 값은 배열, 탐색 시작 위치, 탐색 끝 위치이며 시작 위치와 끝 위치는 실제 값을 포함하는 위치입니다.
The input values for the QuickSort function are Array, Search Start Position, Search End Position, and Start Position and End Position are positions that contain the actual values.
*/
void QuickSort(Point* a, int lo, int hi){
    if(hi - lo <= 0){
        return;
    }

    // 현재 배열 범위의 중앙값을 피벗으로 선택한다.
    // Select the median as pivot in the current array range.
    Point pivot = a[lo + (hi-lo+1)/2];
    int i = lo, j = hi;

    // 정복 과정
    // Conquer process
    while(i <= j){
        // 피벗의 왼쪽에는 comparator(타겟, "피벗")을 만족하지 않는 인덱스를 선택 (i)
        // On the left side of the pivot, select an index that doesn't satisfy the comparator(target, "pivot"). (i)
        while(comparator(&a[i], &pivot)) i++;
        
        // 피벗의 오른쪽에는 comparator("피벗", 타겟)을 만족하지 않는 인덱스를 선택 (j)
        // On the right side of the pivot, select an index that doesn't satisfy the comparator("pivot", target). (j)
        while(comparator(&pivot, &a[j])) j--;
        // (i > j) 피벗의 왼쪽에는 모든 값이 피벗보다 작고 피벗의 오른쪽에는 모든 값이 피벗보다 큰 상태가 되었음.
        // (i > j) On the left side of the pivot, all values are smaller than the pivot, and on the right side of the pivot, all values are larger than the pivot.
        if(i > j){
            break;
        }

        // i번째 값은 피벗 보다 크고 j번째 값은 피벗보다 작으므로 두 값을 스왑한다.
        // The i-th value is larger than the pivot and the j-th value is smaller than the pivot, so swap the two values.
        Point temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        // 인덱스 i를 1증가 시키고 인덱스 j를 1 감소 시켜서 탐색 범위를 안쪽으로 좁힌다.
        // Narrow the search inward by increasing index i by one and decreasing index j by one.
        i++;
        j--;
    }

    // 분할 과정
    // Divide process
    QuickSort(a, lo, j);
    QuickSort(a, i, hi);
}