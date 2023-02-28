#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include "myStack.h"

using namespace std;

int main() {

	myStack* f;
	char permStr[80];
	char tempStr[80] = {0};
	ifstream txtfile;
	char* value;
	int pushMe;
	int temp1, temp2;

	txtfile.open("rpnArithmetic.txt");
	f = new myStack;

	while (!txtfile.eof()) {
		txtfile.getline(permStr, 80);
		
		for (int i = 0; i < strlen(permStr); i++) {
			tempStr[i] = permStr[i];
		}

		value = strtok(tempStr, " ");

		while (value != NULL) {
			switch (value[0]) {
			case '+':
				f->push(f->pop() + f->pop());
				break;
			case '-':
				f->push(-(f->pop()) + f->pop());
				break;
			case '*':
				f->push(f->pop() * f->pop());
				break;
			case '/':
				temp1 = f->pop();
				temp2 = f->pop();
				f->push(temp2/temp1);
				break;
			default:
				pushMe = stoi(value);
				f->push(pushMe);
			}
			if (value != NULL)
				value = strtok(NULL, " ");
			else
				break;
		}
		
		printf("expression %.*s evaluates to %d", (int)sizeof(permStr), permStr, f->pop());
		cout << endl;
	}
	f->print(cout);
	cout << endl;
	txtfile.close();

	return 0;

}

//output:
//expression 2 3 + 7 * evaluates to 35 
//strtok - CRT_SECURE_NO_WARNINGS (preprocessor definition)