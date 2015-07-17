/*********************************************************************
 ** Program Filename: connect_any.cpp
 ** Author: Julian Weisbord
 ** Date: 4/12/15
 ** Description: Contains all of the functions which will be called
 in main.
 ** Output: A connect game with a winner, loser and asks if the users
 want to play again.
 *********************************************************************/

#include <iostream>
#include "./connect_any.h"
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <locale>
#include <sstream>
using namespace std;

char game::get_p1(){
	return p1;
}
void game::set_p1(char player1){
	p1 = player1;
}
char game::get_p2(){
	return p2;
}
void game::set_p2(char player2){
	p2 = player2;
}

int game::get_r(){
	return r;
}

void game::set_r(int R){
	r = R;
}
int game::get_c(){
	return c;
}
void game::set_c(int C){
	c = C;
}
int game::get_p(){
	return p;
}
void game::set_p(int P){
	p = P;
}


/*********************************************************************
 ** Name: is_valid_arguments
 ** Description:makes sure that the arguments entered are posotive
 integers
 ** Input: None
 ** Output: error statements, reprompting, and program exitting
 *********************************************************************/
bool game::is_valid_arguments(char*info[]){
	//must be posotive int
	// do i need strcmp?
	bool foundR = false, foundP =  false, foundC = false;
	bool digi = false, digi2 = false, digi3 =false;

	for(int x =0; x< 7; x++){
		if(strcmp(info[x], "-p")==0){
			if(info[x+1][0] == '-'){
				(digi == false && digi2 == false && digi3 == false);
				return true;
			}
		}
		else if(strcmp(info[x],"-r")==0){
			if(info[x+1][0] == '-'){
				(digi == false && digi2 == false && digi3 == false);
				return true;
			}
		}
		else if(strcmp(info[x], "-c")==0){
			if(info[x+1][0] == '-'){
				(digi == false && digi2 == false && digi3 == false);
				return true;

			}

		}
	}


	for (int i = 1; i <7; i++){
		if(strcmp(info[i], "-r")==0){
			foundR =  true;
			if(isdigit(*info[i+1])){
				digi = true;
				if(*info[i+1] == '0'){
					digi = false;

				}

			}
		}
		if(strcmp(info[i], "-c")==0){
			foundC = true;
			if(isdigit(*info[i+1])){
				digi2 = true;
				if(*info[i+1] == '0'){
					digi2 = false;

				}
			}
		}
		if(strcmp(info[i], "-p")==0){
			foundP = true;
			if(isdigit(*info[i+1])){
				digi3 = true;
				if(*info[i+1] == '0'){
					digi3 = false;

				}
			}
		}


	}
	if (foundR == false || foundC == false || foundP == false){
		cout<< "error missing atleast one argument!"<< endl;
		exit (0);
		return false;


	}
	if(digi == false || digi2 == false || digi3 == false){
		cout<< "Bad Data!"<< endl;
		return true;
	}

	//return false;
//ERRRORS




}
/*********************************************************************
 ** Name: set_game_info
 ** Description: sets the command line arguments to struct values
 ** Input: None
 ** Output: command line args
 *********************************************************************/
void game::set_game_info(game* xpoint, char* info[]){
	for(int x = 0; x <7; x++){
		if(strcmp(info[x], "-r")==0){
			xpoint->set_r(atoi(info[x+1]));
		}
		if(strcmp(info[x], "-c")==0){
			xpoint->set_c(atoi(info[x+1]));
		}
		if(strcmp(info[x], "-p")==0){
			xpoint->set_p(atoi(info[x+1]));
		}

	}
}
/*********************************************************************
 ** Name: set_alt_info
 ** Description: sets the command line arguments to struct values
 if the user did not enter correct arguments initially.
 ** Input: None
 ** Output: command line args
 *********************************************************************/
void game::set_alt_info(game*xpoint, char*info[]){
	int c;
	cout<< "Please enter a posotive number for c"<< endl;
	cin>> c;
	xpoint->set_c(c);
	cout<< "Please enter a posotive number for r"<< endl;
	cin>>r;
	xpoint->set_r(r);
	cout<< "Please enter a posotive number for p"<< endl;
	cin>> p;
	xpoint->set_p(p);
}
/*********************************************************************
 ** Name: create_table
 ** Description: creates a dynamic 2-D array.
 ** Input: the rows and columns from command line arguments.
 ** Output: 2D board array.
 *********************************************************************/
char** game::create_table(int rows, int cols){

	char** cats = new char*[rows];

	for (int i = 0; i< rows; i++){
		cats[i] = new char[cols];

		for (int j= 0; j<cols; j++){
			cats[i][j] = ' ';
		}
	}
	return cats;
}
/*********************************************************************
 ** Name: play_game
 ** Description: the users enter values into the 2d array and they
 will eventually tie, win, or lose.
 ** Input: piece choice, 2 players.
 ** Output: pieces into the 2D array, a winner and loser, or a tie.
 *********************************************************************/
