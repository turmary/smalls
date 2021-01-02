//: T05:T05-11.cpp
// Define a class template named Bob that takes a single type parameter.
// Make Bob a friend of all instances of a template class named Friendly,
// and a friend of a class template named Picky only
// when the type parameter of Bob and Picky are identical.
// Give Bob member functions that demonstrate its friendship.
#include <iostream>
#include "../require.h"
using namespace std;

template<class T> class Friendly;
template<class T> class Picky;

template<class T>
struct Bob {
	Bob() {
		cout <<"Class Bob T" <<endl;
	}
	template<class X> friend class Friendly;
	friend class Picky<T>;
private:
	int private_f0(int v) const {
		cout <<"private_f0 " <<v <<endl;
		return 0;
	}
};

template<class T>
class Friendly {
	int v;
public:
	Friendly(int arg) {
		v = arg;
	}
	template<class X> void accessBob(const class Bob<X>& b) {
		b.private_f0(v);
	}
};

template<class T>
class Picky {
	int v;
public:
	Picky(int arg) {
		v = arg;
	}
	template<class X> void accessBob(const class Bob<X>& b) {
		b.private_f0(v);
	}
};

int main(int argc, char* argv[]) {
	Bob<int> bi;
	Bob<double> bd;
	Friendly<int> fi(0);
	Friendly<double> fd(1);
	Picky<int> pi(2);
	Picky<double> pd(3);

	fi.accessBob(bi);
	fi.accessBob(bd);
	fd.accessBob(bi);
	fd.accessBob(bd);

	pi.accessBob(bi);
	/*
In instantiation of ‘void Picky<T>::accessBob(const Bob<X>&) [with X = double; T = int]’:
   required from here
error: ‘int Bob<T>::private_f0(int) const [with T = double]’ is private within this context
	*/
	#if 0
	pi.accessBob(bd);
	pd.accessBob(bi);
	#endif
	pd.accessBob(bd);

	return 0;
}
///:~
