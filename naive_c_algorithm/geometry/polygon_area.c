double GetPolygonArea(int* x_points, int* y_points, int num_points) {
	// https://gaussian37.github.io/math-algorithm-polygon_area/
	double ret = 0;
	int i, j;
	i = num_points - 1;
	for (j = 0; j < num_points; ++j) {
		ret += x_points[i] * y_points[j] - x_points[j] * y_points[i];
		i = j;
	}
	ret = ret < 0 ? -ret : ret;
	ret /= 2;

	return ret;
}