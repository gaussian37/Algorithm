typedef struct Point{
    int x;
    int y;
}Point;

double GetPolygonArea(Point* points, int num_points){
        double ret = 0;
        int i, j;
        i = num_points - 1;
        for(j = 0; j < num_points; ++j){
            ret += points[i].x * points[j].y - points[j].x * points[i].y;
            i = j;
        }
        ret = ret < 0 ? -ret : ret;
        ret /= 2;

        return ret;
}