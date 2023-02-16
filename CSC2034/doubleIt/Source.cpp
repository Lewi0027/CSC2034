#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <stdio.h>

void doubleIt(int&, int o = 5);

void doubleIt(double&, int o = 5);

using namespace std;

int num;

int main(int argc, char* argv[]) {
	double dnum = 11.22;
	num = atoi(argv[1]);
	//num = 33;

	doubleIt(num);
	doubleIt(dnum);
	cout << "Num is: " << num << endl;
	cout << "dNum is: " << dnum << endl;
}

void doubleIt(int& n, int o) {
	n = (o + n) * 2;
	return;
}

void doubleIt(double& n, int o) {
	n = (o + n) * 2;
	return;
}