//: T11:T11-10.c
//创建一个引用

int func(int i) {
	return ++i;
}

int func_char(char c) {
	return c;
}

int func_int(int i) {
	return i;
}

int func_float(float f) {
	return f;
}

int func_double(double d) {
	return d;
}

double df(int i) {
	return i;
}

double gd = 25.3;

int main(void) {
	double d;

	func_char('c');
	func_int(5);
	func_float(2.5f);
	func_double(25.4);
	d = gd;
	d = df(2);
	return func(3);
} ///:~
