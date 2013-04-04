//: T04:T04-23.cpp
//����һ��struct
//��װStash��Stack
//ʹ�ó�Ա������Ӻ͵õ�һ��
//{L} Stash
//{L} Stack

#include "Stash.h"
#include "Stack.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Lines {
	static const int bufsize = 80;
	int i;
	Stash* psh;
	Stack texts;

	void initialize(void);
	void cleanup(void);
	int add(const char* line);
	char* get(void);
};

void Lines::initialize(void) {
	texts.initialize();
	psh = NULL;
	i = 0;
	return;
}

void Lines::cleanup(void) {
	delete psh;
	texts.cleanup();
	return;
}

int Lines::add(const char* line) {
	if (0 == i) {
		psh = new Stash();
		psh->initialize(bufsize * sizeof(char));
	}
	psh->add(line);
	if (++i == 5) {
		texts.push(psh);
		psh = NULL;
		i = 0;
	}
	return 0;
}

char* Lines::get(void) {
	// ע��,add��get���ܴ������
	// ֻ���ȵ���add�ٵ���get
	if (i == 0) {
		delete psh;
		if ((psh = static_cast<Stash*>(texts.pop())) == NULL) {
			return NULL;
		}
	}
	if (--i < 0) {
		i += 5;
	}
	return static_cast<char*>(psh->fetch(i));
}

int main(int argc, char* argv[]) {
	requireArgs(argc, 1);
	ifstream in(argv[1]);

	Lines lineset;
	lineset.initialize();
	string line;
	while (getline(in, line)) {
		lineset.add(line.c_str());
	}

	Lines oforms;
	oforms.initialize();
	char* newline;
	while ((newline = lineset.get()) != NULL) {
		oforms.add(newline);
	}
	lineset.cleanup();

	while ((newline = oforms.get()) != NULL) {
		cout <<newline <<endl;
	}
	oforms.cleanup();
	return 0;
}
///:~
