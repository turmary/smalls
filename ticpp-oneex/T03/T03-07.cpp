//: T03:T03-07.cpp
//  π”√string*∫Õstring&

#include <string>
#include <iostream>
using namespace std;

int string_ptr(string* sp) {
	sp->append(string(__FUNCTION__) + "() ");
	return 0;
}

int string_ref(string& sr) {
	sr += string(__FUNCTION__) + "() ";
	return 0;
}

int main() {
	string s = "s-init ";

	string_ptr(&s);
	cout <<"after called string_ptr" <<endl;
	cout <<"s = " <<s <<endl;

	string_ref(s);
	cout <<"after called string_ref" <<endl;
	cout <<"s = " <<s <<endl;

} ///:~
