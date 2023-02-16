#include <iostream>
using namespace std;

/*
* A program using Hans Luhn's algorithm to validate a c/c number.
*/

// return true if the argument is a valid card number
bool isValid(unsigned long long int);

// get the result from step 2
int sumOfDoubleEvenPlace(unsigned long long int number);

/* return this number if argument is a single digit, otherwise
 * return the sum of the two digit argument
 */
int getDigit(int);

// return sum of odd placed digits in argument
int sumOfOddPlace(unsigned long long int);

// return true if prefix d is a prefix for number
bool prefixMatched(unsigned long long int number, int d);

// return the number of digits in argument
int getSize(unsigned long long int);

/* return the first k number of digits from number.  If the
 * number of digits in number is is less than k, return number.
 */
unsigned long int getPrefix(unsigned long long int number, int k);

int main() {
	unsigned long long int ccNum; // = 4388576018410707; //--is valid; 4388576018402626--is invalid ;
	char loopVar = 'y';
	while (loopVar != 'n') {
		cout << "Enter a credit card number: ";
		cin >> ccNum;
		cout << ((isValid(ccNum)) ? "Credit card is valid.\n" : "Credit card is not valid.\n");
		cout << "Would you like to enter another number? (type 'n' to stop)" << endl;
		cin >> loopVar;
	}
}

bool isValid(unsigned long long int num) {
	int total = sumOfDoubleEvenPlace(num) + sumOfOddPlace(num);
	int size = getSize(num);
	int prefix = getPrefix(num, 1);

	if (size < 13 || size > 16) {
		if (size < 13)
			cout << "Too short." << endl;
		if (size > 16)
			cout << "Too long." << endl;
		return false;
	}
	if (total % 10 != 0) {
		cout << "Not divisible by 10." << endl;
		return false;
	}
	if (prefix < 3 || prefix > 6) {
		cout << "Not a valid prefix." << endl;
		return false;
	}
	if (prefix == 3) {
		prefix = getPrefix(num, 2);
		if (prefix != 37) {
			cout << "Not a valid prefix (37)." << endl;
			return false;
		}
	}
	return true;
}

/* return the first k number of digits from number.  If the
 * number of digits in number is is less than k, return number.
 */
unsigned long int getPrefix(unsigned long long int number, int k) {
	if (getSize(number) <= k)
		return number;

	int lengthNeeded = getSize(number) - k;
	for (int i = 0; i < lengthNeeded; i++) {
		number /= 10;
	}
	return number;
}

// return the number of digits in argument
int getSize(unsigned long long int ccNum) {
	int digits = 0;
	while (ccNum != 0) {
		ccNum /= 10;
		digits++;
	}
	return digits;
}

// return true if prefix d is a prefix for number
bool prefixMatched(unsigned long long int number, int d) {
	bool flag = false;
	int numberSize = getSize(number);
	int prefixSize = getSize(d);
	int difference = numberSize - prefixSize;

	for (int i = 0; i < difference; i++)
		number /= 10;
	
	return number == d ? true : false;
}

// return sum of odd placed digits in argument
int sumOfOddPlace(unsigned long long int number) {
	int total = 0;
	int temp;
	int length = getSize(number);
	for (int i = 0; i < length; i++) {
		if (i % 2 == 0) {
			temp = number % 10;
			total += temp;
		}
		number /= 10;
	}
	return total;
}

/* return this number if argument is a single digit, otherwise
 * return the sum of the two digit argument
 */
int getDigit(int number) {
	if (getSize(number) == 1 or number == 0)
		return number;
	number %= 10;
	return number + 1;
}

// get the result from step 2
int sumOfDoubleEvenPlace(unsigned long long int number) {
	int total = 0;
	int temp;
	int length = getSize(number);
	for (int i = 0; i < length; i++) {
		if (i % 2 != 0) {
			temp = (number % 10) * 2;
			temp = getDigit(temp);
			total += temp;
		}
		number /= 10;
	}
	return total;
}

