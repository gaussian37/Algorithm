## Linear algebra with naive C

- 입력 받은 스칼라 값의 역수를 취한다. (divided by zero 처리함)
`double Reciprocal(double a);`

- matrix를 복사한다.
`Matrix CloneMatrix(Matrix mat);`

- vector를 복사한다.
`Vector CloneVector(Vector vec);`

- 두 matrix를 곱한다.
`Matrix MatrixByMatrix(Matrix mat1, Matrix mat2);`

- matrix와 vector를 곱한다.
`Vector MatrixByVector(Matrix mat, Vector vec);`

- 입력 받은 길이의 항등행렬을 반환한다.
`Matrix Identity(int len);`

- matrix의 각 값에 scalar 값을 곱합니다.
`Matrix ScalarByMatrix(double scalar, Matrix mat);`

- vector의 각 값에 scalar 값을 곱합니다.
`Vector ScalarByVector(double scalar, Vector vec);`

- matrix와 matrix를 더합니다.
`Matrix MatrixPlusMatrix(Matrix mat1, Matrix mat2);`

- matrix를 transpose 합니다.
`Matrix Transpose(Matrix mat);`

- matrix의 모든 값을 역수를 취합니다. (divide by zero 조치함)
`Matrix MatrixReciprocal(Matrix mat);`

- vector의 모든 값을 역수를 취합니다. (divide by zero 조치함)
`Vector VectorReciprocal(Vector vec);`
- 모든 값이 0인 (row, col) 크기의 matrix를 만듭니다.
`Matrix Zeros(int row, int col);`

- 모든 값이 1인 (row, col) 크기의 matrix를 만듭니다.
`Matrix Ones(int row, int col);`

- matrix의 eigenvector와 eigenvalue를 구합니다. Matrix에 eigenvector가, Vector에 eigenvalue가 저장됩니다.
`MatrixVector Eigen(Matrix mat);`

- matrix를 U, Sigma, V 순으로 특이값 분해 합니다.
`SVD SingularValueDecomposition(Matrix mat);`

- matrix의 역행렬을 구합니다. 역행렬 값이 없을 때에는 pseudo inverse로 구합니다.
`Matrix Inverse(Matrix mat);`

- matrix를 출력합니다.
`void PrintMatrix(Matrix mat);`

- vector를 출력합니다.
`void PrintVector(Vector vec);`