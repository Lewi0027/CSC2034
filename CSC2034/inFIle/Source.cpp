#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

	ifstream infile;
	int num;
	bool flag;

	infile.open("numbers.dat");

	flag = false;
	while (infile >> num && !flag) {
		if (num >= 150) {
			flag = true;
		}
	}


	return 0;
}