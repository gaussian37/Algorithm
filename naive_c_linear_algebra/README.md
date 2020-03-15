## Linear algebra with naive C

 <br> 

- 입력 받은 스칼라 값의 역수를 취한다. (divided by zero 처리함)
- `double Reciprocal(double a);`

<br>

- matrix를 복사한다.
- `Matrix CloneMatrix(const Matrix* mat);`

 <br> 

- vector를 복사한다.
- `Vector CloneVector(const Vector* vec);`

 <br> 

- 두 matrix를 곱한다.
- `Matrix MatrixByMatrix(const Matrix* mat1, const Matrix* mat2);`

 <br> 

- matrix와 vector를 곱한다.
- `Vector MatrixByVector(const Matrix* mat, const Vector* vec);`

 <br> 

- 입력 받은 길이의 항등행렬을 반환한다.
- `Matrix Identity(int len);`

 <br> 

- matrix의 각 값에 scalar 값을 곱합니다.
- `Matrix ScalarByMatrix(double scalar, const Matrix* mat);`

 <br> 

- vector의 각 값에 scalar 값을 곱합니다.
- `Vector ScalarByVector(double scalar, const Vector* vec);`

 <br> 

- matrix와 matrix를 더합니다.
- `Matrix MatrixPlusMatrix(const Matrix* mat1, const Matrix* mat2);`

 <br> 

- matrix를 transpose 합니다.
- `Matrix Transpose(const Matrix* mat);`

 <br> 

- matrix의 모든 값을 역수를 취합니다. (divide by zero 조치함)
- `Matrix MatrixReciprocal(const Matrix* mat);`

 <br> 

- vector의 모든 값을 역수를 취합니다. (divide by zero 조치함)
- `Vector VectorReciprocal(const Vector* vec);`

 <br> 

- 모든 값이 0인 (row, col) 크기의 matrix를 만듭니다.
- `Matrix Zeros(int row, int col);`

 <br> 

- 모든 값이 1인 (row, col) 크기의 matrix를 만듭니다.
- `Matrix Ones(int row, int col);`

 <br> 

- matrix의 eigenvector와 eigenvalue를 구합니다. Matrix에 eigenvector가, Vector에 eigenvalue가 저장됩니다.
- `MatrixVector Eigen(const Matrix* mat);`

 <br> 

- matrix를 U, Sigma, V 순으로 특이값 분해 합니다.
- `Svd SingularValueDecomposition(const Matrix* mat);`

 <br> 

- matrix의 역행렬을 구합니다. 역행렬 값이 없을 때에는 pseudo inverse로 구합니다.
- `Matrix Inverse(const Matrix* mat);`

 <br> 

- matrix를 출력합니다.
- `void PrintMatrix(const Matrix* mat);`

 <br> 

- vector를 출력합니다.
- `void PrintVector(const Vector* vec);`