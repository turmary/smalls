//: T08:T08-17.cpp
//修改ConstPointer.cpp
//将所有指针改为引用

void t(int&) {}

void u(const int& cip) {
	// assign of read-only reference 'cip'
	cip = 2; // Illegal -- modifies value
	int i = cip; // OK -- copies value

	// invalid initialization of reference of 
	// type 'int&' from expression of type 'const int'
	int& ip2 = cip; // Illegal: non-const
}

const char* v() {
	// Returns address of static character array:
	return "result of function v()";
}

const int* w() {
	static int i;
	return &i;
}

int main() {
	int x = 0;
	int& ip = x;
	const int& cip = x;
	t(ip);	// OK

	// invalid initialization of reference of 
	// type 'int&' from expression of type 'const int'
	t(cip); // Not OK
	u(ip);	// OK
	u(cip); // Also OK

	// invalid initialization of non-const reference of
	// type 'char&' from a temporary of type 'const char*'
	char& cp = v(); // Not OK
	const char* ccp = v(); // OK

	// invalid initialization of non-const reference of
	// type 'int&' from a remporary of type 'const int*'
	int& ip2 = w(); // Not OK
	const int* const ccip = w(); // OK
	const int* cip2 = w(); // OK

	// non-lvalue in assignment
	w() = 1; // Not OK
} ///:~
