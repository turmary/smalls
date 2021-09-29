//: T06:T06-20.cpp
//{L} ../T03/T03Util
// Using the characters
//   "~`!@#$%^&*( )_-+=}{[]|\:;"'<.>,?/",
// generate a code book using an input file given on the command line
// as a dictionary of words.
// Don’t worry about stripping off the non-alphabetic characters
// nor worry about case of the words in the dictionary file.
// Map each permutation of the character string to a word such as the following:
//  "=')/%[}]|{*@?!"`,;>&^-~_:$+.#(<\"   apple
//  "|]\~>#.+%(/-_[`':;=}{*"$^!&?),@<"   carrot
//  "@=~['].\/<-`>#*)^%+,";&?!_{:|$}("   Carrot
// etc.
// Make sure that no duplicate codes or words exist in your code book.
// Use lexicographical_compare( ) to perform a sort on the codes.
//
// Use your code book to encode the dictionary file.
// Decode your encoding of the dictionary file,
// and make sure you get the same contents back.
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../require.h"
#include "../T03/T03Util.h"
using namespace std;

string INIT_CODE = "~`!@#$%^&*( )_-+=}{[]|" "\\:;\"" "'<.>,?/";
                   
vector<string> words;
vector<string> dictionary;
bool encrypt;

int scanline(const string& line) {
	vector<string> sv;

	sv = to_words(line);
	for (size_t i = 0; i < sv.size(); i++) {
		// find duplicated
		if (words.end() != find(words.begin(), words.end(), sv[i])) {
			continue;
		}
		words.push_back(sv[i].c_str());
	}
	return 0;
}

bool string_lexicographical(const string& left, const string& right) {
	return lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

int encode_dictionary(ifstream& inf, string name) {
	// Read input file line by line
	// then find all words.
	string line;
	while (getline(inf, line)) {
		scanline(line);
	}

	sort(words.begin(), words.end(), string_lexicographical);

	ofstream ofcodebook(".codebook", ios::binary);

	cout <<"### All words: ###" <<endl;
	for (size_t i = 0; i < words.size(); i++) {
		cout <<words[i] <<endl;
		ofcodebook << words[i] <<endl;
		dictionary.push_back(INIT_CODE);
		next_permutation(INIT_CODE.begin(), INIT_CODE.end());
	}
	ofcodebook.close();

	inf.clear();
	inf.seekg(0, inf.beg);

	string on(name);
	name.append(".encrypt");
	ofstream ofencrypt(name.c_str(), ios::binary);

	while (getline(inf, line)) {
		vector<string> sv;

		sv = to_words(line);
		for (size_t i = 0; i < sv.size(); i++) {
			vector<string>::iterator p;
			if (words.end() == (p = find(words.begin(), words.end(), sv[i]))) {
				// not found the word
				continue;
			}
			// cout <<(p - words.begin()) <<endl;
			ofencrypt << dictionary[p - words.begin()] <<endl;
		}
	}
	ofencrypt.close();
	return 0;
}

int decode_dictionary(ifstream& inf, string name) {
	ifstream fcodebook(".codebook", ios::binary);
	string line;

	while (getline(fcodebook, line)) {
		words.push_back(line);
	}

	cout <<"### All words: ###" <<endl;
	for (size_t i = 0; i < words.size(); i++) {
		cout <<words[i] <<endl;
		dictionary.push_back(INIT_CODE);
		next_permutation(INIT_CODE.begin(), INIT_CODE.end());
	}

	cout <<"### All text: ###" <<endl;
	int counter = 0;
	while (getline(inf, line)) {
		vector<string>::iterator p;
		if (dictionary.end() == (p = find(dictionary.begin(), dictionary.end(), line))) {
			// not found the code
			continue;
		}
		// cout <<(p - dictionary.begin()) <<endl;
		cout << words[p - dictionary.begin()] <<' ';
		if (++counter % 16 == 0) {
			cout <<endl;
		}
	}
	return 0;
}

int main(int argc, char* argv[]) {
	requireArgs(argc, 2, "T06-20 <e|d> <dictionary-file>");

	switch (*argv[1]) {
	case 'e':
	case 'E':
		encrypt = true;
		break;

	case 'd':
	case 'D':
		encrypt = false;
		break;

	default:
		cerr << "Usage: T06-20 <e|d> <dictionary-file>";
		exit(EXIT_FAILURE);
	}

	// See if input file exists
	ifstream inf(argv[2]);
	if (!inf) {
		cerr << "error opening file: " << argv[2] << endl;
		exit(EXIT_FAILURE);
	}

	if (encrypt) {
		encode_dictionary(inf, argv[2]);
	} else {
		decode_dictionary(inf, argv[2]);
	}
	exit(EXIT_FAILURE);
} ///:~
