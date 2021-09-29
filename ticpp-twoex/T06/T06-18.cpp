//: T06: T06-18.cpp
// Create an STL-style algorithm that is an overloaded version of for_each()
// which follows the second form of transform() and
// takes two input ranges so it can pass the objects of the second input range a
// to a binary function that it applies to each object of the first range.
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
using namespace std;

namespace std {
  /**
   *  @brief Perform an operation on corresponding elements of two sequences.
   *  @ingroup mutating_algorithms
   *  @param  __first1     An input iterator.
   *  @param  __last1      An input iterator.
   *  @param  __first2     An input iterator.
   *  @param  __binary_op  A binary operator.
   *  @return   none.
   *
   *  Applies the operator to the corresponding elements in the two
   *  input ranges and assigns the results to successive elements of the
   *  output sequence.
   *  Evaluates @p
   *  __binary_op(*(__first1+N),*(__first2+N)) for each
   *  @c N in the range @p [0,__last1-__first1).
   *
  */
  template<typename _InputIterator1, typename _InputIterator2,
	   typename _BinaryOperation>
    void
    for_each(_InputIterator1 __first1, _InputIterator1 __last1,
	      _InputIterator2 __first2, _BinaryOperation __binary_op)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>)
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>)
      __glibcxx_requires_valid_range(__first1, __last1);

      for (; __first1 != __last1; ++__first1, (void)++__first2)
	__binary_op(*__first1, *__first2);
      return;
    }
};

void pass_double(int& a, int& b) {
	cout <<a <<" : " <<b <<endl;
	return;
}

int main(int argc, const char* argv[]) {
	int array_as[] = {1, 3, 5, 8, 2};
	int array_bs[] = {6, 4, 3, 9, 7};
	vector<int> va(array_as, array_as + sizeof array_as / sizeof array_as[0]);
	vector<int> vb(array_bs, array_bs + sizeof array_bs / sizeof array_bs[0]);

	for_each(va.begin(), va.end(),
	             vb.begin(), pass_double);
	return 0;
} ///:~
