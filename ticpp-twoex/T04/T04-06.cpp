//: T04:T04-06.cpp
// Demonstrate to yourself that if the fail or bad bit is set,
// and you subsequently turn on stream exceptions,
// that the stream will immediately throw an exception.
#include <iostream>
#include <sstream>

namespace std {
	struct _STREAM_exception { char c; };

	istream& operator>>(istream& __is, _STREAM_exception& __f)
	{
		__is >>__f.c;
		switch (__f.c) {
		case 'b':
			__is.setstate(ios::badbit);
			break;
		case 'e':
			__is.setstate(ios::eofbit);
			break;
		case 'f':
			__is.setstate(ios::failbit);
			break;
		default:
			break;
		}
		return __is;
	}
}

using namespace std;

int main(int argc, const char* argv[]) {
	_STREAM_exception se;

	string o("hello b, world f !");
	stringstream ss(o);

	try {
		while (ss) {
			se.c = '\'';
			ss >> se;
			cerr << " :" <<se.c;
			if (!ss) {
				ss.clear();
				ss.exceptions(ios::badbit | ios::eofbit | ios::failbit);
				cerr <<"***";
			}
			cerr <<endl;
		}
	} catch (ios_base::failure& e) {
		cerr <<"Reading _STREAM_exception exception: " <<e.what() <<endl;
		throw;
	}
	return 0;
}
///:~
