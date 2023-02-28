#include <iostream>
#include "myStack.h"

myStack::myStack() {
	//Intentionally left blank

}

myStack::~myStack() {
	//INtentionally left blank
	data.clear();
	data.~vector();
}

void myStack::push(int k) {
	//Post-condition: pushes the item (int k) passed to the argument onto the top of the stack
	data.push_back(k);
}

int myStack::pop() {
	//Post-condition: evaluates if the vector is populated.
	//If so pops the top item from the stack and returns that value
	int k = 0;
	if (!isEmpty()) {
		k = data.back();
		data.pop_back();
		return k;
	}
	else {
		throw "Error...Nothing in stack";
	}
}

bool myStack::isEmpty() {
	//Post-condition: returns True if stack is Empty, otherwise returns False
	return data.empty();
}

//void myStack::print() {
//	for (auto i = data.begin(); i != data.end(); i++) {
//		std::cout << data[*i] << " ";
//	}
//	std::cout << std::endl;
//}

//Prints out the values
void myStack::print(std::ostream& outs) {
	if (!isEmpty())
		outs << this;
	std::cout << std::endl;
	return;
}

std::ostream& operator << (std::ostream& outs, myStack* p) {
	if (p->isEmpty())
		outs << "stack is empty." << std::endl;
	else 
		for (std::vector<int>::iterator it = p->data.begin(); it != p->data.end(); it++) {
			outs << *it << " ";
		}
	return outs;
}