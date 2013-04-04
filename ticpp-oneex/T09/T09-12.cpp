//: T09:T09-12.cpp
//修改Cpptime.cpp
//使其从程序开始运行时开始计时
//直到用户按确认键或者回车键

#include "../require.h"
#include "Cpptime.h"
#include <cstring>
#include <iostream>
using namespace std;

#define DEBUG(x) cout << #x " = " << x << endl
#define TRACE(s) do {cerr << #s <<endl; s ; }while(0)
#define FIELD(a,index)						\
	private:						\
		char* a##_string_##index; int a##_size_##index ;\
	public:							\
		int set_##a##_##index (char* cp) {		\
			a##_string_##index = cp;		\
			a##_size_##index = strlen(cp);		\
		}						\
		int get_##a##_##index (void) {			\
			cout << a##_string_##index ;		\
			cout << a##_size_##index ;		\
			cout <<endl;				\
		};;;


class FieldIndex {
private:
	FIELD(one, 0);
	FIELD(one, 1);
	FIELD(one, 2);
public:
	int visitOne(int index, char* cp) {
		if (index == 0) {
			one_string_0 = cp;
			one_size_0 = strlen(cp);
		} else
		if (index == 1) {
			one_string_1 = cp;
			one_size_1 = strlen(cp);
		} else
		if (index == 2) {
			one_string_2 = cp;
			one_size_2 = strlen(cp);
		}
		return 0;
	}

	int print(void) {
		cout <<one_size_0 <<one_string_0 <<endl;
		cout <<one_size_1 <<one_string_1 <<endl;
		cout <<one_size_2 <<one_string_2 <<endl;
		return 0;
	}
};

int main(int argc, char* argv[]) {
	Time start;

	requireArgs(argc, 1);
	string s(argv[1]);

	for (; s != "";) {
		DEBUG(s);
		TRACE(s.erase(0, 1));
	}

	FieldIndex fi;
	fi.visitOne(0, "hello");
	fi.visitOne(1, "world");
	fi.visitOne(2, "!");
	fi.print();

	fi.set_one_0("fuck");
	fi.set_one_1("the");
	fi.set_one_2("world");

	fi.get_one_0();
	fi.get_one_1();
	fi.get_one_2();

	char c;

	while ((c = cin.get()) != 0x0C && (c != 0x0A)) {
		cout <<"get() = " <<c <<endl;
	}

	Time end;
	cout <<endl;

	cout << "start = " << start.ascii();
	cout << "end = " << end.ascii();
	cout << "delta = " << end.delta(&start);

	return 0;
} ///:~
