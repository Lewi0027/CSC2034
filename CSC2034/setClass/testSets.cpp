#include <iomanip>
#include "sets.h"

using namespace std;

int main() {

	//Test initialization with an int value
	sets Test1(7);
	Test1.print();

	//Test the += operator
	//check for duplicate values
	sets Test2;
	Test2.print();
	Test2 += 1;
	Test2 += 2;
	Test2 += 3;
	Test2 += 4;
	Test2 += 3;
	Test2.print();

	sets Test3(Test2);
	Test3.print();
	Test3 -= 5;
	Test3 -= 4;
	Test3 -= 1;
	Test3.print();

	return 0;
}