//: T10:mirror.h
//创建一个含有类Mirror的头文件

#ifndef __MIRROR_H__
#define __MIRROR_H__

class Mirror {
	Mirror* pm;
	bool b;
public:
	Mirror(void): pm(0), b(true) {}
	Mirror(Mirror* p): pm(p), b(false) {}
	bool test(void) {
		if (pm != 0) {
			return pm->test();
		}
		return b;
	}
};

#endif //__MIRROR_H__
///:~
