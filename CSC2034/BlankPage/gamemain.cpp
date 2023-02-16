#include <iostream>
#include <string>
#include <vector>

#include "CharacterC.h"
#include "diceC.h"
#include "ElfC.h"

using namespace std;

void directions();
int chooseLevel();

int main()
{
	srand(0);
	int level;
	directions();

	level = chooseLevel();

	system("pause");
	cout << endl;
	return 0;
}

void directions()
{
	cout << "Here is how to play the game" << endl;
	//	cout<<ATTRIBUTENAME[0];
}

int chooseLevel()
{
	int level;
	do
	{
		cout << "What level do you want? ";
		cin >> level;
	} while (level < 0 || level > 10);

	return level - 1;
}

