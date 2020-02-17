#include <vector.h>

// 1차원 int형 벡터 구조체 초기화
// Initialize 1-dimensional int type vector struct
void ViInit(VI* vi){
    // col(size)를 0으로 맞추고 벡터(배열)을 0으로 초기화 한다.
    // set col(size) to 0 and initialize vector(array) to 0.
    vi->col = 0;
    memset(vi->vector, 0, sizeof(vi->vector));
}

// 1차원 int형 벡터의 마지막 인덱스에 값 추가
// add new value at the end of 1-dimensional vector
void ViPushBack(VI* vi, int val){    
    if(vi->col < MAX_COL){
        vi->vector[vi->col++] = val;
    }
    // 배열의 최대 범위를 초과하여 값을 추가하면 오류 발생
    // An error occurs, if you add a value beyond the maximum range of the array. 
    else{
        printf("ViPushBack : The index is out of range.\n");
        exit(1);
    }
}

// 1차원 int형 벡터의 마지막 값 제거
// Remove last value of 1-dimensional int vector
void ViPopBack(VI* vi){
    if(vi->col > 0){
        vi->vector[--vi->col] = 0;
    }
    // 값이 없을 때 호출되면 오류 발생
    // An error occurs, if this funcion is called with no value in the array.
    else{
        printf("ViPopBack : The index is out of range.\n");
        exit(1);
    }
}

// 1차원 int형 벡터 출력
// print 1-dimensional int vector (#col and values in the vector)
void ViPrint(VI* vi){
    int i;
    printf("#col : %d\n", vi->col);
    for(i = 0; i < vi->col; ++i){
        printf("%d ", vi->vector[i]);
    }
    printf("\n");
}


// 2차원 int형 벡터 구조체
// 2-dimensional int type vector struct
typedef struct VectorInt2d{
    // row는 vectors의 사이즈를 관리한다.
    // row manages size of vectors
    int row;
    VI vectors[MAX_ROW];
}VI2;

// 2차원 int형 벡터 구조체 초기화
// Initialize 2-dimensional int type vector struct
void Vi2Init(VI2* vi2){
    // row(size)를 0으로 맞추고 벡터들(배열들)을 0으로 초기화 한다.
    // set row(size) to 0 and initialize vectors(arrays) to 0.
    int i;
    vi2->row = 0;
    for(i = 0; i < MAX_ROW; ++i){
        ViInit(&vi2->vectors[i]);
    }
}

// 2차원 int형 벡터의 마지막 인덱스에 벡터 추가
// add new vector at the end of 2-dimensional vector
void Vi2PushBack(VI2* vi2, VI vi){
    if(vi2->row < MAX_ROW){
        vi2->vectors[vi2->row++] = vi;
    }
    // 배열의 최대 범위를 초과하여 값을 추가하면 오류 발생
    // An error occurs, if you add a value beyond the maximum range of the array.
    else{
        printf("Vi2PushBack : The index is out of range.\n");
        exit(1);
    }
}

// 2차원 int형 벡터의 마지막 벡터 제거
// Remove last vector of 2-dimensional int vector
void Vi2PopBack(VI2* vi2){
    if(vi2->row > 0){
        vi2->row--;
        memset(&vi2->vectors[vi2->row], 0, sizeof(&vi2->vectors[vi2->row]));
    }
    // 벡터가 없을 때 호출되면 오류 발생
    // An error occurs, if this funcion is called with no vector in the array.
    else{
        printf("Vi2PopBack : The index is out of range.\n");
        exit(1);
    }
}

// 2차원 int형 벡터 출력
// print 2-dimensional int vector (#rol, #col and values in each vector)
void Vi2Print(VI2* vi2){
    int i, j;
    printf("#row : %d\n", vi2->row);
    for(i = 0; i < vi2->row; ++i){
        printf("#col of %dth vector : %d\n", i, vi2->vectors[i].col);
        for(j = 0; j < vi2->vectors[i].col; ++j){
            printf("%d ",vi2->vectors[i].vector[j]);
        }
        printf("\n");
    }
}
