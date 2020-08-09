//============================================================================
// Name        : TicTacToeGame.cpp
// Author      : James Ford
// Version     : v.1.0.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

void playerTurn(); 	//changes player who is playing
void p1Winner();		//player 1 winner announcement
void p2Winner();		//player 2 winner announcement
void tieGame();		//tie game announcement
void continuePlaying();  //provides players opportunity to play another round

static int global_variable_p1,
			global_variable_p2;

//wanted to develop the container for objects
class tictactoe{

public:

	string playerBoard[3][3],
	player,
	p1 = "X",
	p2 = "O";
};

/*******************************************************************
 * Prints the current board
 *******************************************************************/
void printGame(string arr[3][3]){

	cout << "INSTRUCTIONS: Player chooses the number \n"
			<< "to the corresponding position to mark their\n"
			<< "desired block." << endl;
	cout << "Player 1 [X], and Player 2 [O] \n";
    cout << ("###############################") << endl;
    cout << ("------------------------------");

    for (int i = 0; i < 3; i++)
    {
    	cout << endl;
        cout << "|" << setw(5);

        for (int j = 0; j < 3; j++){
            cout << arr[i][j] <<  setw(5) << "|" << setw(5);
        }
        cout << endl;
        cout << ("------------------------------") << endl;

    }
    cout << ("###############################\n");

}

/*******************************************************************
 * Reset the board for a new game and number the boxes
 *******************************************************************/
void resetBoard(string arr[3][3]){

	arr[0][0] = "1";
	arr[0][1] = "2";
	arr[0][2] = "3";
	arr[1][0] = "4";
	arr[1][1] = "5";
	arr[1][2] = "6";
	arr[2][0] = "7";
	arr[2][1] = "8";
	arr[2][2] = "9";

	return;
}//End clearBoard()

/*******************************************************************
 * Continuously check the board for a winner.
 *******************************************************************/
void checkGameStatus(string arr[3][3]){
	tictactoe game;

	//Check player1 possibilities
	//Checks if the player win across
	if(arr[0][0] == "X" && arr[0][1] == "X" && arr[0][2] == "X"){
		p1Winner();
	}
	if(arr[1][0] == "X" && arr[1][1] == "X" && arr[1][2] == "X"){
		p1Winner();
	}
	if(arr[2][0] == "X" && arr[2][1] == "X" && arr[2][2] == "X"){
		p1Winner();
	}
	//Checks if the player wins down
	if(arr[0][0] == "X" && arr[1][0] == "X" && arr[2][0] == "X"){
		p1Winner();
	}
	if(arr[0][1] == "X" && arr[1][1] == "X" && arr[2][1] == "X"){
		printGame(game.playerBoard);
		p1Winner();
	}
	if(arr[0][2] == "X" && arr[1][2] == "X" && arr[2][2] == "X"){
		p1Winner();
	}
	//Checks if the player wins diagonal
	if(arr[0][0] == "X" && arr[1][1] == "X" && arr[2][2] == "X"){
		p1Winner();
	}
	if(arr[0][2] == "X" && arr[1][1] == "X" && arr[2][0] == "X"){
		p1Winner();
	}

	//check player2 possibilities
	//checks if player wins across
	if(arr[0][0] == "O" && arr[0][1] == "O" && arr[0][2] == "O"){
		p2Winner();
	}
	if(arr[1][0] == "O" && arr[1][1] == "O" && arr[1][2] == "O"){
		p2Winner();
	}
	if(arr[2][0] == "O" && arr[2][1] == "O" && arr[2][2] == "O"){
		p2Winner();
	}
	//checks if player wins down
	if(arr[0][0] == "O" && arr[1][0] == "O" && arr[2][0] == "O"){
		p2Winner();
	}
	if(arr[0][1] == "O" && arr[1][1] == "O" && arr[2][1] == "O"){
		p2Winner();
	}
	if(arr[0][2] == "O" && arr[1][2] == "O" && arr[2][2] == "O"){
		p2Winner();
	}
	//checks if player wins diagonal
	if(arr[0][0] == "O" && arr[1][1] == "O" && arr[2][2] == "O"){
		p2Winner();
	}
	if(arr[0][2] == "O" && arr[1][1] == "O" && arr[2][0] == "O"){
		p2Winner();
	}
	//validate a tie game/draw
	else if (arr[0][0] != "1" && arr[0][1] != "2" && arr[0][2] !="3" &&
			arr[1][0] != "4" && arr[1][1] != "5" && arr[1][2] !="6"	&&
			arr[2][0] != "7" && arr[2][1] != "8" && arr[2][2] !="9"){
		tieGame();
	}

}

//main function to utilize objects
int main() {

	playerTurn();

	return 0;
}

/*******************************************************************
 * The playerTurn() function is the primary function of this game.
 * This function identifies the current players turn, and populates the game
 * board with the respective mark or symbol associated with the players
 * numeric selection of the game board.
 *******************************************************************/
