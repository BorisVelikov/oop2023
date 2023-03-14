#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
	void copy(const Matrix& other);
	void destroy();

	int rowCount;
	int colCount;
	int** data;

public:
	//rule of 4
	Matrix(int rows, int cols);
	~Matrix();
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	
	//move semanthics
	Matrix(Matrix&& other);
	Matrix& operator=(Matrix&& other);

	//custom funcs
	int& operator()(int row, int col);  // lvalue

	Matrix operator+(const Matrix& other) const;

	Matrix operator-(const Matrix& other) const;

	Matrix operator*(const Matrix& other) const;

	bool operator==(const Matrix& other) const;

	friend Matrix transpose(const Matrix& matrix);

	friend void print(const Matrix& matrix);
};

#endif  // MATRIX_H