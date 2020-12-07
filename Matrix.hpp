#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Matrix
{
	static_assert(std::is_arithmetic<T>::value, "Matrix should be arithmetic");
	std::vector<std::vector<T>> matrix;
	int _size1;
	int _size2;
public:
	Matrix();
	Matrix(int size1, int size2);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);

	template <class V>
	friend Matrix<V>& operator+(const Matrix<V>& other1, const Matrix<V>& other2);

	template <class V>
	friend Matrix& operator-(const Matrix& other1, const Matrix& other2);

	Matrix& operator-(Matrix& other);

	template <class V>
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);

	template <class V>
	friend std::istream& operator>>(std::istream& in, Matrix& m);
};

#include "Matrix.ipp"