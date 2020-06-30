/*
- All codes are written by gaussian37.
- Compile environment : C99
- All comments MUST be written English.
- All code follows the rules.

1. Notation
	1.1. All functions follow Pascal notation. (e.g. CloneMatrix (o), cloneMatrix(x), clone_matrix(x))
	1.2. All variables follow snake notation. (e.g. result_matrix (o), resultMatrix(x), ResultMatrix(x))

2. Function 
	2.1. Function inputs and outputs are taken as arguments. It must be delivered in the order of input and output.
	2.2. When input is passed to a function, the primitive type must be passed by value and the structure by pointer.
	2.3. The input of the function takes as const type.
	2.4. The result is stored directly in the output passed to the pointer.
	2.5. It indicates the function operation status through the return value, 
	     and if the return value is 0, it is determined that it is operated normally.

3. Etc
	3.1. All codes have minimum dynamic memory allocation because those are created for using embedded environment.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "matrix.h"


void CloneMatrix(const Matrix *input, Matrix *output) {
	
	output->row = input->row;
	output->col = input->col;

	for (int i = 0; i < input->row; ++i) {
		for (int j = 0; j < input->col; ++j) {
			output->matrix[i][j] = input->matrix[i][j];
		}
	}
}

void CloneVector(const Vector *input, Vector *output) {
	output->row = input->row;
	
	for (int i = 0; i < input->row; ++i) {
		output->vector[i] = input->vector[i];
	}
}

void PrintMatrixShape(const Matrix *input) {
	printf("(%d, %d)\n", input->row, input->col);
}

void PrintVectorShape(const Vector *input) {
	printf("(%d,)\n", input->row);
}

Matrix MatrixByMatrix(const Matrix* mat1, const Matrix* mat2) {

	int i, j, k;
	Matrix ret;

	assert(mat1.col != mat2.row);

	ret.row = mat1->row;
	ret.col = mat2->col;

	for (i = 0; i < mat1->row; ++i) {
		for (j = 0; j < mat2->col; ++j) {
			ret.matrix[i][j] = 0;
			for (k = 0; k < mat1->col; ++k) {
				ret.matrix[i][j] += mat1->matrix[i][k] * mat2->matrix[k][j];
			}
		}
	}

	return ret;

}

Vector MatrixByVector(const Matrix* mat, const Vector* vec) {
	int i, j;
	Vector ret;

	assert(mat->col != vec->row);

	ret.row = mat->row;
	for (i = 0; i < mat->row; ++i) {
		ret.vector[i] = 0;
		for (j = 0; j < mat->col; ++j) {
			ret.vector[i] += mat->matrix[i][j] * vec->vector[j];
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

Matrix ScalarByMatrix(double scalar, const Matrix* mat) {
	int i, j;
	Matrix ret;
	ret.row = mat->row;
	ret.col = mat->col;
	for (i = 0; i < mat->row; ++i) {
		for (j = 0; j < mat->col; ++j) {
			ret.matrix[i][j] = scalar * mat->matrix[i][j];
		}
	}
	return ret;
}

Vector ScalarByVector(double scalar, const Vector* vec) {
	int i;
	Vector ret;
	ret.row = vec->row;
	for (i = 0; i < vec->row; ++i) {
		ret.vector[i] = scalar * vec->vector[i];
	}
	return ret;
}

Matrix MatrixPlusMatrix(const Matrix* mat1, const Matrix* mat2) {
	int i, j;
	Matrix ret;
	assert((mat1->row != mat2->row) || (mat1->col != mat2->col));

	ret.row = mat1->row;
	ret.col = mat1->col;

	for (i = 0; i < mat1->row; ++i) {
		for (j = 0; j < mat1->col; ++j) {
			ret.matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
		}
	}
	return ret;
}


Matrix MatrixMinusMatrix(const Matrix* mat1, const Matrix* mat2) {
	int i, j;
	Matrix ret;
	assert((mat1->row != mat2->row) || (mat1->col != mat2->col));

	ret.row = mat1->row;
	ret.col = mat1->col;

	for (i = 0; i < mat1->row; ++i) {
		for (j = 0; j < mat1->col; ++j) {
			ret.matrix[i][j] = mat1->matrix[i][j] - mat2->matrix[i][j];
		}
	}
	return ret;
}

Vector VectorPlusVector(const Vector* vec1, const Vector* vec2) {
	int i;
	Vector ret;
	assert(vec1->row != vec2->row);

	ret.row = vec1->row;
	for (i = 0; i < vec1->row; ++i) {
		ret.vector[i] = vec1->vector[i] + vec2->vector[i];
	}
	return ret;
}

Vector VectorMinusVector(const Vector* vec1, const Vector* vec2) {
	int i;
	Vector ret;
	assert(vec1->row != vec2->row);

	ret.row = vec1->row;
	for (i = 0; i < vec1->row; ++i) {
		ret.vector[i] = vec1->vector[i] - vec2->vector[i];
	}
	return ret;
}

Matrix Transpose(const Matrix* mat) {

	int i, j;
	Matrix ret;
	ret.row = mat->col;
	ret.col = mat->row;

	for (i = 0; i < ret.row; ++i) {
		for (j = 0; j < ret.col; ++j) {
			ret.matrix[i][j] = mat->matrix[j][i];
		}
	}

	return ret;

}

double Reciprocal(const double input, double *output) {
	int ret = 0;

	if ( -EPS < input && input < EPS) {
		*output = 0.0;
		ret = 1;
	}
	else {
		*output = 1 / input;
	}
	return ret;
}

Matrix MatrixReciprocal(const Matrix* mat) {

	int i, j;
	Matrix ret;
	ret.row = mat->row;
	ret.col = mat->col;
	
	memset(ret.matrix, 0, sizeof(ret.matrix));	
	for (i = 0; i < mat->row; ++i) {
		for (j = 0; j < mat->col; ++j) {
			ret.matrix[i][j] = Reciprocal(mat->matrix[i][j]);
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

MatrixVector Eigen(const Matrix* mat) {

	MatrixVector ret;
	double a, b, c, d;
	double T, D, L1, L2;
	double eigen_value[MAX_ROW];

	memset(eigen_value, 0, sizeof(eigen_value));
	if (mat->row == 2 && mat->col == 2) {
		// https://gaussian37.github.io/math-la-2_by_2_eigen/
		
		a = mat->matrix[0][0]; b = mat->matrix[0][1];
		c = mat->matrix[1][0]; d = mat->matrix[1][1];

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

Svd SingularValueDecomposition(const Matrix* mat) {

	Svd ret;
	MatrixVector U, V;
	Matrix Sigma, A_At, At_A;;

	int i;
	int max_r_c, flag, r, c;

	r = mat->row;
	c = mat->col;
	A_At = MatrixByMatrix(&mat, Transpose(&mat));
	At_A = MatrixByMatrix(Transpose(&mat), &mat);

	U = Eigen(&A_At);
	V = Eigen(&At_A);

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
	

	// U�� ����� �� ū ���
	if (flag == 0) {
		for (i = 0; i < max_r_c; ++i) {
			Sigma.matrix[i][i] = sqrt(U.Vector.vector[i]);
		}
	}
	// V�� ����� �� ū ���
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

Matrix Inverse(const Matrix* mat) {

	double eta = 0.1;
	double a, b, c, d, e, f, g, h, i, denominator, det;
	Svd svd;
	Matrix ret;
	ret.row = mat.row;
	ret.col = mat.col;

	if (mat.row != mat.col) {
		printf("Rectangle matrix inverse is not implemented.\n");
		exit(1);
	}
	else if (mat.row == 1 && mat.col == 1) {
		ret = CloneMatrix(&mat);
	}
	else if (mat.row == 2 && mat.col == 2) {
		a = mat.matrix[0][0]; b = mat.matrix[0][1];
		c = mat.matrix[1][0]; d = mat.matrix[1][1];
		det = a * d - b * c;
		if (det < 0.1) {
			svd = SingularValueDecomposition(&mat);
			matrix_reciprocal = MatrixReciprocal(&svd.Sigma);
			matrix_by_matrix1 = MatrixByMatrix(&svd.V, &matrix_reciprocal);
			transpose = Transpose(&svd.U);
			ret = MatrixByMatrix(&matrix_by_matrix1, &transpose);
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
		ret = ScalarByMatrix(denominator, &ret);
	}
	else {

	}
	return ret;
}


void PrintMatrix(const Matrix* mat) {
	int i, j;
	for (i = 0; i < mat->row; ++i) {
		for (j = 0; j < mat->col; ++j) {
			printf("%f\t", mat->matrix[i][j]);
		}
		printf("\n");
	}
}

void PrintVector(const Vector* vec) {
	int i;
	for (i = 0; i < vec->row; ++i) {
		printf("%f\n", vec->vector[i]);
	}
}