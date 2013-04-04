//: T16:T16-06.cpp
// Using the Standard C++ Library vector as an underlying
// implementation, create a Set template class that accepts 
// only one of each type of object that you put into it. 
#include <fstream>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <iterator>
#include <string>
#include "../require.h"
using namespace std;

template<class T>
class Set {
public:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef T const & const_reference;
	typedef unsigned size_type;
	typedef int difference_type;
	vector<value_type> vt;
	typedef typename vector<value_type>::iterator vt_it_t;

	class iterator;
	friend class iterator;

	class iterator {
		friend class Set;
		vt_it_t it;
	public:
		iterator() {}
		iterator(vt_it_t it): it(it) {}
		iterator(const Set& sr) {
			it = const_cast<Set&>(sr).vt.begin();
		}
		iterator(const Set& sr, bool) {
			it = const_cast<Set&>(sr).vt.end();
		}
		iterator& operator=(const iterator& o) {
			it = o.it;
		}
		bool operator != (const iterator& o) {
			return !(it == o.it);
		}
		bool operator == (const iterator& o) {
			return it == o.it;
		}
		iterator operator++ () {
			vt_it_t o_it = it++;
			return iterator(o_it);
		}
		iterator& operator++ (int) {
			it++;
			return *this;
		}
		reference operator* () { return *it; }
	};
	typedef iterator const_iterator;
	/*
	class reverse_iterator {
	};
	typedef reverse_iterator const_reverse_iterator;
	*/
	iterator begin() const {
		return iterator(*this);
	}
	iterator end() const {
		return iterator(*this, true);
	}
	size_type size() const {
		return vt.size();
	}
	iterator insert(const value_type& x) {
		vt_it_t it;
		for (it = vt.begin(); it != vt.end(); it++) {
			if (!(*it < x)) break;
		}
		if (it != vt.end() && *it == x) {
			return iterator(it);
		}
		vt.insert(it, x);
	}
	size_type max_size() const {
		return vt.max_size();
	}
	bool empty() const {
		return vt.size() == 0;
	}
	Set() {}
	Set(const Set& sr) { vt = sr.vt; }
	void erase(iterator pos) {
		vt.erase(pos.it);
	}
	void erase(iterator first, iterator last) {
		vt.erase(first.it, last.it);
	}
	void clear() {
		vt.clear();
	}
	bool operator==(const Set& sx) {
		return vt == sx.vt;
	}
	bool operator< (const Set& sx) {
		return vt < sx.vt;
	}
};

void wordSet(const char* fileName) {
	ifstream x(fileName);
	require(x, fileName);
	string y;
	Set<string> w;
	while (x >> y) {
		w.insert(y);
	}
	Set<string>::iterator it = w.begin();
	int j = 0;
	for (it = w.begin(); it != w.end(); it++) {
		cout <<"[ " <<setw(3) <<j++ <<"] " <<*it <<endl;
	}
	cout <<endl;
	cout << "Number of unique words:"
			 << w.size() << endl;

	Set<int> s;
	Set<int>::iterator sit;
	for (int i = 0; i < 10; i++) {
		s.insert(i);
		s.insert(i + 3);
	} /* { { { } } } */
	for (sit = s.begin(); sit != s.end(); sit++) {
		cout <<*sit <<" ";
	}
	cout <<endl;

	int i;
	for (i = 0, sit = s.begin(); i < 5; i++) {
		s.erase(sit);
	}
	for (sit = s.begin(); sit != s.end(); ++sit) {
		cout <<*sit <<" ";
	}
	cout <<endl;

	cout <<"Before clear(), count of integers:" <<s.size() <<endl;
	cout <<"empty() = " <<s.empty() <<endl;
	s.clear();
	cout <<"After  clear(), count of integers:" <<s.size() <<endl;
	cout <<"empty() = " <<s.empty() <<endl;
}

int main(int argc, char* argv[]) {
	if(argc > 1)
		wordSet(argv[1]);
	else
		wordSet("T16-06.cpp");
}///:~
