#include "matrix.h"

Matrix::Matrix(std::size_t r, std::size_t c) {
	_rows = r;
	_cols = c;
	_data = new int* [_rows];
	for (std::size_t i = 0; i < _rows; i++)
        _data[i] = new int[_cols]();
}

Matrix::~Matrix(){
    for (std::size_t i = 0; i < _rows; i++)
        delete []_data[i];
    delete []_data;
}

Matrix::Matrix(const Matrix& m) {
	_rows = m._rows;
	_cols = m._cols;
	_data = new int* [_rows];
	for (std::size_t i = 0; i < _rows; i++)
        _data[i] = new int[_cols];
	for (std::size_t i = 0; i < _rows; i++)
		for (std::size_t j = 0; j < _cols; j++)
			_data[i][j] = m._data[i][j];
}

Matrix Matrix::operator=(const Matrix& m) {
	if (*this != m){
        Matrix tmp = Matrix(m);
        (*this).swap(tmp);
	}
    return *this;
}

void Matrix::swap(Matrix& m) {
    std::swap(_rows, m._rows);
    std::swap(_cols, m._cols);
    std::swap(_data, m._data);
}

std::size_t Matrix::get_rows() const { return _rows; }
std::size_t Matrix::get_cols() const { return _cols; }

void Matrix::set(std::size_t i, std::size_t j, int val) {
	assert(i < _rows);
	assert(j < _cols);
	_data[i][j] = val;
}

int Matrix::get(std::size_t i, std::size_t j) const {
	assert(i < _rows);
	assert(j < _cols);
	return _data[i][j];
}

void Matrix::print(FILE* f) const {
	for (std::size_t i = 0; i < _rows; i++){
		for (std::size_t j = 0; j < _cols; j++)
			fprintf(f, "%d ", _data[i][j]);
		fprintf(f, "\n");
	}
}

bool Matrix::operator==(const Matrix& m) const {
	if (_rows != m._rows || _cols != m._cols) return false;
	for (std::size_t i = 0; i < _rows; i++){
		for (std::size_t j = 0; j < _cols; j++)
			if (_data[i][j] != m._data[i][j]) return false;
	}
	return true;
}

bool Matrix::operator!=(const Matrix& m) const {
	return !(*this).operator==(m);
}

Matrix& Matrix::operator+=(const Matrix& m) {
	for (std::size_t i = 0; i < _rows; i++)
		for (std::size_t j = 0; j < _cols; j++)
			_data[i][j] += m._data[i][j];
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
	for (std::size_t i = 0; i < _rows; i++)
		for (std::size_t j = 0; j < _cols; j++)
			_data[i][j] -= m._data[i][j];
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
	Matrix tmp = Matrix(_rows, m._cols);
	for (std::size_t i = 0; i < _rows; i++)
		for (std::size_t j = 0; j < _cols; j++)
			for (std::size_t k = 0; k < m._cols; k++)
				tmp._data[i][k] += _data[i][j] * m._data[j][k];
	(*this).swap(tmp);
	return *this;
}

Matrix Matrix::operator+(const Matrix& m) const {
	Matrix tmp = (*this);
	tmp += m;
	return tmp;
}

Matrix Matrix::operator-(const Matrix& m) const {
	Matrix tmp = (*this);
	tmp -= m;
	return tmp;
}

Matrix Matrix::operator*(const Matrix& m) const {
	Matrix tmp = (*this);
	tmp *= m;
	return tmp;
}
