#ifndef SETS_H
#define SETS_H

#include <vector>

using namespace std;

class sets {
protected:
	vector<int> data;

public:

	//Constructors &destructor
	sets();
	sets(int);
	~sets();
	sets(const sets&);

	//Functions
	void print();
	void print(int);

	//Overloaded operators
	sets operator+= (int);
	sets operator-= (int);
	friend const sets operator* (const sets&, const sets&);
	friend const sets operator+ (const sets&, const sets&);
	friend const sets operator- (const sets&, const sets&);
};

#endif
