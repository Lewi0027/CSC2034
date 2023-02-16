#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

const string moneyNameSingular[] = { "dollar", "half dollar", "quarter", "dime", "nickel", "penny" };
const string moneyNamePlural[] = { "dollars", "half dollars", "quarters", "dimes", "nickels", "pennies" };
int coinValues[] = { 100, 50, 25, 10, 5, 1 };
bool sflag;

int getInput();
void denomSolve(int, int);

int main() {
	int cents = getInput();
	denomSolve(cents, 0);

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

void denomSolve(int cents, int denomIndx) {
	int denom = coinValues[denomIndx];
	string coins;

	if (denom == 1) { // this is the base case
		coins = cents / 1 > 1 ? moneyNamePlural[denomIndx] : moneyNameSingular[denomIndx];
		printf("%d %s\n", cents / denom, coins.c_str());
		denomSolve(cents % denom, denomIndx + 1);
		return;
	}

	coins = cents / denom > 1 ? moneyNamePlural[denomIndx] : moneyNameSingular[denomIndx];
	printf("%d %s\n", cents / denom, coins.c_str());
	denomSolve(cents % denom, denomIndx + 1);
}