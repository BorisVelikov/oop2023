#include "matrix.h"

Matrix::Matrix(int rows, int cols) : rowCount(rows), colCount(cols) {
	data = new int* [rowCount];
	for (int br = 0; br < colCount; br++) {
		data[br] = new int[colCount];
	}
}

void Matrix::destroy() {
	if (data != nullptr) {
		for (int br = 0; br < rowCount; br++) {
			delete[] data[br];
		}
		delete[] data;
		data = nullptr;
	}
}

Matrix::~Matrix() {
	destroy();
}

void Matrix::copy(const Matrix& other) {
	destroy();
	rowCount = other.rowCount;
	colCount = other.colCount;
	data = new int* [rowCount];
	//suzdavame matrica
	for (int br = 0; br < colCount; br++) {
		data[br] = new int[colCount];
	}
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			data[i][j] = other.data[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& other) : rowCount(other.rowCount), colCount(other.colCount), data(nullptr) {
	copy(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
	copy(other);
	return *this;
}

Matrix::Matrix(Matrix&& other) : rowCount(other.rowCount), colCount(other.colCount), data(other.data) {
	other.data = nullptr;
}

Matrix& Matrix::operator=(Matrix&& other) {
	destroy();
	rowCount = other.rowCount;
	colCount = other.colCount;
	data = other.data;
	other.data = nullptr;
}

//custom funcs

int& Matrix::operator()(int row, int col) {
	return data[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const {
	Matrix temp(rowCount, colCount);
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			temp.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return temp;
}

Matrix Matrix::operator-(const Matrix& other) const {
	Matrix temp(rowCount, colCount);
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			temp.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
	return temp;
}

bool Matrix::operator==(const Matrix& other) const {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			if (data[i][j] != other.data[i][j])
				return false;
		}
	}
	return true;
}

Matrix Matrix::operator*(const Matrix& other) const {
	Matrix temp(rowCount, other.colCount);
	for (int i = 0; i < temp.rowCount; i++) {
		for (int j = 0; j < temp.colCount; j++) {
			int sum = 0;
			for (int br = 0; br < colCount; br++) {
				sum += data[i][br] * other.data[br][j];
			}
			temp.data[i][j] = sum;
		}
	}
	return temp;
}