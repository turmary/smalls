//: T10:second.h
//再创建另一个头文件
//它包含第一个头文件

#include "first.h"

namespace namespace_first {
	int second_print(void);
	int second_print(int* p);
}

namespace namespace_second {
	class CFirst {
	public:
		int hello(int arg) {};
	};
}

///:~
