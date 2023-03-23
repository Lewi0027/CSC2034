#pragma once
#include <iostream>
#include <string>

class Class1 {
private:
	int x = 0;
	char y = 'x';
	int j;
	//int y;
public:
	Class1(int k){
		x = k;
		j = 0;
	}
	Class1() {
		this->setX();
		j = 0;
	}
	Class1(char y) {
		this->y = y;
		j = 1;
	}
	~Class1() {
		std::cout << "destructor" << std::endl;
	}
	void setX() {
		x = 5;
	};
	void print() {
		j == 0 ? std::cout << x << std::endl : std::cout << y << std::endl ;
	};
};