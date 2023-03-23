#include <iostream>
#include <vector>
#include "sets.h"

sets::sets() {
	data = std::vector<int>();
}

sets::sets(int x) {
	data = std::vector<int>(1,x);
}

sets::~sets() {
	//Intentionally left blank
}

sets::sets(sets& set) : data (set.data) {}

//Functions
void sets::print() {
	for (unsigned int i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
		if (i == data.size()-1)
			std::cout << "last value." << std::endl;
	}
	if (data.size() == 0)
		std::cout << "Empty vector." << std::endl;
}

//Overloaded operators
sets sets :: operator+= (int value) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == value) {
			return *this;
		}
	}

	sets Result(*this);
	data.push_back(value);
	return Result;
}

sets sets :: operator-= (int value) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == value) {
			sets Result(*this);
			data.erase(data.begin() + i);
			return Result;
		}
	}
	std::cout << "Value not in set.\n";
	return *this;
}
/*
sets operator* (sets& set);
sets operator+ (sets& set);
sets operator- (sets& set);
*/