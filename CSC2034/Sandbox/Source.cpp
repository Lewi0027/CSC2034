#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int main() {

	Class1 experiment;
	Class1 experiment2 = 3;
	Class1 experiment3 = 'h';

	experiment.print();
	experiment2.print();
	experiment3.print();

	return 0;
}
