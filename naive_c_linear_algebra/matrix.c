#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

double Reciprocal(double a) {
	double ret, temp;
	temp = a;
	if (temp < 0) {
		temp = -temp;
	}
	if (temp < EPS) {
		ret = 0.0;
	}
	else {
		ret = 1 / a;
	}
	return ret;
}

Matrix CloneMatrix(Matrix mat) {
	int i, j;
	Matrix ret;
	ret.row = mat.row;
	ret.col = mat.col;

	for (i = 0; i < mat.row; ++i) {
		for (j = 0; j < mat.col; ++j) {
			ret.matrix[i][j] = mat.matrix[i][j];
		}
	}
	return ret;
}

Vector CloneVector(Vector vec) {
	int i;
	Vector ret;
	ret.row = vec.row;

	for (i = 0; i < vec.row; ++i) {
		ret.vector[i] = vec.vector[i];
	}
	return vec;
}

void PrintMatrixShape(Matrix mat) {
	printf("(%d, %d)\n", mat.row, mat.col);
}

void PrintVectorShape(Vector vec) {
	printf("(%d,)\n", vec.row);
}

Matrix MatrixByMatrix(Matrix mat1, Matrix mat2) {

	int i, j, k;
	Matrix ret;

	if (mat1.col != mat2.row) {
		printf("MatrixByMatrix: 첫번째 행렬의 열과 두번째 행렬의 행의 사이즈가 다릅니다.");
		system("pause");
		exit(1);
	}

	ret.row = mat1.row;
	ret.col = mat2.col;

	for (i = 0; i < mat1.row; ++i) {
		for (j = 0; j < mat2.col; ++j) {
			ret.matrix[i][j] = 0;
			for (k = 0; k < mat1.col; ++k) {
				ret.matrix[i][j] += mat1.matrix[i][k] * mat2.matrix[k][j];
			}
		}
	}

	return ret;

}

Vector MatrixByVector(Matrix mat, Vector vec) {
	int i, j;
	Vector ret;

	if (mat.col != vec.row) {
		printf("MatrixByVector: 행렬의 열과 열벡터의 열의 사이즈가 다릅니다.");
		system("pause");
		exit(1);
	}

	ret.row = mat.row;
	for (i = 0; i < mat.row; ++i) {
		ret.vector[i] = 0;
		for (j = 0; j < mat.col; ++j) {
			ret.vector[i] += mat.matrix[i][j] * vec.vector[j];
		}
	}

	return ret;
}

Matrix Identity(int len) {
	int i;
	Matrix ret;

	memset(ret.matrix, 0, sizeof(ret.matrix));
	ret.row = len;
	ret.col = len;
	for (i = 0; i < len; ++i) {
		ret.matrix[i][i] = 1;
	}

	return ret;
}

Matrix ScalarByMatrix(double scalar, Matrix mat) {
	int i, j;
	Matrix ret;
	ret.row = mat.row;
	ret.col = mat.col;
	for (i = 0; i < mat.row; ++i) {
		for (j = 0; j < mat.col; ++j) {
			ret.matrix[i][j] = scalar * mat.matrix[i][j];
		}
	}
	return ret;
}

Vector ScalarByVector(double scalar, Vector vec) {
	int i;
	Vector ret;
	ret.row = vec.row;
	for (i = 0; i < vec.row; ++i) {
		ret.vector[i] = scalar * vec.vector[i];
	}
	return ret;
}

Matrix MatrixPlusMatrix(Matrix mat1, Matrix mat2) {
	int i, j;
	Matrix ret;
	if (mat1.row != mat2.row || mat1.col != mat2.col) {
		printf("MatrixPlusMatrix: 두 행렬의 행 또는 열의 크기가 일치하지 않습니다.\n");
		exit(1);
	}
	ret.row = mat1.row;
	ret.col = mat1.col;

	for (i = 0; i < mat1.row; ++i) {
		for (j = 0; j < mat1.col; ++j) {
			ret.matrix[i][j] = mat1.matrix[i][j] + mat2.matrix[i][j];
		}
	}
	return ret;
}


Matrix MatrixMinusMatrix(Matrix mat1, Matrix mat2) {
	int i, j;
	Matrix ret;
	if (mat1.row != mat2.row || mat1.col != mat2.col) {
		printf("MatrixMinusMatrix: 두 행렬의 행 또는 열의 크기가 일치하지 않습니다.\n");
		exit(1);
	}
	ret.row = mat1.row;
	ret.col = mat1.col;

	for (i = 0; i < mat1.row; ++i) {
		for (j = 0; j < mat1.col; ++j) {
			ret.matrix[i][j] = mat1.matrix[i][j] - mat2.matrix[i][j];
		}
	}
	return ret;
}

