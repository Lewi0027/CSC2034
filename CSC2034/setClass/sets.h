#ifndef SETS_H
#define SETS_H

#include <vector>

class sets {
private:
	std::vector<int> data;

public:

	//Constructors & destructor
	sets();					//Empty class
	sets(int);				//Create with int value
	sets(const sets&);		//Copy class
	~sets();

	//Functions
	void print();
	void print(int);		//Print w/out endl

	//Overloaded operators
	//Member functions:
	sets operator+= (int);			//Add to set; test if value already exists in set
	sets operator-= (int);			//Remove item from set

	//Non-Member functions:
	friend const sets operator* (const sets&, const sets&);		//Set intersection
	friend const sets operator+ (const sets&, const sets&);		//Set union
	friend const sets operator- (const sets&, const sets&);		//Set difference
};

#endif