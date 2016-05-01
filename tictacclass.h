#ifndef TICTACCLASS_H
#define TICTACCLASS_H
class TicTacClass {
	public:
				TicTacClass();
		bool 	checkWin();
		bool 	getStatus();
		bool 	rematch();
		void 	displayBoard();
		void 	nextMove();
		void 	switchPlayer();

	private:
		bool 	status_;
		bool 	validatePosition(int, int);
		bool 	validateValue(int, int []);
		bool 	won_;
		int 	currentPlayer_;
		int 	spaces_[3][3];
		void 	printCell(int, int);
		void	resetGame();
};
#endif