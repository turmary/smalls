//: T10:second.cpp
//创建多个Mirror对象,并指定连接顺序

#include "mirror.h"

extern Mirror m1;
Mirror m2(&m1);
