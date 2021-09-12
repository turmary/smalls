//: T06:T06-03.cpp
// Create a Sum function object template that
// will accumulate all the values in a range when used with
// for_each( ).
#include <iostream>
#include <algorithm>
#include <cctype>
#include <unistd.h>
#include "../require.h"
using namespace std;

template<class T>
class Sum {
private:
	bool copy;
	T* ptr;

public:
	Sum(T initial = T()): ptr(new T(initial)), copy(false) {}
	// using original space
	Sum(Sum& c): ptr(c.ptr), copy(true) {}
	~Sum() {
		if (!copy && ptr) delete ptr;
	}

	T operator() (T v) {
		// cout <<"*iter = " <<v <<" s = " <<*ptr <<endl;
		return *ptr += v;
	}

	T getSum(void) {
		return *ptr;
	}
};

int main(int argc, const char* argv[]) {
	int ia[] = { 1, 3, 5, 8, 2, 6, 9};
	size_t ia_sz = sizeof ia / sizeof ia[0];

	Sum<int> is;
	for_each(ia, ia + ia_sz, is);
	cout <<"ia sum = " <<is.getSum() <<endl;

	double da[] = { 1.0, 3.0, 5.0, 8.0, 2.0, 6.0, 9.0, 0.5};
	size_t da_sz = sizeof da / sizeof da[0];

	Sum<double> ds;
	for_each(da, da + da_sz, ds);
	cout <<"da sum = " <<ds.getSum() <<endl;
	return 0;
}
///:~