Vector VectorPlusVector(Vector vec1, Vector vec2) {
	int i;
	Vector ret;
	if (vec1.row != vec2.row) {
		printf("VectorPlusVector: 두 벡터의 크기가 일치하지 않습니다.\n");
		exit(1);
	}
	ret.row = vec1.row;
	for (i = 0; i < vec1.row; ++i) {
		ret.vector[i] = vec1.vector[i] + vec2.vector[i];
	}
	return ret;
}

Vector VectorMinusVector(Vector vec1, Vector vec2) {
	int i;
	Vector ret;
	if (vec1.row != vec2.row) {
		printf("VectorMinusVector: 두 벡터의 크기가 일치하지 않습니다.\n");
		exit(1);
	}
	ret.row = vec1.row;
	for (i = 0; i < vec1.row; ++i) {
		ret.vector[i] = vec1.vector[i] - vec2.vector[i];
	}
	return ret;
}

Matrix Transpose(Matrix mat) {

	int i, j;
	Matrix ret;
	ret.row = mat.col;
	ret.col = mat.row;

	for (i = 0; i < ret.row; ++i) {
		for (j = 0; j < ret.col; ++j) {
			ret.matrix[i][j] = mat.matrix[j][i];
		}
	}

	return ret;

}

Matrix MatrixReciprocal(Matrix mat) {

	int i, j;
	Matrix ret;
	ret.row = mat.row;
	ret.col = mat.col;
	
	memset(ret.matrix, 0, sizeof(ret.matrix));	
	for (i = 0; i < mat.row; ++i) {
		for (j = 0; j < mat.col; ++j) {
			ret.matrix[i][j] = Reciprocal(mat.matrix[i][j]);
		}
	}
	return ret;
}

Vector VectorReciprocal(Vector vec) {
	int i;
	Vector ret;
	ret.row = vec.row;

	for (i = 0; i < ret.row; ++i) {
		ret.vector[i] = Reciprocal(vec.vector[i]);
	}
	return ret;
}

Matrix Zeros(int row, int col) {
	Matrix ret;
	ret.row = row;
	ret.col = col;
	memset(ret.matrix, 0, sizeof(ret.matrix));
	return ret;
}

Matrix Ones(int row, int col) {
	int i, j;
	Matrix ret;
	ret.row = row;
	ret.col = col;
	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			ret.matrix[i][j] = 1;
		}
	}
	return ret;
}

MatrixVector Eigen(Matrix mat) {

	MatrixVector ret;
	double a, b, c, d;
	double T, D, L1, L2;
	double eigen_value[MAX_ROW];

	memset(eigen_value, 0, sizeof(eigen_value));
	if (mat.row == 2 && mat.col == 2) {
		// https://gaussian37.github.io/math-la-2_by_2_eigen/
		
		a = mat.matrix[0][0]; b = mat.matrix[0][1];
		c = mat.matrix[1][0]; d = mat.matrix[1][1];

		T = a + d;
		D = a * d - b * c;

		L1 = T / 2 + sqrt((T*T) / 4 - D);
		L2 = T / 2 - sqrt((T*T) / 4 - D);

		ret.Vector.row = 2;
		ret.Vector.vector[0] = L1;
		ret.Vector.vector[1] = L2;

		ret.Matrix.row = 2;
		ret.Matrix.col = 2;		

		if (b == 0 && c == 0) {
			ret.Matrix.matrix[0][0] = 1.0; 
			ret.Matrix.matrix[0][1] = 0;
			ret.Matrix.matrix[1][0] = 0; 
			ret.Matrix.matrix[1][1] = 1.0;
		}
		else if (c != 0) {
			ret.Matrix.matrix[0][0] = (L1 - d) / sqrt((L1 - d)*(L1 - d) + c * c);
			ret.Matrix.matrix[0][1] = (L2 - d) / sqrt((L2 - d)*(L2 - d) + c * c);
			ret.Matrix.matrix[1][0] = c / sqrt((L1 - d)*(L1 - d) + c * c);
			ret.Matrix.matrix[1][1] = c / sqrt((L2 - d)*(L2 - d) + c * c);
		}
		else if (b != 0) {
			ret.Matrix.matrix[0][0] = b / sqrt(b * b + (L1 - a) * (L1 - a));
			ret.Matrix.matrix[0][1] = b / sqrt(b * b + (L2 - a) * (L2 - a));
			ret.Matrix.matrix[1][0] = (L1 - a) / sqrt(b * b + (L1 - a) * (L1 - a));	
			ret.Matrix.matrix[1][1] = (L2 - a) / sqrt(b * b + (L2 - a) * (L2 - a));
		}				
		
	}
	else {
		puts("Not implemented");
		exit(1);
	}
	return ret;
}

