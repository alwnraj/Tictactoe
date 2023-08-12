#include <iostream>

using namespace std;

//This function creates a game board
void gameboard(char board[3][3]) {
	cout << "-------------" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " | ";
		}
		cout << endl;
		cout << "-------------" << endl;
	}
}

//this void function to check if any player has won 
bool checkwin( char board[3][3], char player1 ) {
	//check if coloumns and rows have a win
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == player1 && board[i][1] == player1 && board[i][2]==player1) ||
			(board[0][i] == player1 && board[1][i] == player1 && board[2][i]==player1))
		{
			return true;
		}
	}

	//check if diagonal coloumns have a win
	for (int j = 0; j < 3; j++) {
		if (board[0][0] == player1 && board[1][1] == player1 && board[2][2] == player1)
		{
			return true;
		}
	}

	return false;
} 

//check for a tie 
bool checktie( char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}



int main() {

	char board[3][3] = { { ' ',' ',' ' }, { ' ',' ',' ' }, { ' ',' ',' ' } };

	int row, col;
	char player1 = 'X';
	string currentplayer;

	cout << "Tic-Tac-Toe Game" << endl;
	cout << endl;
	cout << "Player 1: X" << endl;
	cout << "Player 2: O" << endl;
	cout << "Enter the position you want (row coloumn): ";
	cout << endl;

	while (1) {
		gameboard(board);

		cout << (player1=='X'? "Player 1 (X)" : "Player 2 (O)") << " please enter what coloumn you want to move to: ";
		cin >> row >> col;

		if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] !=' ') {
			cout << "Invalid input try again !"<<endl;
			break;
		}

		//making the move
		board[row - 1][col - 1]= player1;

		//check if player1 won
		if (checkwin(board, player1)) {
			gameboard(board);
			cout << "Player " << player1 << " has won !" << endl;
			break;
		}

		//check if it's a tie
		if (checktie(board)) {
			gameboard(board);
			cout << "It's a tie!"<<endl;
			break;
		}
		//switch to other player
		player1 = (player1 == 'X') ? 'O': 'X';
	}
}