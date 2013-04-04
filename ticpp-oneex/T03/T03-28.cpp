//: T03:T03-28.cpp
//������doubleָ��ʹ�С�����ĺ���
//����ĳ�������
//�ı��������ֵ����

#include <iostream>
using namespace std;

void print_array(double* p, int size) {
	for (int i = 0; i < size; i++) {
		cout <<"double[" <<i <<"] = " <<p[i] <<endl;
	}
	return;
}

int main() {
	double double_arr[] = {1.1, 2.2, 3.3, 4.4, 5.5,};

	print_array(double_arr, sizeof double_arr / sizeof double_arr[0]);

	unsigned char* s = reinterpret_cast<unsigned char*>(double_arr);
	for (int i = 0; i < sizeof double_arr; i++) {
		s[i] = static_cast<char>(1);
	}

	print_array(double_arr, sizeof double_arr / sizeof double_arr[0]);

	return 0;
} ///:~
