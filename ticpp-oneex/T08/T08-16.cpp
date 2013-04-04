//: T08:T08-16.cpp
//修改ConstPointer.cpp
//观察每一行产生的错误信息

void t(int*) {}

void u(const int* cip) {
	// assignment of read-only location
	*cip = 2; // Illegal -- modifies value
	int i = *cip; // OK -- copies value

	// invalid conversion from 'const int*' to 'int*'
	int* ip2 = cip; // Illegal: non-const
}

const char* v() {
	// Returns address of static character array:
	return "result of function v()";
}

const int* const w() {
	static int i;
	return &i;
}

int main() {
	int x = 0;
	int* ip = &x;
	const int* cip = &x;
	t(ip);	// OK

	// invalid conversion from 'const int*' to 'int*'
	// initializing argument 1 of 'void t(int*)'
	t(cip); // Not OK
	u(ip);	// OK
	u(cip); // Also OK

	// invalid conversion from 'const char*' to 'char*'
	char* cp = v(); // Not OK
	const char* ccp = v(); // OK

	// invalid conversion from 'const int*' to 'int*'
	int* ip2 = w(); // Not OK
	const int* const ccip = w(); // OK
	const int* cip2 = w(); // OK

	// assignment of read-only location
	*w() = 1; // Not OK
} ///:~
