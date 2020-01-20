//: T04:T04-08.cpp
//  Make a Person struct with fields such as name, age, address, etc.
// Make the string fields fixed-size arrays.
// The social security number will be the key for each record.
// Implement the following Database class: 
// Write some Person records to disk (do not keep them all in memory).
// When the user requests a record, read it off the disk and return it.
// The I/O operations in the DataBase class use read( ) and write( ) to process all Person records.
#include <stdint.h>
#include <iostream>
#include <fstream>
#include "../require.h"
using namespace std;

struct Person {
	size_t ssn;
	char name[12];
	int age;
	char address[44];

	friend ostream& operator<<(ostream& os, const Person& ps) {
		if (!ps.ssn) {
			os <<"No valid record #" <<endl;
		} else {
			os <<ps.ssn <<"\t";
			os <<ps.name <<"\t";
			os <<ps.age <<"\t";
			os <<ps.address;
		}
		return os;
	}
};


class DataBase {
	fstream& fs;
public:
	DataBase(fstream& fs): fs(fs) { }
	~DataBase() { }
	// Find where a record is on disk
	size_t query(size_t ssn);
	// Return the person at rn (record number)
	Person retrieve(size_t rn);
	// Record a record on disk
	void add(const Person& p);
};

size_t DataBase::query(size_t ssn) {
	Person ps;

	fs.seekg(0, ios::beg);
	size_t rn;
	for (rn = 0; !fs.eof() && !fs.fail(); rn++) {
		fs.read(reinterpret_cast<char*>(&ps), sizeof ps);
		if (ps.ssn == ssn) {
			break;
		}
	}
	if (ps.ssn != ssn) {
		return string::npos;
	}
	return rn;
}

Person DataBase::retrieve(size_t rn) {
	Person ps;

	fs.seekg(rn * sizeof ps, ios::beg);
	fs.read(reinterpret_cast<char*>(&ps), sizeof ps);
	if (!fs) {
		ps.ssn = 0;
		/*
		cerr <<__LINE__ <<": Rdstate = 0x"
		                <<fs.rdstate() <<endl;
		*/
		fs.clear();
	}
	return ps;
}

void DataBase::add(const Person& p) {
	if (query(p.ssn) != string::npos) {
		return;
	}
	fs.clear();
	fs.seekp(0, ios::end);
	fs.write(reinterpret_cast<const char*>(&p), sizeof p);
	return;
}

int main(int argc, const char* argv[]) {
	requireArgs(argc, 1, "T04-08 <a|d|i|r|s>\n"
	  "  a -- add a new record\n"
	  "  d -- dump all records\n"
	  "  i -- import records from stdin\n"
	  "  r -- retrieve a record by #\n"
	  "  s -- search a record by ssn\n"
	);

	const char* fname = "Person.db";
	fstream fs(fname, ios::in | ios::out | ios::binary);
	if (!fs) {
		fs.open(fname, ios::out | ios::binary | ios::app);
		fs.open(fname, ios::in | ios::out | ios::binary);
	}

	DataBase db(fs);
	Person ps;

	int rt = 0;
	switch (*argv[1]) {
	case 'a':
	case 'A':
		cout <<"Input ==> id name age address" <<endl;
		cin >>ps.ssn >>ps.name >>ps.age >>ps.address;
		db.add(ps);
		break;

	case 'd':
	case 'D':
		for (size_t i = 0; ; i++) {
			ps = db.retrieve(i);
			if (ps.ssn == 0) {
				break;
			}
			cerr <<ps <<endl;
		}
		break;

	case 'i':
	case 'I':
		while (true) {
			cin >>ps.ssn >>ps.name >>ps.age >>ps.address;
			if (!cin) break;
			db.add(ps);
		}
		break;

	case 'r':
	case 'R':
		int rn;

		cout <<"Enter record # to show the Person" <<endl;
		cin >>rn;
		ps = db.retrieve(rn);
		cout <<"<== id name age address" <<endl;
		cout <<ps <<endl;
		break;

	case 's':
	case 'S':
		cout <<"Enter id to search" <<endl;
		cin >>ps.ssn;
		cout <<db.query(ps.ssn) <<endl;
		break;

	default:
		cerr <<"Wrong parameter " <<argv[1] <<endl;
		rt = 1;
		break;
	}

	// fs.close();
	return rt;
}
///:~
