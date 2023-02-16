#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	//enum Gender {Male = 5, Female = 8};
#define Male 0
#define Female 1
	int inp;

	//Gender gender;
	cout << "Please enter gender (0 - Male; 1 - Female): ";
	cin >> inp;
	
	//gender = (Gender)inp;
	//cout << gender;

	//gender = (inp == 0) ? Male : Female;
	
	switch (inp) {
	case Male:
		cout << "Gender is male.";
		break;
	case Female:
		cout << "Gender is female.";
		break;
	default:
		cout << "Impossible value";
	}
	return 0;
}