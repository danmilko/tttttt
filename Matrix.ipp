#pragma once
#include "Matrix.hpp"

template <typename T>
Matrix<T>::Matrix()
{
	_size1 = 1;
	_size2 = 1;
	std::vector<T> temp;
	temp.push_back(0);
	matrix.push_back(temp);
}

template <typename T>
Matrix<T>::Matrix(int size1, int size2)
{
	if (size1 < 1 || size2 < 1)
	{
		throw std::exception("Error: one dimension is < 0");
	}
	_size1 = size1;
	_size2 = size2;
	for (int i = 0; i < size1; ++i)
	{
		std::vector<T> temp;
		for (int j = 0; j < size2; ++j)
		{
			temp.push_back(0);
		}
		matrix.push_back(temp);
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other)
{
	_size1 = other._size1;
	_size2 = other._size2;
	for (int i = 0; i < _size1; ++i)
	{
		std::vector<T> temp;
		for (int j = 0; j < _size2; ++j)
		{
			temp.push_back(other.matrix[i][j]);
		}
		matrix.push_back(temp);
	}
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
	_size1 = other._size1;
	_size2 = other._size2;
	for (int i = 0; i < _size1; ++i)
	{
		std::vector<T> temp;
		for (int j = 0; j < _size2; ++j)
		{
			temp.push_back(other.matrix[i][j]);
		}
		matrix.push_back(temp);
	}
	return *this;
}

template <typename T>
Matrix<T>& operator+(const Matrix<T>& other1, const Matrix<T>& other2)
{
	if (other1._size1 != other2._size1 || other1._size2 != other2._size2)
	{
		throw std::exception("Error: sum of matrix of incompatible size");
	}

	Matrix<T> res = Matrix<T>(other1._size1, other1._size2);

	for (int i = 0; i < other1._size1; ++i)
	{
		for (int j = 0; j < other1._size2; ++j)
		{
			res.matrix[i][j] = other1.matrix[i][j] + other2.matrix[i][j];
		}
	}

	return res;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-(Matrix<T>& other)
{
	for (int i = 0; i < other._size1; ++i)
	{
		for (int j = 0; j < other._size2; ++j)
		{
			other.matrix[i][j] *= -1;
		}
	}

	return other;
}

template <typename T>
Matrix<T>& operator-(const Matrix<T>& other1, const Matrix<T>& other2)
{
	return other1 + (-other2);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m)
{
	for (int i = 0; i < m._size1; ++i)
	{
		for (int j = 0; j < m._size2; ++j)
		{
			out << m.matrix[i][j] << ' ';
		}
		out << std::endl;
	}
}

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& m)
{
	for (int i = 0; i < m._size1; ++i)
	{
		for (int j = 0; j < m._size2; ++j)
		{
			in >> m.matrix[i][j];
		}
	}
}