//: T09:T09-01.cpp
//修改宏F修之正确运行

//! #define F (x) (x + 1)
#define F(x) (x + 1)

#define FLOOR(x,b) ((x)>=(b)?0:1)

int main() {
	F(1);
	F (1);

	int i = 5;
	FLOOR(i++, i++);
	return 0;
} ///:~
