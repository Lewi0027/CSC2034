#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

//enum value for calculating cost/hour
enum rates { carRate = 2, truckRate, busRate };

//Calculates total cost and outputs it as a float
void finalOutput(rates, float);

using namespace std;

int main() {
	char input;
	float hours;
	rates cost;
	enum vehicleType { car = 'c', truck = 't', bus = 'b' };

	cout << "What kind of vehicle? [(c)ar, (b)us or (t)ruck?]" << endl;
	cin >> input;
	cout << "How many hours did you park for?" << endl;
	cin >> hours;

	//Switch statements to assign proper rates and run finalOutput
	switch (input) {
	case (car):
		cost = carRate;
		finalOutput(cost, hours);
		break;
	case (truck):
		cost = truckRate;
		finalOutput(cost, hours);
		break;
	case (bus):
		cost = busRate;
		finalOutput(cost, hours);
		break;
	default:
		cout << "Not a valid input" << endl;
	}
	return 0;
}

//Calculates total cost and outputs it as a float
void finalOutput(rates cost, float hours) {
	float total = hours * cost;
	cout << "You owe: $";
	cout << fixed << showpoint << setprecision(2);
	cout << total << endl;
}