void playerTurn(){
	tictactoe game;

	resetBoard(game.playerBoard);

	int a = 0,
			userSelection;

	//there are only 9 turns: player 1 will always be "X" and player 2 will always be "O"
	//Player 1 will always be the even turn and Player 2 odd.

		do {
			if (a == 0 || a == 2 || a == 4 || a == 6 || a == 8){
				game.player = game.p1;
				cout << endl << endl;
				printGame(game.playerBoard);
				cout << "Player 1 your move: \n";
				cin >> userSelection;

			}
			if (a == 1 || a == 3 || a == 5 || a == 7 || a == 9){
				game.player = game.p2;
				cout << endl << endl;
				printGame(game.playerBoard);
				cout << "Player 2 your move: \n";
				cin >> userSelection;
			}

			switch(userSelection){

			case 1: if(game.playerBoard[0][0] == "1"){ //if statement to validate user input and prevent overwriting
				game.playerBoard[0][0]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}	//keeps the turn on the same player until a proper selection is made
			break;
			case 2: if(game.playerBoard[0][1] == "2"){
				game.playerBoard[0][1]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}
			break;
			case 3: if(game.playerBoard[0][2] == "3"){
				game.playerBoard[0][2]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}
			break;
			case 4: if(game.playerBoard[1][0] == "4"){
				game.playerBoard[1][0]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}
			break;
			case 5: if(game.playerBoard[1][1] == "5"){
				game.playerBoard[1][1]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}
			break;
			case 6: if(game.playerBoard[1][2] == "6"){
				game.playerBoard[1][2]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}
			break;
			case 7: if(game.playerBoard[2][0] == "7"){
				game.playerBoard[2][0]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}
			break;
			case 8: if(game.playerBoard[2][1] == "8"){
				game.playerBoard[2][1]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}
			break;
			case 9: if(game.playerBoard[2][2] == "9"){
				game.playerBoard[2][2]= game.player;}
				else
				{cout << "Already selected! \n";
				a--;}
			break;
			default: cout << "Invalid Selection \n";
				a--;//keeps it on the selected player until a valid selection is made
			break;
			}//end switch

			a++; //increment to change player
			//print board and then check to see if there is a winner
			printGame(game.playerBoard);
			checkGameStatus(game.playerBoard);

			}while(a < 9);

}

/************************************************
 * keep count of the current round to identify which
 * player won what round.  Use pointers to keep
 * accurate 'win' count.
 ************************************************/
int countRound(){
	static int counter3 = 0;
	counter3++;
	return counter3;
}
//Named the function as a pointer value to a global variable
//to help with some confusion; also used.  Also, was able to
//get the desired results using double indirection to the pointer
//ptr_ptr to the global variable
void changeP1_PointerValue(int** ptr_ptr)
{
    *ptr_ptr = &global_variable_p1;
}

void changeP2_PointerValue(int** ptr_ptr)
{
    *ptr_ptr = &global_variable_p2;
}

/************************************************
 * Print the winner after each game or shows a
 * tie game - pointers increment to keep win score
 ************************************************/

void p1Winner(){
	ofstream out_stream;

	int var1 = 0,
			var2 = 0;
	int* pointer_to_var1 = &var1;
	int* pointer_to_var2 = &var2;


	cout<< "###############################\n";
	cout<< "#" << setw(31) << "#\n";
	cout<< "#" << "     PLAYER 1 WINS!!!" << setw(10) << "#\n";
	cout<< "#" << setw(31) << "#\n";
	cout<< "###############################\n";

	int round = countRound();

	changeP1_PointerValue(&pointer_to_var1);
	changeP2_PointerValue(&pointer_to_var2);

	out_stream.open("results.txt", ios_base::app);
	out_stream << "Wins after round " << round << endl;
	out_stream << "Player 1 has " << ++*pointer_to_var1 << " wins.\n";
	out_stream << "Player 2 has " << *pointer_to_var2 << " wins.\n" << endl;
	out_stream.close();

	continuePlaying();
}

void p2Winner(){
	ofstream out_stream;

	int var1 = 0,
			var2 = 0;
	int* pointer_to_var1 = &var1;
	int* pointer_to_var2 = &var2;

	cout<< "###############################\n";
	cout<< "#" << setw(31) << "#\n";
	cout<< "#" << "     PLAYER 2 WINS!!!" << setw(10) << "#\n";
	cout<< "#" << setw(31) << "#\n";
	cout<< "###############################\n";

	int round = countRound();

	changeP1_PointerValue(&pointer_to_var1);
	changeP2_PointerValue(&pointer_to_var2);

	out_stream.open("results.txt", ios_base::app);
	out_stream << "Wins after round " << round << endl;
	out_stream << "Player 1 has " << *pointer_to_var1 << " wins.\n";
	out_stream << "Player 2 has " << ++*pointer_to_var2 << " wins.\n"  << endl;
	out_stream.close();

	continuePlaying();
}

void tieGame(){
	ofstream out_stream;

	cout<< "###############################\n";
	cout<< "#" << setw(31) << "#\n";
	cout<< "#" << "          Tie Game!" << setw(12) << "#\n";
	cout<< "#" << setw(31) << "#\n";
	cout<< "###############################\n";

	int round = countRound();
	out_stream.open("results.txt", ios_base::app);
	out_stream << "Round " << round << endl;
	out_stream << "Tie game!\n" << endl;
	out_stream.close();

	continuePlaying();

}

/************************************************
 * Give players the opportunity to play multiple
 * games.  Use input validation and quit the game
 * if an invalid character is used.
 ************************************************/
void continuePlaying(){

	char input;

	while (input != 'Y' || input != 'N'){
		cout << "Would you like to play again? (y/n): \n";
		cin >> input;

		//toupper is a cool function that converts case to an available upper case
		//makes the (y/n) selection more cleaner and the below only allows for y/n option
			if(toupper(input) == 'Y'){
				main();

			}else if (toupper(input) == 'N'){
				cout << "Game win results can be found in 'results.txt'\nQuitting game.\n  ";
				exit(1);

			}else if(toupper(input) != 'Y'){
					if(toupper(input) != 'N'){
					cout << "Invalid selection! \n";
				}
			}
	}//end while
}