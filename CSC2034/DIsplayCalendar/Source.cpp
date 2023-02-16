#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	const string DAYS_OF_WEEK[] = { "Sun", "Mon", "Tue",
							"Wed", "Thu", "Fri", "Sat" };    //name of days of the week
	const string MONTHS[] = { "January", "February", "March", "April",
						"May", "June", "July", "August",
						"September", "October", "November", "December" };    //name of months

	int month = 1;
	int days, start, year;
	int starth = 0;
	bool leap = false;
	//string header2 = " Sun Mon Tue Wed Thu Fri Sat ";
	string header = "-----------------------------";

	cout << "Enter a year: ";
	cin >> year;
	cout << "Enter the first day of the year: ";
	cin >> start;

	if (year % 4 == 0) // Set flag for leap year
		leap = true;

	int a1[37] = {0};

	while (month <= 12) {
		for (int i = 0; i < 37; i++) {
			a1[i] = 0; // Initialize arrays used to create calendars
		}	

		switch (month) {
		case 1:
			cout << setw(15) << "January " << year << endl;
			days = 31;
			break;
		case 2:
			cout << setw(15) << "February " << year << endl;
			if (leap = false)
				days = 28;
			else
				days = 29;
			break;
		case 3:
			cout << setw(15) << "March " << year << endl;
			days = 31;
			break;
		case 4:
			cout << setw(15) << "April " << year << endl;
			days = 30;
			break;
		case 5:
			cout << setw(15) << "May " << year << endl;
			days = 31;
			break;
		case 6:
			cout << setw(15) << "June " << year << endl;
			days = 30;
			break;
		case 7:
			cout << setw(15) << "July " << year << endl;
			days = 31;
			break;
		case 8:
			cout << setw(15) << "August " << year << endl;
			days = 31;
			break;
		case 9:
			cout << setw(15) << "September " << year << endl;
			days = 30;
			break;
		case 10:
			cout << setw(15) << "October " << year << endl;
			days = 31;
			break;
		case 11:
			cout << setw(15) << "November " << year << endl;
			days = 30;
			break;
		case 12:
			cout << setw(15) << "December " << year << endl;
			days = 31;
			break;
		default:
			cout << "Impossible value" << endl;
		}
		cout << header << endl;
		//cout << header2 << endl;

		for (string currentDay : DAYS_OF_WEEK)
			printf("%4s", currentDay.c_str());
		cout << endl;

		for (int i = start; i < days+start; i++) {
			if (i == 0)
				a1[0] = 1;
			else
				a1[i] = a1[i - 1] + 1;
			if (i == days+start - 1)
				starth = (i + 1) % 7;
		}

		for (int i = 0; i < (sizeof(a1) / sizeof(a1[0])); i++) {
			if (a1[i] == 0)
				cout << setw(4) << " ";
			else
				cout << setw(4) << a1[i];
			if (i % 7 == 0)
				cout << endl;
		}

		start = starth;
		month += 1;
		cout << endl;
	}

	return 0;
}