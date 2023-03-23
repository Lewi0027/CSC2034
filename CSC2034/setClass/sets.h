#ifndef SETS_H
#define SETS_H

#include <vector>

using namespace std;

class sets {
private:
	vector<int> data;

public:

	//Constructors &destructor
	sets();
	sets(int);
	~sets();
	sets(sets&);

	//Functions
	void print();

	//Overloaded operators
	sets operator+= (int);
	sets operator-= (int);
	//sets operator* (sets& set);
	//sets operator+ (sets& set);
	//sets operator- (sets& set);
};

#endif
