//: T05:T05-08.cpp
//创建三种权限的成员
//并使用showMap()函数显示成员分布

#include <iostream>
using namespace std;

class Maps {
public:
	int pubFirst;
	int pubSecond;
private:
	int privFirst;
	int privSecond;
protected:
	int protFirst;
	int protSecond;
public:
	int showMap(void);
};

int Maps::showMap(void) {
	cout <<"pubFirst\t" <<&pubFirst <<endl;
	cout <<"pubSecond\t" <<&pubSecond <<endl;
	cout <<"privFirst\t" <<&privFirst <<endl;
	cout <<"privSecond\t" <<&privSecond <<endl;
	cout <<"protFirst\t" <<&protFirst <<endl;
	cout <<"protSecond\t" <<&protSecond <<endl;
	return 0;
}

int main() {
	Maps m;
	m.showMap();
} ///:~
