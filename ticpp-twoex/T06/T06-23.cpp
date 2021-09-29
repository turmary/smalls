//: T06:T06-23.cpp
// A travel company wants to find out the average number of days people
// take to travel from one end of the continent to another.
// The problem is that in the survey, some people did not take
// a direct route and took much longer than is needed
// (such unusual data points are called “outliers”).
// Using the following generator, generate travel days into a vector.
// Use remove_if( ) to remove all the outliers in your vector.
// Take the average of the data in the vector
// to find out how long people generally take to travel.
/*
    int travelTime() {
        // The "outlier"
        if (rand() % 10 == 0)
            return rand() % 100;
        // Regular route
        return rand() % 10 + 10;
    }
*/
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

    int travelTime() {
        // The "outlier"
        if (rand() % 10 == 0)
            return rand() % 100;
        // Regular route
        return rand() % 10 + 10;
    }

vector<int> travels;

bool travels_if_remove(const int& v) {
	if (v < 10 || v >= 20) {
		cout <<"D " <<v <<endl;
		return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	srand(time(0));

	generate_n(back_inserter(travels), 1000, travelTime);

	auto endp = remove_if(travels.begin(), travels.end(), /*ptr_fun()*/ travels_if_remove);
	travels.erase(endp, travels.end());
	cout <<"# elements after removing: " <<travels.size() <<endl;

	double sum = accumulate(travels.begin(), travels.end(), int(0));
	cout <<"Average time: " << sum / travels.size() <<endl;

	exit(EXIT_FAILURE);
} ///:~
