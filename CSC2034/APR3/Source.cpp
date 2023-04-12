//Exception Handling
#include <exception> //Contains all below; bad_exception
#include <stdexcept> //Logic E, runtime E, range E, overflow E, underflow E, domain E, out of range, length E, invalid argument
#include <new> // bad_alloc
#include <typeinfo> //bad-typeid, bad_cast
#include <ios> // ios_base::failure
#include <iostream>
#include <string>
#include <cassert>
#define NDEBUG

void foobar(int);
char foo();
void bar();

int main() {
	foobar(450);
	bar();
	return 0;
}

void foobar(int y) {
	try {
		if (y == 440) {
			throw 440;
		}
		else if (y < 440){
			throw foo();
		}
		else {
			throw "string";
		}
	}
	catch (int x) {
		std::cout << "exception " << x << std::endl;
	}
	catch (char b) {
		std::cout << "exception " << b << std::endl;
	}
	catch (...) {
		std::cout << "exception other" << std::endl;
	}
}

char foo() {
	return 'x';
}

void bar() {
	int j = 11;
	while (j > 10) {
		j--;
		while (8 > 6){
			if (3 < 2) {
				barz:
				std::cout << "you made it" << std::endl;
				break;
				}
			else {
				while (9 > 6) {
					goto barz;
				}
			}
		}
	}
end:
	std::cout << "end" << std::endl;
}

//ptr = new int  #memory leak prone
//{
//	*ptr = v;
//}
//
//vs
//
//sp(new int); # not memory leak prone since using a class
//{
//	*sp = v;
//}