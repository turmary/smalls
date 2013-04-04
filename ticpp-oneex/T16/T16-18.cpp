//: T16:T16-18.cpp
// Templatize the IntArray class in
// IostreamOperatorOverloading.cpp from Chapter12,
// templatizing both the type of object that is contained and
// the size of the internal array.
#include "../require.h"
#include <iostream>
#include <sstream> // "String streams"
#include <cstring>
using namespace std;

template<class T,int ssz = 5>
class IntArray;

template<class T, int ssz>
ostream& operator<<(ostream& os, const IntArray<T,ssz>& ia) {
	for(int j = 0; j < ia.sz; j++) {
		os << ia.i[j];
		if(j != ia.sz -1)
			os << ", ";
	}
	os << endl;
	return os;
}

template<class T, int ssz>
istream& operator>>(istream& is, IntArray<T,ssz>& ia){
	for(int j = 0; j < ia.sz; j++)
		is >> ia.i[j];
	return is;
}

template<class T,int ssz>
class IntArray {
	enum { sz = ssz };
	T i[sz];
public:
	IntArray() { memset(i, 0, sz* sizeof(*i)); }
	T& operator[](int x) {
		require(x >= 0 && x < sz,
			"IntArray::operator[] out of range");
		return i[x];
	}
	friend ostream& operator<< <T,ssz>(ostream& os, const IntArray<T,ssz>& ia);
	friend istream& operator>> <T,ssz>(istream& is, IntArray<T,ssz>& ia);
};

int main() {
	stringstream input("47 34 56 92 103 17 204 33 52 88 04");
	IntArray<int, 10> I;
	input >> I;
	I[4] = -1; // Use overloaded operator[]
	cout << I;
} ///:~
