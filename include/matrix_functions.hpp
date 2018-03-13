/** MIT License
Copyright (c) 2018 Sudarshan Raghunathan
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *@copyright Copyright 2018 Sudarshan Raghunathan
 *@file test.cpp
 *@author Sudarshan Raghunathans
 *@brief Matrix operations definition
 */
#ifndef MATRIX_H_ // NOLINT
#define MATRIX_H_
#include<vector>
using namespace::std;

/**
*@brief Class used for member function definitions. Uses templates
*/

template<class T, int m, int n>
class Matrix
{
vector<vector<T>> elements;

public:
int nrow;
int ncol;
bool flag1;
bool flag2;
Matrix(vector<vector<T> >& a);
~Matrix();
void print();
friend class Matrix<T, n, m>;
//friend class Matrix<T, n, l>;
Matrix<T, n, m> transpose();
template<class _T, int _m, int _n,int p, int l>
friend Matrix<_T, _m, l> operator*(const Matrix<_T, _m, _n>&, const Matrix<_T, p, l>&);
};

/**
*@brief Constructor of class. Used to create matrix
*@param ar is the vector of vectors used to define the matrix
*@return Matrix which is a created object and a vector of vectors
*/

template<class T, int m, int n>
Matrix<T, m, n>::Matrix(vector<vector<T> > & ar) :
		nrow(m), ncol(n) {
try {
	if(m < 0 || n < 0)
	{
		throw std::invalid_argument(
				"Matrix index cannot be negative");
	}
	for (vector<T> i : ar) {
		elements.push_back(i);
	}
} catch (std::exception& e) {
	std::cerr << "Exception: " << e.what() << std::endl;
	flag1=false;
}
}
/**
*@brief Destructor
*/

template<class T, int m, int n>
Matrix<T, m, n>::~Matrix() {
}
/**
*@brief Function to create transpose
*@param none
*@return Matrix Transposed matrix object
*/

template<class T, int m, int n>
Matrix<T, n, m> Matrix<T, m, n>::transpose() {
vector<vector<T> > tmp;
for (int i = 0; i < n; i++) {
	std::vector<T> fogRow;
	for (int j = 0; j < m; j++) {
		fogRow.push_back(0);
	}
	tmp.push_back(fogRow);
}
Matrix<T, n, m> k(tmp);
for (int i = 0; i < nrow; ++i) {
	for (int j = 0; j < ncol; ++j) {
		k.elements[j][i] = elements[i][j];
	}
}
return k;
}
/**
*@brief Multiplication function created as an operator
*@param m1 is the object of a matrix that is to be multiplied
*@param m2 is the object of another matrix. the result is m1*m2
*@return Matrix multiplied matrix object
*/
template<class T, int m, int n, int p, int l>
Matrix<T, m, l> operator*(const Matrix<T, m, n>& m1,
	const Matrix<T, p, l>& m2) {
try {
	if (n != p) {
		throw std::invalid_argument("Matrix multiplication dimension mismatch");
	}
	int nrow = m1.nrow;
	int ncol = m2.ncol;
	vector<vector<T> > tmp;
	for (int i = 0; i < m; i++) {
		std::vector<T> fogRow;
		for (int j = 0; j < l; j++) {
			fogRow.push_back(0);
		}
		tmp.push_back(fogRow);
	}
	Matrix<T, m, l> m3(tmp);
	for (int i = 0; i < nrow; ++i) {
		for (int j = 0; j < ncol; ++j) {
			m3.elements[i][j] = 0;
			for (int k = 0; k < m1.ncol; k++) {
				T temp = m1.elements[i][k] * m2.elements[k][j];
				m3.elements[i][j] = temp + m3.elements[i][j];
			}
		}
	}
	return m3;
} catch (std::exception& e) {
	std::cerr << "Exception: " << e.what() << std::endl;
}
}
/**
*@brief Function to print out the matrix and display
*@return none
*/
template<class T, int m, int n>
void Matrix<T, m, n>::print() {
	flag2=true;
for (int i = 0; i < nrow; i++) {
	for (int j = 0; j < ncol; j++) {
		cout << elements[i][j] << " ";
	}
	cout << endl;
}
}


#endif
