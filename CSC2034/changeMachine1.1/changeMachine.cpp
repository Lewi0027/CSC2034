#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

const string moneyName[] = { "dollar", "half dollar", "quarter", "dime", "nickel", "penny" };
const string moneyNamePlural[] = { "dollars", "placeholder", "placeholder", "dimes", "placeholder", "pennies" };
int coinValues[] = {100, 50, 25, 10, 5, 1};
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

void denomSolve(int cents, int iteration) {
	while (cents != 0 && iteration < 5) {
		cents >= coinValues[iteration] * 2 ? sflag = true : sflag = false;
		sflag == true ? printf("%d %s\n", cents / coinValues[iteration], moneyNamePlural[iteration].c_str()) : printf("%d %s\n", cents / coinValues[iteration], moneyName[iteration].c_str());
		cents -= ((cents / coinValues[iteration]) * coinValues[iteration]);
		denomSolve(cents, iteration+1);
	}
	cents > 1 ? sflag = true : sflag = false;
	sflag == true ? printf("%d %s\n", cents / coinValues[iteration], moneyNamePlural[iteration].c_str()) : printf("%d %s\n", cents / coinValues[iteration], moneyName[iteration].c_str());
	return;
}