/*
오름차순 시 left < right가 true이고 내림차순 시 left > right가 true이다.
Left < right is ture in ascending order and left > right is true in descending order.
*/
int comparator(int left, int right){
    int ret;
    if (left < right){
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
void QuickSort(int* a, int lo, int hi){
    if(hi - lo <= 0){
        return;
    }

    // 현재 배열 범위의 중앙값을 피벗으로 선택한다.
    // Select the median as pivot in the current array range.
    int pivot = a[lo + (hi-lo+1)/2];
    int i = lo, j = hi;

    // 정복 과정
    // Conquer process
    while(i <= j){
        // 피벗의 왼쪽에는 comparator(타겟, "피벗")을 만족하지 않는 인덱스를 선택 (i)
        // On the left side of the pivot, select an index that doesn't satisfy the comparator(target, "pivot"). (i)
        while(comparator(a[i], pivot)) i++;
        // 피벗의 오른쪽에는 comparator("피벗", 타겟)을 만족하지 않는 인덱스를 선택 (j)
        // On the right side of the pivot, select an index that doesn't satisfy the comparator("pivot", target). (j)
        while(comparator(pivot, a[j])) j--;

        // (i > j) 피벗의 왼쪽에는 모든 값이 피벗보다 작고 피벗의 오른쪽에는 모든 값이 피벗보다 큰 상태가 되었음.
        // (i > j) On the left side of the pivot, all values are smaller than the pivot, and on the right side of the pivot, all values are larger than the pivot.
        if(i > j){
            break;
        }

        // i번째 값은 피벗 보다 크고 j번째 값은 피벗보다 작으므로 두 값을 스왑한다.
        // The i-th value is larger than the pivot and the j-th value is smaller than the pivot, so swap the two values.
        int temp = a[i];
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