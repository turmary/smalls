//: T04:T04-05.cpp
// We know that setw( ) allows for a minimum of characters read in,
// but what if you wanted to read a maximum?
// Write an effector that allows the user to specify
// a maximum number of characters to extract.
// Have your effector also work for output,
// in such a way that output fields are truncated,
// if necessary, to stay within width limits.
#include <iosfwd>
namespace std {
  template<typename _CharT>
  struct _Setmaxw { int _M_n; basic_string<_CharT>* _M_s; };

  /**
   *  @brief  Manipulator for @c max width.
   *  @param  n  The new width.
   *
   *  Sent to a stream object, this manipulator
   */
  template<typename _CharT>
  inline _Setmaxw<_CharT>
  setmaxw(int __n, basic_string<_CharT> & __s)
  {
    _Setmaxw<_CharT> __x;
    __x._M_n = __n;
    __x._M_s = &__s;
    return __x;
  }

  template<typename _CharT, typename _Traits>
    inline basic_istream<_CharT,_Traits>&
    operator>>(basic_istream<_CharT,_Traits>& __is, _Setmaxw<_CharT> __f)
    {
      _CharT c;
      for (int i = 0; i < __f._M_n; i++) {
        __is >> c;
        __f._M_s -> push_back(c);
      }
      return __is;
    }

  template<typename _CharT, typename _Traits>
    inline basic_ostream<_CharT,_Traits>&
    operator<<(basic_ostream<_CharT,_Traits>& __os, _Setmaxw<_CharT> __f)
    {
      for (int i = 0; i < __f._M_n; i++) {
        __os << (*__f._M_s)[i];
      };
      return __os;
    }

// template declaration
  extern template ostream& operator<<(ostream&, _Setmaxw<char>);
  extern template istream& operator>>(istream&, _Setmaxw<char>);
#if defined (_GLIBCXX_USE_WCHAR_T)
  template wostream& operator<<(wostream&, _Setmaxw<wchar_t>);
  template wistream& operator>>(wistream&, _Setmaxw<wchar_t>);
#endif
}

#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, const char* argv[]) {
	string o("hello world!");
	cout <<"<< first 5 chars of '" <<o <<"' is\n  *"
	     <<setmaxw(5, o) <<'*' <<endl;

	stringstream ss(o);
	string s;
	ss >>setmaxw(3, s);
	cout <<">> first 3 chars of '" <<o
	     <<"' is\n  *" <<s <<"*" <<endl;
	return 0;
}

namespace std {
// template implementation
  template ostream& operator<<(ostream&, _Setmaxw<char>);
  template istream& operator>>(istream&, _Setmaxw<char>);
}
///:~

