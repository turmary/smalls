//: T09:T09-03.cpp
//修改MacroSideEffects.cpp
//使宏BAND()能够正常运行

#include "../require.h"
#include <fstream>
using namespace std;

#define BAND(x) (((x)>5 && (x)<10) ? (x) : 0)

int main() {
	ofstream out("macro.out");
	assure(out, "macro.out");
	for(int i = 4; i < 11; i++) {
		int a = i;
		out << "a = " << a << endl << '\t';
		out << "BAND(++a)=" << (++a, BAND(a)) << endl;
		out << "\t a = " << a << endl;
	}
	return 0;
} ///:~
