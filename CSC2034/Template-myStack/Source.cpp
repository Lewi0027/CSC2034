#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include "myTemplateStack.h"

using namespace std;

int main() {

	myStack<int>* f;			//object that holds data and push,pop,print
	char tempStr[80];	//char array that holds txt file info
	ifstream txtfile;	//ifstream that imports txt file info
	char* value;		//variable to hold the value to be pushed, popped or used as an operand

	txtfile.open("rpnArithmetic.txt");
	f = new myStack<int>;

	//while loop which keeps repeating until end of file is reached.
	while (!txtfile.eof()) {
		//set tempStr equal to first line of txtfile up to 80 chars or delimeter of \n
		txtfile.getline(tempStr, 80, '\n');

		//output the header before calculating final sum
		printf("expression %.*s evaluates to ", (int)sizeof(tempStr), tempStr);

		//extract value from char array using strtok() in order to preserve integers longer than 1 digit
		value = strtok(tempStr, " ");

		//while loop keeps repeating until strtok value is NULL
		//performs switch based upon value and then gets new strtok value
		while (value != NULL) {
			//switch statement either:
			//pushes integer values
			//pops two int values to use with operand value and pushes new value
			switch (value[0]) {
			case '+':
				f->push(f->pop() + f->pop()); break;
			case '-':
				f->push(-(f->pop()) + f->pop()); break;
			case '*':
				f->push(f->pop() * f->pop()); break;
			case '/':
				f->push((1.0 / f->pop()) * f->pop()); break;
			default:
				f->push(stoi(value));
			}
			//Get new strtok value starting where last strtok left off
			value = strtok(NULL, " ");
		}
		//print out the values currently in the stack
		//should just be one value if txtfile formatted correctly
		f->print();

		//delete object and recreate in order to remove any pushed values
		delete f;
		f = new myStack<int>;
	}

	txtfile.close();

	return 0;
}
//strtok - CRT_SECURE_NO_WARNINGS (preprocessor definition)