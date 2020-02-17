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

## **geometry**

<br>

- [polygon_area.c](https://github.com/gaussian37/algorithm/blob/master/naive_c_algorithm/geometry/polygon_area.c)
    - n차원 다각형의 넓이를 구하는 함수 (단, 다각형 내부에서 교차하는 점이나 twist된 부분이 있으면 적용 불가함).
    - This function gets n-dimensional polygon area (Not applicable if there are intersections or twisted parts inside the polygon).
- [ccw.c](https://github.com/gaussian37/algorithm/blob/master/naive_c_algorithm/geometry/ccw.c)
    - 세 점 또는 두 벡터의 위치 관계 (반시계 방향, 시계 방향, 동일선상)를 구하는 함수.
    - Function to find the positional relationship (counter clockwise, clockwise, collinear) of three points or two vectors.
