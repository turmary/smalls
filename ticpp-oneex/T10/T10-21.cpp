//: T10:T10-21.cpp
//修改OverridingAmbiguity.cpp
//指定divide函数并编译通过

#include "NamespaceMath.h"
#include "NamespaceOverriding2.h"

namespace BobsSuperDuperLibrary {
	class Widget { /* ... */ };
	class Poppit { /* ... */ };
	// ...
}

// Too much to type! I'll alias it:
namespace Bob = BobsSuperDuperLibrary;

namespace White {
	class Arm  { /* ... */ };
	class Leg  { /* ... */ };
	class Head { /* ... */ };
}

namespace Third {
	using namespace Bob;
	using namespace White;
}

namespace Math {
	int divide(int i, int j) {};
}

namespace Calculation {
	int divide(int i, int j) {};
}


void s(void) {
	using namespace Math;
	using namespace Calculation;

	// Everything's ok until:
	//! divide(1, 2); // Ambiguity
}

void s1(void) {
	using namespace Math;
	using namespace Calculation;

	Math::divide(1, 2);
	Calculation::divide(1, 2);
}

void s2(void) {
	using Math::divide;
	// using Calculation::divide;

	divide(1, 2);
}

int main() {
	using namespace Third;

	class Robot {
		Arm arm[4];
		Leg leg[16];
		Head head[3];
		// ...
	}xanthan;
	int i, j, k;

	Widget w;

	s();
	s1();
	s2();

	return 0;
}
///:~