SVD SingularValueDecomposition(Matrix mat) {

	SVD ret;
	MatrixVector U, V;
	Matrix Sigma, A_At, At_A;;

	int i;
	int max_r_c, flag, r, c;

	r = mat.row;
	c = mat.col;
	A_At = MatrixByMatrix(mat, Transpose(mat));
	At_A = MatrixByMatrix(Transpose(mat), mat);

	U = Eigen(A_At);
	V = Eigen(At_A);

	if (r >= c) {
		max_r_c = r;
		flag = 0;
	}
	else {
		max_r_c = c;
		flag = 1;
	}

	memset(Sigma.matrix, 0, sizeof(Sigma.matrix));
	Sigma.row = r;
	Sigma.col = c;
	

	// U의 사이즈가 더 큰 경우
	if (flag == 0) {
		for (i = 0; i < max_r_c; ++i) {
			Sigma.matrix[i][i] = sqrt(U.Vector.vector[i]);
		}
	}
	// V의 사이즈가 더 큰 경우
	else {
		for (i = 0; i < max_r_c; ++i) {
			Sigma.matrix[i][i] = sqrt(U.Vector.vector[i]);
		}
	}

	ret.U = U.Matrix; 
	ret.Sigma = Sigma;
	ret.V = V.Matrix;

	return ret;
}

Matrix Inverse(Matrix mat) {

	double eta = 0.1;
	double a, b, c, d, e, f, g, h, i, denominator, det;
	SVD svd;
	Matrix ret;
	ret.row = mat.row;
	ret.col = mat.col;

	if (mat.row != mat.col) {
		printf("Rectangle matrix inverse is not implemented.\n");
		exit(1);
	}
	else if (mat.row == 1 && mat.col == 1) {
		ret = CloneMatrix(mat);
	}
	else if (mat.row == 2 && mat.col == 2) {
		a = mat.matrix[0][0]; b = mat.matrix[0][1];
		c = mat.matrix[1][0]; d = mat.matrix[1][1];
		det = a * d - b * c;
		if (det < 0.1) {
			svd = SingularValueDecomposition(mat);
			ret = MatrixByMatrix(MatrixByMatrix(svd.V, MatrixReciprocal(svd.Sigma)), Transpose(svd.U));
		}
		else {
			denominator = 1 / det;
			ret.matrix[0][0] = denominator * d;
			ret.matrix[0][1] = denominator * -b;
			ret.matrix[1][0] = denominator * -c;
			ret.matrix[1][1] = denominator * a;
		}
	}
	else if (mat.row == 3 && mat.col == 3) {
		a = mat.matrix[0][0]; b = mat.matrix[0][1]; c = mat.matrix[0][2];
		d = mat.matrix[0][0]; e = mat.matrix[0][1]; f = mat.matrix[0][2];
		g = mat.matrix[0][0]; h = mat.matrix[0][1]; i = mat.matrix[0][2];
		denominator = a * e*i + b * f*g + c * d*h - c * e*g - b * d*i - a * f*h + eta;
		ret.matrix[0][0] = e * i - f * h;
		ret.matrix[0][1] = -(b * i - c * h);
		ret.matrix[0][2] = b * f - c * e;
		ret.matrix[1][0] = -(d * i - f * g);
		ret.matrix[1][1] = a * i - c * g;
		ret.matrix[1][2] = -(a * f - c * d);
		ret.matrix[2][0] = d * h - e * g;
		ret.matrix[2][1] = -(a * h - b * g);
		ret.matrix[2][2] = a * e - b * d;
		ret = ScalarByMatrix(denominator, ret);
	}
	else {

	}
	return ret;
}


void PrintMatrix(Matrix mat) {
	int i, j;
	for (i = 0; i < mat.row; ++i) {
		for (j = 0; j < mat.col; ++j) {
			printf("%f\t", mat.matrix[i][j]);
		}
		printf("\n");
	}
}

void PrintVector(Vector vec) {
	int i;
	for (i = 0; i < vec.row; ++i) {
		printf("%f\n", vec.vector[i]);
	}
}