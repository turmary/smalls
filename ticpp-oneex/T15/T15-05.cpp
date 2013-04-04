//: T15:T15-05.cpp
// Modify Instrument3.cpp by adding a virtual prepare()
// function. Call prepare inside tune()

#include <iostream>
using namespace std;
enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
public:
	virtual void play(note) const {
		cout << "Instrument::play" << endl;
	}
	virtual void prepare(void) {
		cout <<"Instrument::" <<__func__ <<"()" <<endl;
	}
};

// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {
public:
	// Override interface function:
	void play(note) const {
		cout << "Wind::play" << endl;
	}
	virtual void prepare(void) {
		cout <<"Wind::" <<__func__ <<"()" <<endl;
	}
};

void tune(Instrument& i) {
	// ...
	i.play(middleC);
	i.prepare();
}

int main() {
	Wind flute;
	tune(flute); // Upcasting
} ///:~
