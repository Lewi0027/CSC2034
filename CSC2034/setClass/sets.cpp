#include <iostream>
#include <vector>
#include "sets.h"

//Create object with empty vector
sets::sets() {
	data = std::vector<int>();
}

//Create object with one int in vector
sets::sets(int x) {
	data = std::vector<int>(1,x);
}

//Copy existing object
sets::sets(const sets& set) : data(set.data) {}

//Destructor
sets::~sets() {
	//std::cout << "destructor invoked" << std::endl;
	//Intentionally left blank
}

//Functions
//Print all elements in array or "Empty vector" with two end lines
void sets::print() {
	//Precondition: sets object must exist
	//Postcondition: N/A
	for (unsigned int i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
		if (i == data.size()-1)
			std::cout << std::endl;
	}
	if (data.size() == 0)
		std::cout << "Empty vector." << std::endl;
	std::cout << std::endl;
}

//Print all elements in array or "Empty vector"
void sets::print(int x) {
	//Precondition: sets object must exist
	//Postcondition: N/A
	for (unsigned int i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	if (data.size() == 0)
		std::cout << "Empty vector." << std::endl;
}

//Overloaded operators
//+= operator - Test uniqueness, if unique add to sets object and return
sets sets :: operator+= (int value) {
	//Precondition: sets object must exist
	//Postcondition: Returns sets object with int value added to vector data if unique
	for (unsigned int i = 0; i < data.size(); i++) {
		if (data[i] == value) {
			return *this;
		}
	}
	sets Result(*this);
	data.push_back(value);
	return Result;
}

//-= operator - Remove value from sets object if present and return
sets sets :: operator-= (int value) {
	//Precondition: sets object must exist
	//Postcondition: Returns sets object with provided value removed from vector data
	for (unsigned int i = 0; i < data.size(); i++) {
		if (data[i] == value) {
			sets Result(*this);
			data.erase(data.begin() + i);
			return Result;
		}
	}
	std::cout << "Value not in set.\n\n";
	return *this;
}

//* operator - Returns a sets object that is the intersection of two sets
const sets operator* (const sets& set1, const sets& set2) {
	//Precondition: Two sets object must exist
	//Postcondition: Returns a sets object that is the intersection of set1 and set2
	sets Result;
	for (unsigned int i = 0; i < set1.data.size(); i++) {
		for (unsigned int j = 0; j < set2.data.size(); j++) {
			if (set1.data[i] == set2.data[j])
				Result += set1.data[i];
		}
	}
	return Result;
}

//+ operator - Returns a sets object that is the union of two sets
const sets operator+ (const sets& set1, const sets& set2) {
	//Precondition: Two sets objects must exist
	//Postcondition: Returns a sets object that is the union of set1 and set2
	sets Result(set1);
	for (unsigned int i = 0; i < set2.data.size(); i++)
		Result += set2.data[i];
	return Result;
}

//- operator - Returns a sets object that is the difference between two sets
const sets operator- (const sets& set1, const sets& set2) {
	//Precondition: Two sets objects must exist
	//Postcondition: Returns a sets object that is the difference of set1 - set2
	sets Result(set1);
	for (unsigned int i = Result.data.size(); i >= 1; i--) {						//Why can't this be an unsigned int? This was causing errors that way and it was not turning into a negative value
		for (unsigned int j = 0; j < set2.data.size(); j++) {
			if (Result.data[i-1] == set2.data[j]) {
				Result -= Result.data[i-1];
			}
		}
	}
	return Result;
}
