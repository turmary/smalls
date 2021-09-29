//: T06: T06-19.cpp
// g++ --std=c++17
// Create a Matrix class template that is made from a vector<vector<T>>.
//
// Provide it with a
//   friend ostream& operator<<(ostream&, const Matrix&)
// to display the matrix.
//
// Create the following binary operations using the STL function objects where possible:
//   operator+(const Matrix&, const Matrix&)
// for matrix addition,
//
//   operator*(const Matrix&, const vector<T>&)
// for multiplying a matrix by a vector, and
//
//   operator*(const Matrix&, const Matrix&)
// for matrix multiplication.
//
// (You might need to look up the mathematical meanings of the matrix operations
// if you don’t remember them.)
// Test your Matrix class template using int and float.
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cctype>
#include "PrintSequence.h"
using namespace std;

template <class T>
class Matrix {
	vector<vector<T>> cv;

	Matrix<T>(vector<vector<T>>& iv) {
		cv = iv;
	}

public:
	/* Matrix<T>(const Matrix<T>& c) {
		cv = c.cv;
	}*/

	Matrix<T>(int rows, int columns, const T init_val[]) {
		int ind = 0;

		for (int i = 0; i < rows; i++) {
			vector<T> v;
			for (int j = 0; j < columns; j++)
				v.push_back(init_val[ind++]);
			cv.push_back(v);
		}
	}

	friend ostream& operator<<(ostream& os, const Matrix& mt) {
		for_each(mt.cv.begin(), mt.cv.end(), [&](const vector<T>& v)->void {
				for (auto p = v.begin(); p != v.end(); p++) {
					os <<'\t' <<*p;
					/*
					if (++p != v.end()) {
						cout << '\t';
						continue;
					}
					break;
					*/
				}
				os << '\n';
			}
		);
		return os;
	}

	const Matrix operator+ (const Matrix& b) const {
		vector<vector<T>> tv;

		for (auto p = cv.begin(), pb = b.cv.begin();
		  p != cv.end();
		  p++, pb++) {
			vector<T> ev;
			transform(p->begin(), p->end(),
			          pb->begin(),
			          back_inserter(ev), plus<T>());
			tv.push_back(ev);
		}
		return Matrix(tv);
	}
	const vector<T> operator* (const vector<T>& v) const {
		vector<T> tv;

		for (auto p = cv.begin(); p != cv.end(); p++) {
			T ev = inner_product(p->begin(), p->end(), v.begin(), T(0));
			tv.push_back(ev);
		}
		return tv;
	}
	// matrix transpose
	const Matrix operator~ (void) const {
		vector<vector<T>> tv;
		bool first = true;

		for (auto p = cv.begin(); p != cv.end(); p++) {
			if (first) {
				for_each(p->begin(), p->end(), [&](const T& v)->void {
					vector<T> ev(&v, &v + 1); // ev.push_back(v);
					tv.push_back(ev);
				});
			} else {
				auto q = tv.begin();
				for_each(p->begin(), p->end(), [&](const T& v)->void {
					q->push_back(v);
					q++;
				});
			}
			first = false;
		}
		return Matrix(tv);
	}
	const Matrix operator* (const Matrix& b) const {
		vector<vector<T>> tv;
		const Matrix<T> nb(~b);

		for (auto p = cv.begin(); p != cv.end(); p++) {
			vector<T> ev;

			for_each(nb.cv.begin(), nb.cv.end(), [&](const vector<T>& vv)->void {
				T v = inner_product(p->begin(), p->end(), vv.begin(), T(0));
				ev.push_back(v);
			});
			tv.push_back(ev);
		}
		return Matrix(tv);
	}
};


int main(int argc, const char* argv[]) {
	int init_arrayA[] = {
	  1, 3, 5, 8, 2,
	  6, 4, 3, 9, 7,
	  9, 7, 5, 3, 1,
	};
	Matrix<int> miA(3, 5, init_arrayA);

	int init_arrayB[] = {
	  3, 5, 3, 2, 1,
	  4, 3, 9, 7, 6,
	  7, 5, 8, 1, 9,
	};
	Matrix<int> miB(3, 5, init_arrayB);

	cout << "Matrix A:\n" << miA;
	cout << "Matrix B:\n" << miB;

	auto miC = miA + miB;
	cout << "Matrix C = A + B:\n" << miC;

	vector<int> vb(init_arrayB, init_arrayB + 5);
	vector<int> miD = miA * vb;
	print(miD.begin(), miD.end(), "Matrix D = A * B[ROW 0]", "\n\t");

	int init_arrayC[] = {
	  3, 4, 7, -1,
	  5, 3, 5, -3,
	  3, 9, 8, -5,
	  2, 7, 1, -7,
	  1, 6, 9, -9,
	};
	Matrix<int> miG(5, 4, init_arrayC);
	cout << "Matrix G:\n" << miG;

	auto miE = miA * miG;
	cout << "Matrix E = A * G:\n" << miE;

	auto miF = ~miB;
	cout << "Matrix F = ~B:\n" << miF;

	auto miH = miA * miF;
	cout << "Matrix H = A * ~B:\n" << miH;

	return 0;
} ///:~
