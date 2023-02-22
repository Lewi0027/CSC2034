#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include "header.h"


using namespace std;

const size_t COLSIZE = 6;
const size_t ROWSIZE = 7;

void printBoard(char array1[][ROWSIZE]);

int main() {

	char array1[COLSIZE][ROWSIZE] = { 'c', 'c', 'c'};
	for (unsigned int i = 0; i < ROWSIZE; i++) {
		for (unsigned int j = 0; j < COLSIZE; j++) {
			cout << array1[i][j] << " ";
			if (j == COLSIZE-1)
				cout << "before void" << endl;
		}
	}

	printBoard(array1);


	return 0;
}

void printBoard(char array1[][ROWSIZE]) {
	for (unsigned int i = 0; i < ROWSIZE; i++) {
		for (unsigned int j = 0; j < COLSIZE; j++) {
			cout << array1[i][j] << " ";
			if (j == COLSIZE-1)
				cout << endl;
		}
	}
}