typedef struct Vector{
    int x_begin;
    int y_begin;
    int x_end;
    int y_end;
} Vector;

void InitVector(Vector* v, int x_begin, int y_begin, int x_end, int y_end){
    v->x_begin = x_begin;
    v->y_begin = y_begin;
    v->x_end = x_end;
    v->y_end = y_end;
}

/*
- input : Vector v1, Vector v2
- output : Direction from vector v1 to v2 
    - 1 (counter clockwise), 0 (collinear), -1 (clockwise)
*/
int ccw(Vector v1, Vector v2){
    
    int cross_product = (v1.x_end - v1.x_begin)*(v2.y_end - v1.y_begin) - (v2.x_end - v1.x_begin)*(v1.y_end - v1.y_begin);

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