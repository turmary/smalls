//: T10:first.h
//创建一个包含名字空间的头文件

namespace namespace_first {
	int first_print(void);
	int first_print(int* p);
	class CFirst {
	public:
		int hello(int arg) {};
	};
}

namespace {
	int null_print(void);
}

///:~
