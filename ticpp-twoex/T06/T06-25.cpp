//: T06:T06-25.cpp
// The army wants to recruit people from its selective service list.
// They have decided to recruit those that signed up for the service
// in 1997 starting from the oldest down to the youngest.
// Generate an arbitrary amount of people (give them data members
// such as age and yearEnrolled) into a vector.
// Partition the vector so that those who enrolled in 1997
// are ordered at the beginning of the list,
// starting from the youngest to the oldest,
// and leave the remaining part of the list sorted according to age.
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;

struct potential_soldier {
	int age;
	int yearEnrolled;
};

potential_soldier GenSoldier() {
	potential_soldier p;

	p.age = rand();
	p.yearEnrolled = 1992 + rand() % 6;
	return p;
}

vector<potential_soldier> soldiers;

bool year_enrolled_is_1997(const potential_soldier& p) {
	return (p.yearEnrolled == 1997);
}

bool year_enrolled_not_1997(const potential_soldier& a, const potential_soldier& b) {
	/*
	if (a.yearEnrolled == 1997) {
		return true;
	}
	*/
	if (b.yearEnrolled == 1997) {
		return false;
	}
	return true;
}

bool operator< (const potential_soldier& a, const potential_soldier& b) {
	return a.age < b.age;
}

int main(int argc, char* argv[]) {
	int soldier_counter = 0;
	srand(time(0));

	generate_n(back_inserter(soldiers), 100, GenSoldier);

	cout <<"### All potential soldiers: ###" <<endl;
	for (auto s: soldiers) {
		cout <<s.yearEnrolled <<" :" <<setw(5) <<left <<s.age <<'\t';
		if (++soldier_counter % 4 == 0)
			cout <<endl;
	}
	cout <<endl;

	/*
	int enrolled1997 = count_if(soldiers.begin(), soldiers.end(), year_enrolled_is_1997);
	vector<potential_soldier>::iterator join_end = soldiers.begin() + enrolled1997;
	partial_sort(soldiers.begin(), join_end, soldiers.end(), year_enrolled_not_1997);

	cout <<endl;
	cout <<"Count of people enrolled in 1997: " <<enrolled1997 <<endl;
	cout <<endl;
	*/
	vector<potential_soldier>::iterator join_end;
	join_end = /*stable_*/partition(soldiers.begin(), soldiers.end(), year_enrolled_is_1997);
	cout <<endl;
	cout <<"Count of people enrolled in 1997: " <<join_end - soldiers.begin() <<endl;
	cout <<endl;

	sort(soldiers.begin(), join_end);
	sort(join_end, soldiers.end());

	cout <<"### All potential soldiers sorted: ###" <<endl;
	soldier_counter = 0;
	for (auto s: soldiers) {
		cout <<s.yearEnrolled <<" :" <<setw(5) <<left <<s.age <<'\t';
		if (++soldier_counter % 4 == 0)
			cout <<endl;
	}
	cout <<endl;

	exit(EXIT_FAILURE);
} ///:~
