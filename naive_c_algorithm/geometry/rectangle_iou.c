#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

/*
- Rectangle A : (min_x1, min_y1), (max_x1, max_y1)
- Rectangle B : (min_x2, min_y2), (max_x2, max_y2)
- Intersection : A ∩ B
- Union : A + B - A ∩ B
- IoU : (A ∩ B) / (A + B - A ∩ B)
*/
double RectangleIoU(int min_x1, int min_y1, int max_x1, int max_y1, int min_x2, int min_y2, int max_x2, int max_y2) {

	double ret;
	double rect1_area, rect2_area;
	double intersection_x_length, intersection_y_length;
	double intersection_area;
	double union_area;

    // 직사각형 A, B의 넓이를 구한다.
    // get area of rectangle A and B
	rect1_area = (max_x1 - min_x1) * (max_y1 - min_y1);
	rect2_area = (max_x2 - min_x2) * (max_y2 - min_y2);

    // Intersection의 가로와 세로 길이를 구한다.
    // get length and width of intersection.
	intersection_x_length = MIN(max_x1, max_x2) - MAX(min_x1, min_x2);
	intersection_y_length = MIN(max_y1, max_y2) - MAX(min_y1, min_y2);

    // width와 length의 길이가 유효하다면 IoU를 구한다.
    // If the width and length are valid, get IoU.
	if (intersection_x_length > 0 && intersection_y_length > 0) {
		intersection_area = intersection_x_length * intersection_y_length;
		union_area = rect1_area + rect2_area - intersection_area;
        ret = intersection_area / union_area;
	}
	else {
		ret = 0;
	}
	return ret;
}
