#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <stdio.h>
#include <string>

using namespace std;

const size_t ROWSIZE = 6;
const size_t COLSIZE = 7;
int board[ROWSIZE][COLSIZE] = { 0 };
unsigned int turnCount = 0;
unsigned int dropSlot;
string dropValue;
enum colors { red = 8, yellow };

void drawBoard();
void setBoard();
unsigned int prompt();
void modifyBoard(unsigned int, unsigned int);
void putTogether();
int victoryTest();
int horizontalVictory();
int verticalVictory();

/*To do:
* divide into .h and .cpp files. How does this impact global variables?
* finish verticalVictory for enum interaction (?)
* finish diagonalVictory
* global variables vs return values vs pass by reference
* can I clean up vertical and horizontal victory?*/

int main() {
	cout << "Let's play Connect 4. The board is currently empty" << endl;
	drawBoard();
	putTogether();

	return 0;
}

// This is breaking on column where enum value is on three instead of four?????????
int verticalVictory() {
	for (unsigned int j = 0; j < ROWSIZE; j++) {
		for (unsigned int i = 0; i < COLSIZE; i++) {
			if (board[i][j] != 0) {
				if (board[i][j] == board[i + 1][j]) {
					if (board[i][j] == board[i + 2][j]) {
						if (board[i][j] == board[i + 3][j])
							return board[i][j];
					}
				}
			}
		}
	}
	return 0;
}

/*Checks for four values in a row horizontally.
If found, returns value associated with color from one of the array slots.*/
int horizontalVictory() {
	for (unsigned int i = 0; i < COLSIZE; i++) {
		for (unsigned int j = 0; j < ROWSIZE; j++) {
			if (board[i][j] != 0) {
				if (board[i][j] == board[i][j + 1]) {
					if (board[i][j] == board[i][j + 2]) {
						if (board[i][j] == board[i][j + 3])
							return board[i][j];
					}
				}
			}
		}
	}
	return 0;
}

/*Main housing for victory tests*/
int victoryTest() {
	int v = verticalVictory();
	int h = horizontalVictory();

	if (h != 0)
		return h;
	if (v != 0)
		return v;

	return 0;
}

/*Recursive program to keep requesting inputs from user, applying and drawing them until a draw or victory condition is reached*/
void putTogether() {
	//base case 1: draw due to lack of remaining spaces
	if (turnCount == 42) {
		cout << "The game has ended in a draw" << endl;
		return;
	}
	//base case 2: victory; 4 in a row
	if (victoryTest() != 0) {
		victoryTest() == red ? cout << "Red has won!" : cout << "Yellow has won!";
		return;
	}

	//recursively request inputs from user, modifies the array and then draws the array
	turnCount % 2 == 0 ? printf("Drop a red disk at column (0-6): ") : printf("Drop a yellow disk at column (0-6): ");
	modifyBoard(prompt(), turnCount);
	drawBoard();
	putTogether();

}

/*Draws the board using the global array board*/
void drawBoard() {
	unsigned int rowValue;
	unsigned int colValue;
	for (unsigned int i = 1; i < (COLSIZE * ROWSIZE + 1); i++) {
		rowValue = ((i - 1) / 7);
		colValue = (i - 1) % 7;
		cout << setw(2) << "|";
		if (board[rowValue][colValue] == red)
			cout << setw(3) << "R";
		else if (board[rowValue][colValue] == yellow)
			cout << setw(3) << "Y";
		else
			cout << setw(3) << " ";
		if (i % 7 == 0)
			cout << setw(3) << "|" << endl;
	}
}

/* Populate board with predetermined values*/
void setBoard() {
	unsigned int d = 0;
	for (unsigned int i = 0; i < ROWSIZE; i++) {
		for (unsigned int j = 0; j < COLSIZE; j++) {
			board[i][j] = d;
			cout << board[i][j] << " ";
			d++;
			d = (d % 2) + 1;
		}
	}
	cout << endl;
}

/*Get dropSlot from user, check validity and then increase turn counter for draw base case.
Returns dropSlot value to be used with modifyBoard*/
/*unsigned int prompt() {
	turnCount % 2 == 0 ? printf("Drop a red disk at column (0-6): ") : printf("Drop a yellow disk at column (0-6): ");
	cin >> dropSlot;
	while (dropSlot < 0 || dropSlot > 6) {
		cout << "Not a valid value...\nPlease enter again: ";
		cin >> dropSlot;
	}
	while (board[0][dropSlot] != 0) {
		cout << "That column is already full...\nPlease enter a new value: ";
		cin >> dropSlot;
	}
	turnCount++;
	return dropSlot;
}*/

/*Get dropSlot from user, turn into an int from string, check validity and then increase turn counter for draw base case.
Returns dropSlot value to be used with modifyBoard
Can I make this recursive so that the new inputs go through all the tests again instead of just that individual test?*/
unsigned int prompt() {
	cin >> dropValue;
	while (dropValue.length() != 1) {
		cout << "Input must be a number between 0 and 6.\nPlease enter again: ";
		return prompt();
	}
	char c = dropValue[0];
	dropSlot = int(c) - 48;
	while (dropSlot < 0 || dropSlot > 6) {
		cout << "Input must be a number between 0 and 6.\nPlease enter again: ";
		return prompt();
	}
	while (board[0][dropSlot] != 0) {
		cout << "That column is already full.\nPlease enter a new value: ";
		return prompt();
	}
	turnCount++;
	return dropSlot;
}

/*Inserts the value into the array at the proper location using dropSlot. Uses turnCount to determine which color.*/
void modifyBoard(unsigned int dropSlot, unsigned int turnCount) {
	unsigned int i;
	for (i = 0; i < ROWSIZE - 1; i++) {
		if (board[i + 1][dropSlot] != 0) {
			break;
		}
	}
	turnCount % 2 == 0 ? board[i][dropSlot] = yellow : board[i][dropSlot] = red;
}