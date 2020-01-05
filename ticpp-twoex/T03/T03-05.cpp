//: T03:T03-05.cpp
// reorder string literals to
// I moved down the canyon with the mountain bikers. \
// The mountain bikers passed by me too close for comfort. \
// So I went hiking instead.
#include <string>
#include <iostream>
#include "../require.h"
using namespace std;

string one("I walked down the canyon with the moving mountain bikers.");
string two("The bikers passed by me too close for comfort.");
string three("I went hiking instead.");

int main(int argc, const char* argv[]) {
	size_t move_start = one.find('m');
	size_t move_end	 = one.rfind('v');
	string move = one.substr(move_start, move_end - move_start + 1);

	size_t walk_start = one.find('w');
	size_t walk_end	 = one.find('k',	walk_start);
	string walk = one.substr(walk_start, walk_end - walk_start + 1);

	one.replace(walk_start,	walk.size(),	move);

	size_t moving_start = one.find('m', walk_start + 1);
	size_t moving_end	 = one.find(' ', move_start);
	one.erase(moving_start,	moving_end - moving_start + 1);

	size_t mountain_start = one.rfind('m');
	size_t mountain_end   = one.rfind(' ');
	string mountain = one.substr(mountain_start, mountain_end - mountain_start + 1);
	two.insert(two.find(' ') + 1, mountain);

	string space = one.substr(one.find(' '), 1);

	string so = one.substr(one.find('s'), 1);
	so += one.substr(one.find('o'), 1);
	so[0] = toupper(so[0]);

	one.append(space).append(two);
	one.append(space).append(so);
	one.append(space).append(three);

	cout <<one <<endl;
	return 0;
}
///:~
