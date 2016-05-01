#include <iostream>

#include "tictacclass.h"

using namespace std;

// Public

/// Start the game by setting all the
/// spaces to 0, and making player 1
/// the initial player
TicTacClass::TicTacClass() {
	status_ = true;
	currentPlayer_ = 1;
	spaces_[0][0] = 0;
	spaces_[0][1] = 0;
	spaces_[0][2] = 0;
	spaces_[1][0] = 0;
	spaces_[1][1] = 0;
	spaces_[1][2] = 0;
	spaces_[2][0] = 0;
	spaces_[2][1] = 0;
	spaces_[2][2] = 0;
}


/// Iterating through every possible win combination,
/// keeping track of the score and the number of positions used,
/// resets both counters as necessary 
bool 
TicTacClass::checkWin() {
	int sum = 0;
	int count = 0;
	bool win = false;
	
	int possibleWins[][3][2] = {
		{ {0,0}, {0,1}, {0,2} }, /////
		{ {0,2}, {1,2}, {2,2} },    // 
		{ {2,2}, {2,1}, {2,0} },    //
		{ {2,0}, {1,0}, {0,0} },    // Sequences 
		{ {0,0}, {1,1}, {2,2} },    //
		{ {0,2}, {1,1}, {2,0} },    //
		{ {0,1}, {1,1}, {2,1} },    //
		{ {1,0}, {1,1}, {1,2} }  /////
	};

	for(int a = 0; a < 8; a++) {
		for(int b = 0; b < 3; b++) 
			for(int c = 0; c < 1; c++) {
				sum += spaces_[possibleWins[a][b][c]][possibleWins[a][b][c + 1]];
			}
			
				count++;
		
		if(sum == 15 && count == 3) {
			win = true;
			std::cout << "Player " << currentPlayer_ << " won\n";
			break;
		} 
		else {
			sum = 0; 	// Reset the sum after every sequence if it is not 
						// 15.
			count = 0; 	// Reset the count if there is no win.
		}
	}
		
	return win;	
}



bool 
TicTacClass::getStatus() {
	return status_;
}


/// Prompts user for input, then either
/// resets the game or returns false,
/// therefore ending the game
bool 
TicTacClass::rematch() {
	char input;
	
	// Prompt user
	cout << "Rematch(Y/N): ";
	cin >> input;
	
	if (input == 'Y') {	
		resetGame();
	} 
	else
		status_ = false;
	
	return status_;
	
}


/// Prints the text-based board
void 
TicTacClass::displayBoard() {
        std::cout << "    0     1     2  " << std::endl;
        std::cout << "       |     |     " << std::endl;

		for (int row = 0; row < 3; row++) {
			std::cout << row << " ";
			
			for (int col = 0; col < 3; col++)
				printCell (row, col);
			
			if (row != 2) {
				std::cout << std::endl	<< "  _____|_____|_____" 
						  << std::endl;
        		std::cout 				<< "       |     |     " 
        				  << std::endl;
        	}
		}
		
        std::cout << std::endl << "       |     |     " << std::endl;
		
		std::cout << std::endl;
}


/// Prompts user for a position that is valid,
/// as well as a value within a certain range
void 
TicTacClass::nextMove () {
	int row;
	int col; 
	int value;
	int totalPlay = 0; 
	int takenChoices[9];

	do {
		// Prompt user for position
                std::cout << "Player " << currentPlayer_ << ", ";
                std::cout << "choose a row then column"
                		  << "(Separated by a space): ";
                std::cin >> row >> col;

	} while(!validatePosition(row, col)); 

	do {
		 		 // Prompt user for value
                 std::cout << "Player " << currentPlayer_ << ", ";
                 std::cout << "choose a value "
                 		   << "(Enter a integer between 1-9): ";
                 std::cin >> value;

	      		// Add value to board if it hasn't been used before 
                spaces_[row][col] = value;
		takenChoices[totalPlay] = value;
		totalPlay++;
	} while(!validateValue(value, takenChoices) && (value < 1 || value > 9));
    
    std::cout << std::endl; // Create whitespace between each play
    
	return ;
}



void TicTacClass::switchPlayer() {
	if (currentPlayer_ == 1)
		currentPlayer_ = 2;
	else
		currentPlayer_ = 1;
}

// Private

/// Checks to see if the position is feasible
bool 
TicTacClass::validatePosition (int row, int col) {
	bool openStatus = true;

	// Error handling
	
	// If row or column is negative or above 3, prompt user
	if(row < 0 || row > 3 || col < 0 || col > 3) {
		openStatus = false;
		cout << "Invalid position\n";
	} 
	else if(spaces_[row][col] != 0) {
		openStatus = false;
		cout << "Already taken\n";
	} 

	return openStatus;
}


/// Checks to see if the value is feasible
bool TicTacClass::validateValue (int value, int takenSpots[]) {
       	bool valueStatus = true; // Value has not been used yet. 

        for(int index = 0; index < 9; index++) {
                if(takenSpots[index] == value) {
                        valueStatus = false; // Value has already been used.
                        break;
                }
        }
	return valueStatus;
}


/// Aides in displaying the board
void TicTacClass::printCell (int row, int col) {

  if(spaces_[row][col] == 0) {
  	if(col == 2)
    	std::cout << " " << " " << "   ";
    else
    	std::cout << " " << " " << "   |";
  } 
  else
    if(col != 2)
    	std::cout << "  " << spaces_[row][col] << "  |";
    else
    	std::cout << "  " << spaces_[row][col] << "  ";
}


/// Resets all positions to 0, makes player 1
/// the current player
void TicTacClass::resetGame() {
	status_ = true;
	currentPlayer_ = 1;
	spaces_[0][0] = 0;
	spaces_[0][1] = 0;
	spaces_[0][2] = 0;
	spaces_[1][0] = 0;
	spaces_[1][1] = 0;
	spaces_[1][2] = 0;
	spaces_[2][0] = 0;
	spaces_[2][1] = 0;
	spaces_[2][2] = 0;
}