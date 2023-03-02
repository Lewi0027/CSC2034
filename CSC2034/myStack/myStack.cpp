#include <iostream>
#include "myStack.h"

myStack::myStack() {
	//Intentionally left blank
}

myStack::~myStack() {
	//Intentionally left blank
	//data.clear();
	//data.~vector();
}

/*This function will push an integer onto data's stack*/
void myStack::push(int k) {
	//Postcondition: pushes the item (int k) passed to the argument onto the top of the stack
	data.push_back(k);
}

/*This function will pop a value from data's stack and return that value*/
int myStack::pop() {
	//Postcondition: evaluates if the vector is populated
	//if populated pops the top item from the stack and returns that value
	//if not populated throws error
	int k = 0;
	if (!isEmpty()) {
		k = data.back();
		data.pop_back();
		return k;
	}
	else {
		throw "Error...Nothing in stack.";
	}
}

/*This function returns a bool value relating whether the stack is empty or not*/
bool myStack::isEmpty() {
	//Postcondition: returns True if stack is Empty, otherwise returns False
	return data.empty();
}

/*This function outputs any values in the stack as well as if there is any amount other than 1 item on the stack*/
void myStack::print() {
	//Precondition: this is triggered at the end of every individual line of arithmetic
	//Postcondition: this prints out any int values which are currently on the stack
	if (isEmpty()) {
		std::cout << "Nothing on the stack.";
		return;
	}
	else if (data.size() == 1)
		std::cout << data.back() << std::endl;
	else {
		std::cout << "You have multiple values in the stack";
		for (auto i = 0; i < data.size(); i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
}

//Prints out the values
//void myStack::print(std::ostream& outs) {
//	if (!isEmpty())
//		outs << this;
//	std::cout << std::endl;
//	return;
//}

//std::ostream& operator << (std::ostream& outs, myStack* p) {
//	if (p->isEmpty())
//		outs << "stack is empty." << std::endl;
//	else 
//		for (std::vector<int>::iterator it = p->data.begin(); it != p->data.end(); it++) {
//			outs << *it << " ";
//		}
//	return outs;
//}