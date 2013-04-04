//: T16:TPStash2Vector.h
// Modify TPStash2.h so that it uses a Standard C++
// Library vector as its underlying implementation. Make
// sure that you don't change the interface, so that
// TPStash2Test.cpp works unchanged.
#ifndef __TPSTASH2VECTOR_H__
#define __TPSTASH2VECTOR_H__
#include "../require.h"
#include <vector>
#include <cstring>
#include <cstdlib>

template<class T>
class PStash {
	std::vector<T*> vs;
public:
	PStash() {}
	~PStash();
	int add(T* element);
	T* operator[](int index) const;
	T* remove(int index);
	int count() const { return vs.size(); }

	// Nested iterator class:
	class iterator; // Declaration required
	friend class iterator; // Make it a friend
	class iterator { // Now define it
		PStash& ps;
		int index;
	public:
		iterator(PStash& pStash)
			: ps(pStash), index(0) {}
		// To create the end sentinel:
		iterator(PStash& pStash, bool)
			: ps(pStash), index(ps.vs.size()) {}
		// Copy-constructor:
		iterator(const iterator& rv): ps(rv.ps), index(rv.index) {
		}
		iterator& operator=(const iterator& rv) {
			ps = rv.ps;
			index = rv.index;
			return *this;
		}
		iterator& operator++() {
			require(++index <= ps.vs.size(),
				"PStash::iterator::operator++ "
				"moves index out of bounds");
			return *this;
		}
		iterator& operator++(int) {
			return operator++();
		}
		iterator& operator--() {
			require(--index >= 0,
				"PStash::iterator::operator-- "
				"moves index out of bounds");
			return *this;
		}
		iterator& operator--(int) { 
			return operator--();
		}
		// Jump interator forward or backward:
		iterator& operator+=(int amount) {
			require(index + amount < ps.vs.size() && 
				index + amount >= 0, 
				"PStash::iterator::operator+= "
				"attempt to index out of bounds");
			index += amount;
			return *this;
		}
		iterator& operator-=(int amount) {
			require(index - amount < ps.vs.size() && 
				index - amount >= 0, 
				"PStash::iterator::operator-= "
				"attempt to index out of bounds");
			index -= amount;
			return *this;
		}
		// Create a new iterator that's moved forward
		iterator operator+(int amount) const {
			iterator ret(*this);
			ret += amount; // op+= does bounds check
			return ret;
		}
		iterator operator-(int amount) const {
			iterator ret(*this);
			ret -= amount;
			return ret;
		}
		T* current() const {
			return ps.vs[index];
		}
		T* operator*() const { return current(); }
		T* operator->() const { 
			require(ps.vs[index] != 0, 
				"PStash::iterator::operator->returns 0");
			return current(); 
		}
		// Remove the current element:
		T* remove(){
			return ps.remove(index);
		}
		// Comparison tests for end:
		bool operator==(const iterator& rv) const {
			return index == rv.index;
		}
		bool operator!=(const iterator& rv) const {
			return index != rv.index;
		}
	};
	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this, true);}
};

// Destruction of contained objects:
template<class T>
PStash<T>::~PStash() {
	while (!vs.empty()) {
		vs.pop_back();
	}
}

template<class T>
int PStash<T>::add(T* element) {
	vs.push_back(element);
	return(vs.size() - 1); // Index number
}

template<class T> inline
T* PStash<T>::operator[](int index) const {
	require(index >= 0, "PStash::operator[] index negative");
	if(index >= vs.size()) {
		return 0;		// To indicate the end
	}
	require(vs[index] != 0, "PStash::operator[] returned null pointer");
	return vs[index];
}

template<class T>
T* PStash<T>::remove(int index) {
	// operator[] performs validity checks:
	T* v = operator[](index);
	// "Remove" the pointer:
	vs[index] = 0;
	return v;
}

#endif//__TPSTASH2VECTOR_H__
///:~
