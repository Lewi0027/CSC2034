#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

enum denomValues { dollar = 100, halfDollar = 50, quarter = 25, dime = 10, nickel = 5, penny = 1 };
const string moneyName[] = { "dollar", "half dollar", "quarter", "dime", "nickel", "penny" };
const string moneyNamePlural[] = { "dollars", "placeholder", "placeholder", "dimes", "placeholder", "pennies" };

int getInput();
void denomCalc(int);
void output(int, int);

int main() {
	int cents = getInput();
	cout << "Denomination breakdown:\n";
	denomCalc(cents);
	return 0;
}

int getInput() {
	int cents;
	cout << "How many pennies do you have?" << endl;
	cin >> cents;

	while (cents <= 0) {
		cout << "Invalid amount...\nHow many pennies do you have?" << endl;
		cin >> cents;
	}
	return cents;
}

void denomCalc(int cents) {
	if (cents >= dollar) {
		output(cents / dollar, 0);
		cents -= ((cents / dollar) * dollar);
	}
	if (cents >= halfDollar) {
		output(cents / halfDollar, 1);
		cents -= ((cents / halfDollar) * halfDollar);
	}
	if (cents >= quarter) {
		output(cents / quarter, 2);
		cents -= ((cents / quarter) * quarter);
	}
	if (cents >= dime) {
		output(cents / dime, 3);
		cents -= ((cents / dime) * dime);
	}
	if (cents >= nickel) {
		output(cents / nickel, 4);
		cents -= ((cents / nickel) * nickel);
	}
	output(cents, 5);
}

void output(int temp, int i) {
	bool sflag;
	temp > 1 ? sflag = true : sflag = false;
	sflag == true ? printf("%d %s\n", temp, moneyNamePlural[i].c_str()) : printf("%d %s\n", temp, moneyName[i].c_str());
}