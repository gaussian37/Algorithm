/*
- input : p1 = (x1, y1), p2 = (x2, y2), p3 = (x3, y2)
- output : 1 (counter clockwise), 0 (collinear), -1 (clockwise)
※ vector v1 = (p2 - p1), vector v2 = (p3 - p1) 
*/
int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    int cross_product = (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);

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