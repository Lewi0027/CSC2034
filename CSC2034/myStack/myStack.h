#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <vector>

class myStack {
private:
	std::vector<int> data;

public:
	myStack(); //no parameter constructor
	~myStack(); //destructor

	//member functions
	void push(int);
	int pop();
	bool isEmpty();
	void print();
	//void print(std::ostream&);
	
	//non-member functions
	//friend std::ostream& operator << (std::ostream&, myStack*); 

};
#endif
