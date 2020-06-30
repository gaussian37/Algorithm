/*
- 모든 코드는 gaussian37에 의하여 작성되었음.
  (All codes are written by gaussian37.)
- 임베디드 환경에서 사용될 목적으로 작성되어 모든 코드에 동적 메모리 할당은 최소화 하였음.
  (All codes have minimum dynamic memory allocation because those are created for using embedded environment.)
*/

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <math.h>

#define MAX_ROW			(5)
#define MAX_COL			(5)
#define EPS				(0.000000001)

// 2차원 Matrix (2-dimensional Matrix)
typedef struct _Matrix{

	double matrix[MAX_ROW][MAX_COL];
	int row;
	int col;

}Matrix;

// 열 벡터 (Column Vector)
typedef struct _Vector{

	double vector[MAX_ROW];
	int row;

}Vector;

// Matrix와 Vector 한 쌍 (One pair of Matrix and Vector)
typedef struct _MatrixVector{

	Matrix Matrix;
	Vector Vector;

}MatrixVector;

// 특이값 분해 (Singular Value Decomposition)
typedef struct _Svd{
	Matrix U;
	Matrix Sigma;
	Matrix V;
}Svd;

// 입력 받은 스칼라 값의 역수를 취한다. (divided by zero 처리함)
// Take the inverse of the input scalar value. (processed divided by zero)
double Reciprocal(double a);

// matrix를 복사한다.
// copy the matrix
void CloneMatrix(const Matrix* input, Matrix* output);

// vector를 복사한다.
// copy the vector
void CloneVector(const Vector *input, Vector *output);

// 두 matrix를 곱한다.
// multiply two matrices
Matrix MatrixByMatrix(const Matrix* mat1, const Matrix* mat2);

// matrix와 vector를 곱한다.
// multiply matrix by vector
Vector MatrixByVector(const Matrix* mat, const Vector* vec);

// 입력 받은 길이의 항등행렬을 반환한다.
// Return the identity matrix of the input length.
Matrix Identity(int len);

// matrix의 각 값에 scalar 값을 곱합니다.
// Multiply each value in the matrix by the scalar value.
Matrix ScalarByMatrix(double scalar, const Matrix* mat);

// vector의 각 값에 scalar 값을 곱합니다.
// Multiply each value in the vector by the scalar value.
Vector ScalarByVector(double scalar, const Vector* vec);

// matrix와 matrix를 더합니다.
// add matrix and matrix
Matrix MatrixPlusMatrix(const Matrix* mat1, const Matrix* mat2);

// matrix와 matrix를 뺍니다.
// subtract matrix and matrix.
Matrix MatrixMinusMatrix(const Matrix* mat1, const Matrix* mat2);

// vector와 vector를 더합니다.
// add vector and vector
Vector VectorPlusVector(const Vector* vec1, const Vector* vec2);

// vector와 vector를 뺍니다.
// subtract vector and vector
Vector VectorMinusVector(const Vector* vec1, const Vector* vec2);

// matrix를 transpose 합니다.
// transpose the matrix
Matrix Transpose(const Matrix* mat);

// matrix의 모든 값을 역수를 취합니다. (divide by zero 조치함)
// Take the inverse of all values in the matrix. (take action by divide by zero)
Matrix MatrixReciprocal(const Matrix* mat);

// vector의 모든 값을 역수를 취합니다. (divide by zero 조치함)
// Take the inverse of all values of vector. (take action by divide by zero)
Vector VectorReciprocal(Vector vec);

// 모든 값이 0인 (row, col) 크기의 matrix를 만듭니다.
// Create a matrix of size (row, col) with all values equal to zero.
Matrix Zeros(int row, int col);

// 모든 값이 1인 (row, col) 크기의 matrix를 만듭니다.
// Create a matrix of size (row, col) with all values equal to 1.
Matrix Ones(int row, int col);

// matrix의 eigenvector와 eigenvalue를 구합니다. Matrix에 eigenvector가, Vector에 eigenvalue가 저장됩니다.
// find the eigenvector and eigenvalue of the matrix. The eigenvector is stored in the Matrix and the eigenvalue is stored in the Vector.
MatrixVector Eigen(const Matrix* mat);

// matrix를 U, Sigma, V 순으로 특이값 분해 합니다.
// Solve the singular values of the matrix in the order U, Sigma, and V.
Svd SingularValueDecomposition(const Matrix* mat);

// matrix의 역행렬을 구합니다. 역행렬 값이 없을 때에는 pseudo inverse로 구합니다.
// Find the inverse of matrix. If there is no inverse, the pseudo inverse is obtained.
Matrix Inverse(const Matrix* mat);

// matrix를 출력합니다.
// print the matrix.
void PrintMatrix(const Matrix* mat);

// vector를 출력합니다.
// print the vector
void PrintVector(const Vector* vec);

// print matrix shape.
void PrintMatrixShape(const Matrix *input);

// print vector shape.
void PrintVectorShape(const Vector *input);

#endif