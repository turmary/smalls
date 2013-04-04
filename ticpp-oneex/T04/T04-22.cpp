//: T04:T04-22.cpp
//创建一个存放Stash的Stack
//{L} Stash
//{L} Stack

#include "Stash.h"
#include "Stack.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int bufsize = 80;

int main(int argc, char* argv[]) {
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	Stack texts;
	texts.initialize();

	string line;
	int i = 0;
	Stash* psh;
	while (getline(in, line)) {
		if (0 == i) {
			psh = new Stash();
			psh->initialize(bufsize * sizeof(char));
			texts.push(psh);
		}
		psh->add(line.c_str());
		if (++i == 5) {
			i = 0;
		}
	}

	Stack oforms;
	oforms.initialize();
	while ((psh = static_cast<Stash*>(texts.pop())) != NULL) {
		oforms.push(psh);
	}
	texts.cleanup();

	while ((psh = static_cast<Stash*>(oforms.pop())) != NULL) {
		for(int i = 0; i < psh->count(); i++) {
			char* s = static_cast<char*>(psh->fetch(i));
			cout <<s <<endl;
		}
		psh->cleanup();
		delete psh;
	}
	oforms.cleanup();
	return 0;
}
///:~
