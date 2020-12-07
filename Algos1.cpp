#include <iostream>

#include "Matrix.hpp"

int main()
{
	Matrix<int> m1 = Matrix<int>(3, 3);
	Matrix<int> m2 = Matrix<int>(3, 3);
	Matrix<int> m3 = m1 + m2;
	return 0;
}