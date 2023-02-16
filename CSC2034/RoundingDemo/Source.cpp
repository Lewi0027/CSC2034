#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

	float val = 10.0 / 3;
	float newVal;

	newVal = ceil(val * 100) / 100;
	printf("Calculated values: %f %f\n", val, newVal);

	cout << fixed << showpoint;
	cout << setprecision(2);

	//cout.setf(ios::fixed | ios::showpoint);
	//cout.precision(2);

	cout << "Price: " << newVal << endl;

	return 0;
}