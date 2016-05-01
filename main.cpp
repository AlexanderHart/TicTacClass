#include <iostream>

#include "tictacclass.h"

int
main() {
	TicTacClass game;
	
	while (game.getStatus()) {
		game.displayBoard();
		game.nextMove();
		
		if(game.checkWin()) 
			game.rematch();
		else
			game.switchPlayer();
	}
	
	std::cout << "\nThanks for playing\n";
	
	return 0;
}