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

sets::sets(const sets& set) : data (set.data) {}

//Functions
void sets::print() {
	for (unsigned int i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
		if (i == data.size()-1)
			std::cout << std::endl;
	}
	if (data.size() == 0)
		std::cout << "Empty vector." << std::endl;
}

void sets::print(int x) {
	for (unsigned int i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	if (data.size() == 0)
		std::cout << "Empty vector." << std::endl;
}

//Overloaded operators
sets sets :: operator+= (int value) {
	for (unsigned int i = 0; i < data.size(); i++) {
		if (data[i] == value) {
			return *this;
		}
	}

	sets Result(*this);
	data.push_back(value);
	return Result;
}

sets sets :: operator-= (int value) {
	for (unsigned int i = 0; i < data.size(); i++) {
		if (data[i] == value) {
			sets Result(*this);
			data.erase(data.begin() + i);
			return Result;
		}
	}
	std::cout << "Value not in set.\n";
	return *this;
}

const sets operator* (const sets& set1, const sets& set2) {
	sets Result;
	for (unsigned int i = 0; i < set1.data.size(); i++) {
		for (unsigned int j = 0; j < set2.data.size(); j++) {
			if (set1.data[i] == set2.data[j])
				Result += set1.data[i];
		}
	}
	return Result;
}

const sets operator+ (const sets& set1, const sets& set2) {
	sets Result(set1);
	for (unsigned int i = 0; i < set2.data.size(); i++)
		Result += set2.data[i];
	return Result;
}

const sets operator- (const sets& set1, const sets& set2) {
	sets Result(set1);
	for (int i = Result.data.size() - 1; i >= 0; i--) {
		for (unsigned int j = 0; j < set2.data.size(); j++) {
			if (Result.data[i] == set2.data[j]) {
				Result -= Result.data[i];
			}
		}
	}
	return Result;
}
