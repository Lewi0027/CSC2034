#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <stdio.h>

void doubleIt(int&);

void doubleIt(double&);

using namespace std;

int num;

int main(int argc, char* argv[]) {
	double dnum = 11.22;
	num = atoi(argv[1]);

	doubleIt(num);
	doubleIt(dnum);
	cout << "Num is: " << num << endl;
	cout << "dNum is: " << dnum << endl;

	return 0;
}

void doubleIt(int& n) {
	n *= 2;
	return;
}

void doubleIt(double& n) {
	n *= 2;
	return;
}