void game::play_game(game*xpoint){
	cout<< "Player 1 do you want blue or yellow?(b or y): "<< endl;
	cin>>p1;
	xpoint->set_p1(p1);

	cout<< "Player 2 do you want blue or yellow?(b or y): "<< endl;
	cin>>p2;
	xpoint->set_p2(p2);

	int c1, c2;
	bool winCheck = false;
	do{
		cout<< "Player 1, what column do you want to put your piece in: "<< endl;
		cin>> c1;

//reprompt or exit if column is greater than number of columns also pieces cant be greater than rows and columns.
// overflow check doesn't work
		int j = ((c1)-1);
		int x = xpoint->r;
		for(int i = (x-1); i>=0 ; i--){
			if((xpoint->board[i][j]!= 'b') && (xpoint->board[i][j] != 'y')){
				if ((xpoint->board[0][(c1)-1] == 'b') || (xpoint->board[0][(c1)-1] == 'y')){
					cout << "Yo! That column is full" << endl;
					exit (0);
				}
				else{
					//xpoint->board[i][j] = xpoint->p1;
					xpoint->board[i][j] = xpoint->get_p1();
				}
				break;

			}

		}


		print_array(&(*xpoint));

		if(check_winner(*xpoint) == true){
			string answer;
			cout<< "You won!!!! Do you want to play again?(y or n): "<< endl;
			cin>> answer;
			if(answer == "y"){
				winCheck = false;
			}
			else{
				winCheck = true;
				exit(0);
			}
			delete_table(&(*xpoint));
			xpoint->board = create_table(xpoint->r, xpoint->c);
		}


		cout<< "Player 2, what column do you want to put your piece in:"<< endl;
		cin >> c2;

		int b = ((c2)-1);
		int a = xpoint->r;
		for(int i = (a-1); i>=0 ; i--){
			if((xpoint->board[i][b]!= 'b') && (xpoint->board[i][b] != 'y')){
				if ((xpoint->board[0][(c2)-1] == 'b') || (xpoint->board[0][(c2)-1] == 'y')){
					cout << "Yo! That column is full" << endl;
					exit (0);
				}
				else{
					xpoint->board[i][b] = xpoint->p2;
				}
				break;

			}

		}
		print_array(&(*xpoint));



		if(check_winner(*xpoint) == true){
			string answer;
			cout<< "You won!!!! Do you want to play again?(y or n): "<< endl;
			cin>> answer;
			if(answer == "y"){
				winCheck = false;
			}
			else{
				winCheck = true;
				exit(0);
			}
			delete_table(&(*xpoint));
			xpoint->board = create_table(xpoint->r, xpoint->c);
		}

	}while(winCheck == false);

}
/*********************************************************************
 ** Name: print_array
 ** Description: prints the values of the 2D array.
 ** Input: None
 ** Output: the 2D array to the command line.
 *********************************************************************/
void game::print_array(game*xpoint){
	for (int x = 0; x< xpoint->r; x++){
		cout << "|";
		for(int y = 0; y< xpoint->c; y++){
			cout << xpoint->board[x][y]<< "|";
		}
		cout<< " "<< endl;

		for (int k = 0; k< xpoint->c; k++){
			cout<< "__";
		}
		cout<< " "<< endl;
	}
}
/*********************************************************************
 ** Name: check_winner
 ** Description: checks the elements entered into the 2d array. If
 there are as many of the same adjacent pieces as p in struct, that
 player will win.
 ** Input: checking functions.
 ** Output: true
 *********************************************************************/
bool game::check_winner(game var){
	diagonal_left(var);


	if(diagonal_left(var) == true){
		return true;
	}
	else{
		return false;
	}
}


/*********************************************************************
 ** Name: diagonal_left
 ** Description: checks if there is p diagonal of the same piece
 starting on the left and going right
 ** Input: None
 ** Output: winner or not.
 *********************************************************************/
bool game::diagonal_left(game var){
	if(diagonal_left_b(var) == true){
		return true;
	}

	else if(diagonal_left_y(var) == true){
		return true;
	}


	return false;

}
/*********************************************************************
 ** Name: diagonal_left_b
 ** Description: checks if there is p diagonal of b
 starting on the left and going right
 ** Input: None
 ** Output: winner or not.
 *********************************************************************/
bool game::diagonal_left_b(game var){
	int i,j,z, value = 0;
	for(i = 0; i<= ((var.r - var.p)); i++){
		//cout << "In First Loop"<< endl;
		for (j = 0; j <= ((var.c-var.p)); j++ ){
			//cout<< "In the second loop"<< endl;
			for (z = 0; z <var.p; z++ ){
				//cout<< "In the third loop"<< endl;
				if(var.board[i+z][j+z] == 'b'){


					value += 1 ;


					if(value == var.p){
						//cout<< "player b has won"<< endl;
						return true;
					}

				}
			}
			value = 0;
		}
	}
	return false;
}
/*********************************************************************
 ** Name: diagonal_left_y
 ** Description: checks if there is p diagonal of y pieces
 starting on the left and going right
 ** Input: None
 ** Output: winner or not.
 *********************************************************************/
bool game::diagonal_left_y(game var){
	int i,j,z, value = 0;
	for(i = 0; i<= ((var.r - var.p)); i++){
		//cout << "In First Loop"<< endl;
		for (j = 0; j <= ((var.c-var.p)); j++ ){
			//cout<< "In the second loop"<< endl;
			for (z = 0; z <var.p; z++ ){
				//cout<< "In the third loop"<< endl;
				//cout<< "value is"<<value << endl;
				if(var.board[i+z][j+z] == 'y'){


					value += 1 ;


					if(value == var.p){
						//cout<< "player y has won"<< endl;
						return true;
					}

				}
			}
			value = 0;

		}
	}
	return false;
}

/*********************************************************************
 ** Name: delete_table
 ** Description: deletes the 2D array
 ** Input: None
 ** Output: frees memory
 *********************************************************************/

void game::delete_table(game*xpoint){
	for(int i = 0; i<xpoint->r; i++){
		delete [] xpoint->board[i];
	}
	delete []xpoint->board;
}
