#include <iostream>
#include "sets.h"

using namespace std;

int main() {

	//Test initialization with an int value
	sets Test1(1);
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

	//Test copy vector
	sets Test3(Test2);
	Test3.print();

	//Test the -= operator (remove elements from set)
	//state if value not in set
	Test3 -= 5;
	Test3 -= 4;
	Test3 -= 1;
	Test3.print();

	//Test the * operator (set intersection)
	sets Test4;
	Test3 += 5;
	Test3 += 6;
	Test2.print(1);
	std::cout << "intersect ";
	Test3.print(1);
	std::cout << " = ";
	Test4 = Test3 * Test2;
	Test4.print();

	//Test the + operator (set union)
	sets Test5;
	Test2.print(1);
	std::cout << "union ";
	Test3.print(1);
	std::cout << " = ";
	Test5 = Test2 + Test3;
	Test5.print();

	//Test the - operator (set difference)
	sets Test6, Test7;
	Test2.print(1);
	std::cout << "difference ";
	Test3.print(1);
	std::cout << " = ";
	Test6 = Test2 - Test3;
	Test6.print();
	Test3.print(1);
	std::cout << "difference ";
	Test2.print(1);
	std::cout << " = ";
	Test7 = Test3 - Test2;
	Test7.print();


	return 0;
}