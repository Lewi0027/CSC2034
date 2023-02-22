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
enum colors { red = 1, yellow };
bool heightFour = false;

void drawBoard();
void setBoard();
unsigned int prompt();
void modifyBoard(unsigned int, unsigned int);
void putTogether();
int victoryTest();
int horizontalVictory();
int verticalVictory();
int diagonalVictory();
void highestRow();

/*Starts game, draws initial board, goes into recursive function for turns*/
int main() {
	std::cout << "Let's play Connect 4. The board is currently empty" << endl;
	drawBoard();
	putTogether();

	return 0;
}

/*Check to see if vertical victory and diagonal victory need to be performed
* checks to see if any of the fourth row has been populated for any of the columns
* true -> don't need to check; false -> need to check*/
void highestRow() {
	//Pre-condition: heightFour == false
	//Post-condition: heightFour = true if any column has a value at row 3 in board[2][j]
	for (unsigned int j = 0; j < COLSIZE; j++) {
		if (board[2][j] != 0) {
			heightFour = true;
			break;
		}
	}
}

/*Check the arrays for diagonal victory conditions in both diagonal directions
* [i+1][j+1] & [i+1][j-1]
* The victory checks are checking for four in a row so they do not for loop through the entire array
* Only look at elements inside of the array*/
int diagonalVictory(){
	//Pre-condition: heightFour == true
	//Post-condition: returns (0 = no win, 1 = red win, 2 = yellow win)
	for (unsigned int i = 0; i < ROWSIZE-3; i++) {
		for (unsigned int j = 0; j < COLSIZE-3; j++) {
			if (board[i][j] != 0) {
				if (board[i][j] == board[i + 1][j + 1]) {
					if (board[i][j] == board[i + 2][j + 2]) {
						if (board[i][j] == board[i + 3][j + 3]) {
							return board[i][j];
						}
					}
				}
			}
		}
	}
	for (unsigned int i = 0; i < ROWSIZE-3; i++) {
		for (unsigned int j = 3; j < COLSIZE; j++) {
			if (board[i][j] != 0) {
				if (board[i][j] == board[i + 1][j - 1]) {
					if (board[i][j] == board[i + 2][j - 2]) {
						if (board[i][j] == board[i + 3][j - 3]) {
							return board[i][j];
						}
					}
				}
			}
		}
	}
	return 0;
}

/*checks the array for possible vertical victories
* outside for loop uses j instead of i so it moves left to right not up to down
* only checks a column if the second and third row have the same value*/
int verticalVictory() {
	//Pre-condition: heightFour == true
	//Post-condition: returns (0 = no win, 1 = red win, 2 = yellow win)
	for (unsigned int j = 0; j < ROWSIZE+1; j++) {
		if (board[2][j] == board[3][j]) {
			for (unsigned int i = 0; i < COLSIZE - 4; i++) {
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
	}
	return 0;
}

/*Checks for four values in a row horizontally
* first checks if middle value matches right or left value, if not goes to next row/array
* if found checks entire row for 4 in a row/array*/
int horizontalVictory() {
	//Pre-condition: turnCount >= 8
	//Post-condition: returns (0 = no win, 1 = red win, 2 = yellow win)
	for (unsigned int i = 0; i < COLSIZE; i++) {
		if (board[i][3] == board[i][2] || board[i][3] == board[i][4]) {
			for (unsigned int j = 0; j < ROWSIZE-2; j++) {
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
	}
	return 0;
}

/*Main housing for victory tests
* checks to see if diagonal and verticalvictory need to be tested with highestRow()
* Only runs highestRow() if heightFour is false
* d will be equal to Red = 1 or Yellow = 2 (0 + 0 + x) if somebody wins 
* otherwise d equals 0 and game goes on*/
int victoryTest() {
	//Pre-condition: turnCount >= 8
	//Post-condition: returns (0 = no win, 1 = red win, 2 = yellow win)
	int d;
	if (heightFour == true)
		d = diagonalVictory() + verticalVictory() + horizontalVictory();
	else {
		highestRow();
		if (heightFour == true)
			d = diagonalVictory() + verticalVictory() + horizontalVictory();
		else
			d = horizontalVictory();
	}
	return d;
}

/*Recursive program to:
* Requesting inputs from user
* applying input (modifyBoard) and drawBoard until a draw or victory condition is reached (base cases)*/
void putTogether() {
	//Pre-condition: Prompt() is valid
	//Post-condition: putTogether() until Game Over
	//base case 1: draw due to lack of remaining spaces
	if (turnCount == 42) {
		cout << "The game has ended in a draw" << endl;
		return;
	}
	//base case 2: victory - 4 in a row; only tests if 8 turns have elapsed
	if (turnCount >= 7) {
		if (victoryTest() != 0) {
			victoryTest() == red ? cout << "Red has won!" : cout << "Yellow has won!";
			return;
		}
	}
	//recursively request inputs from user, modifies the array and then draws the array
	turnCount % 2 == 0 ? printf("Drop a red disk at column (0-6): ") : printf("Drop a yellow disk at column (0-6): ");
	modifyBoard(prompt(), turnCount);
	drawBoard();
	putTogether();
}

/*Draws the board in its current state
* Uses enum values coupled with the array values (0,1,2) to determine if something should be output
* Empty slots are left blank
* At the end of every array it starts a new line for the next array (starts at 1 for modulo)*/
void drawBoard() {
	//Pre-condition: Start of game and every time board is modified
	//Post-condition: Draws board, returns void, no global variables impacted
	unsigned int rowValue;
	unsigned int colValue;
	for (unsigned int i = 1; i < (COLSIZE * ROWSIZE + 1); i++) {
		rowValue = ((i - 1) / 7);
		colValue = (i - 1) % 7;
		cout << setw(2) << "|";
		if (board[rowValue][colValue] == red)
			cout << setw(2) << "R";
		else if (board[rowValue][colValue] == yellow)
			cout << setw(2) << "Y";
		else
			cout << setw(2) << " ";
		if (i % 7 == 0)
			cout << setw(2) << "|" << endl;
	}
}

/*Function used for testing purposes to populate board
* Not used in final version*/
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

/*Get dropSlot from user, check validity and then increase turn counter for draw base case
* Returns dropSlot value to be used with modifyBoard
* Not in use; was going to overload but that doesn't make since unless I use auto???*/
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

/*Recursive program to get prompt from user for next move
* Base case is valid input and returns the inputted slot value and increases turnCount
* Checks length, if not 1 starts over
* If not an ASCII value starts over
* If input for column that is full starts over*/
unsigned int prompt() {
	//Pre-condition: Game starts, beginning of each turn
	//Post-condition: returns dropSlot, which says where to place next value
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

/*Function to check to find where in column to place value, then place it
* For loop checks if the i+1 value is populated, if it is it breaks
* Can start at i+1 since prompt() checks that column is not full*/
void modifyBoard(unsigned int dropSlot, unsigned int turnCount) {
	//Pre-condition: dropSlot is valid
	//Post-condition: value added to board[][]
	unsigned int i;
	for (i = 0; i < ROWSIZE - 1; i++) {
		if (board[i + 1][dropSlot] != 0) {
			break;
		}
	}
	turnCount % 2 == 0 ? board[i][dropSlot] = yellow : board[i][dropSlot] = red;
}