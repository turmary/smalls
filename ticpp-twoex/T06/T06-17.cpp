//: T06: T06-17.cpp
// Create an STL-style algorithm transform_if( ) following the first form of
// transform( ) which only performs transformations on objects that satisfy a
// unary predicate.
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
using namespace std;

  /**
   *  @brief Perform an operation on a sequence.
   *  @ingroup mutating_algorithms
   *  @param  __first     An input iterator.
   *  @param  __last      An input iterator.
   *  @param  __result    An output iterator.
   *  @param  __unary_op  A unary operator.
   *  @param  __pred    A predicate.
   *  @return   An iterator designating the end of the resulting sequence.
   *
   *  Applies the operator to each element in the input range @p [__first,__last)
   *  for which *  @p __pred returns true and assigns
   *  the results to successive elements of the output sequence.
   *
   *  @p unary_op must not alter its argument.
  */
  template<typename _InputIterator, typename _OutputIterator,
	   typename _UnaryOperation, typename _Predicate>
    _OutputIterator
    transform_if(_InputIterator __first, _InputIterator __last,
	      _OutputIterator __result, _UnaryOperation __unary_op, _Predicate __pred)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator,
	    // "the type returned by a _UnaryOperation"
	    __typeof__(__unary_op(*__first))>)
      __glibcxx_requires_valid_range(__first, __last);

      for (; __first != __last; ++__first, (void)++__result)
	if (__pred(*__first))
	  *__result = __unary_op(*__first);
      return __result;
    }


bool cxx_lower(char& c) {
  return islower(c);
}

int main(int argc, const char* argv[]) {
	string hello = "Hello World, Bye!";
	string result;

	transform_if(hello.begin(), hello.end(),
	             back_inserter(result),
	             bind2nd(plus<char>(), 1),
	             cxx_lower
	            );

	cout << hello <<endl;
	cout << result <<endl;
	return 0;
} ///:~
