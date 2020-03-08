## Algorithm with naive C

<br>

- 이 리포지토리에 있는 알고리즘 코드들은 임베디드 환경에서 사용하기 위하여 동적 메모리 할당의 사용을 최소화 하였습니다.
- All codes in this repository minimize use of dynamic allocation in order to run in embedded environment.

<br>

## **data structure**

<br>

- [vector](https://github.com/gaussian37/algorithm/tree/master/naive_c_algorithm/data_structure/vector)
    - 1차원, 2차원의 int형, double형 벡터 구조체 (임베디드 환경을 위해 동적 할당 사용하지 않음)
    - 1-dimensional, 2-dimensional int or double type vector structure with no dynamic allocation for embedded environment

<br>

## **sort**

<br>

- [quick_sort.c](https://github.com/gaussian37/algorithm/blob/master/naive_c_algorithm/sort/quick_sort/quick_sort.c)
    - 퀵 소트가 평균적으로 매우 효율적인 알고리즘으로 알려져 있고 임베디드 환경에서 추가 배열 생성 및 동적 할당 발생하지 않으므로 적합함.
    - Quick sort is suitable, especially in the embedded environment, because it is known on average as a very efficient algorithm and does not cause additional array creation and dynamic allocation. 

<br>

## **geometry**

<br>

- [ccw.c](https://github.com/gaussian37/algorithm/blob/master/naive_c_algorithm/geometry/ccw.c)
    - 세 점의 위치 관계를(반시계 방향, 시계 방향, 동일선상)를 구하는 함수.
    - Function to find the positional relationship (counter clockwise, clockwise, collinear) of three points.
- [ccw_sort.c](https://github.com/gaussian37/Algorithm/blob/master/naive_c_algorithm/geometry/ccw_sort.c)
    - 점의 좌표들을 저장한 배열을 반시계 방향으로 정렬하는 함수
    - Function to sort an array containing coordinate of points by counter clockwise .
- [ccw_vector.c](https://github.com/gaussian37/algorithm/blob/master/naive_c_algorithm/geometry/ccw_vector.c)
    - 두 벡터의 위치 관계를(반시계 방향, 시계 방향, 동일선상)를 구하는 함수.
    - Function to find the positional relationship (counter clockwise, clockwise, collinear) of two vectors.
- [line_intersect.c](https://github.com/gaussian37/algorithm/blob/master/naive_c_algorithm/geometry/line_intersect.c)
    - 두 선분이 교차하는 지 구하는 함수
    - Function to Find if Two Lines Intersect
- [intersection_point.c]()
    - 두 선분의 교차점을 구하는 함수
    - Function to get intersection point of two lines.
- [polygon_area.c](https://github.com/gaussian37/algorithm/blob/master/naive_c_algorithm/geometry/polygon_area.c)
    - n차원 다각형의 넓이를 구하는 함수 (단, 다각형 내부에서 교차하는 점이나 twist된 부분이 있으면 적용 불가함).
    - This function gets n-dimensional polygon area (Not applicable if there are intersections or twisted parts inside the polygon).
- [polygon_inout.c](https://github.com/gaussian37/algorithm/blob/master/naive_c_algorithm/geometry/polygon_inout.c)
    - 어떤 점이 다각형의 내부에 있는 지 외부에 있는 지 판단하는 함수
    - Function to determine which point is inside or outside the polygon
- [rectangle_iou.c](https://github.com/gaussian37/Algorithm/blob/master/naive_c_algorithm/geometry/rectangle_iou.c)
    - 두 직사각형의 (x최소값, y최소값), (x최대값, y최대값) 좌표를 이용하여 IoU를 계산하는 함수
    - Function to calculate IoU using (min value of x, min value of y), (max valud of x, max valud of y) of two rectangles.