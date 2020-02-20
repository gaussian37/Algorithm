#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROW 100
#define MAX_COL 100

// 1차원 int형 벡터 구조체
// 1-dimensional int type vector struct
typedef struct VectorInt1d{
    // col은 vector의 사이즈를 관리한다.
    // col manages size of vector
    int col;
    int vector[MAX_COL];
}VI;

// 1차원 int형 벡터 구조체 초기화
// Initialize 1-dimensional int type vector struct
void ViInit(VI* vi);

// 1차원 int형 벡터의 마지막 인덱스에 값 추가
// add new value at the end of 1-dimensional vector
void ViPushBack(VI* vi, int val);

// 1차원 int형 벡터의 마지막 값 제거
// Remove last value of 1-dimensional int vector
void ViPopBack(VI* vi);

// 1차원 int형 벡터 출력
// print 1-dimensional int vector (#col and values in the vector)
void ViPrint(VI* vi);



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
void Vi2Init(VI2* vi2);

// 2차원 int형 벡터의 마지막 인덱스에 벡터 추가
// add new vector at the end of 2-dimensional vector
void Vi2PushBack(VI2* vi2, VI vi);

// 2차원 int형 벡터의 마지막 벡터 제거
// Remove last vector of 2-dimensional int vector
void Vi2PopBack(VI2* vi2);

// 2차원 int형 벡터 출력
// print 2-dimensional int vector (#rol, #col and values in each vector)
void Vi2Print(VI2* vi2);





// 1차원 double형 벡터 구조체
// 1-dimensional double type vector struct
typedef struct VectorDouble1d{
    // col은 vector의 사이즈를 관리한다.
    // col manages size of vector
    int col;
    double vector[MAX_COL];
}VD;

// 1차원 double형 벡터 구조체 초기화
// Initialize 1-dimensional double type vector struct
void VdInit(VD* vd);

// 1차원 double형 벡터의 마지막 인덱스에 값 추가
// add new value at the end of 1-dimensional vector
void VdPushBack(VD* vd, double val);

// 1차원 double형 벡터의 마지막 값 제거
// Remove last value of 1-dimensional double vector
void VdPopBack(VD* vd);

// 1차원 double형 벡터 출력
// print 1-dimensional double vector (#col and values in the vector)
void VdPrint(VD* vd);




// 2차원 double형 벡터 구조체
// 2-dimensional double type vector struct
typedef struct VectorInt2d{
    // row는 vectors의 사이즈를 관리한다.
    // row manages size of vectors
    int row;
    VD vectors[MAX_ROW];
}VD2;

// 2차원 double형 벡터 구조체 초기화
// Initialize 2-dimensional double type vector struct
void Vd2Init(VD2* vd2);

// 2차원 double형 벡터의 마지막 인덱스에 벡터 추가
// add new vector at the end of 2-dimensional vector
void Vd2PushBack(VD2* vd2, VD vd);

// 2차원 double형 벡터의 마지막 벡터 제거
// Remove last vector of 2-dimensional double vector
void Vd2PopBack(VD2* vd2);

// 2차원 double형 벡터 출력
// print 2-dimensional double vector (#rol, #col and values in each vector)
void Vd2Print(VD2* vd2);