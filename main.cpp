/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Julian Weisbord
 ** Date: 4/12/15
 ** Description: The main function runs the traditional connect
 4 game but with any number
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

#include <stdio.h>

using namespace std;

/*********************************************************************
 **Name: main
 ** Description: checks the number of arguments entered
 ** Input: row, column, and number of pieces integers
 ** Output: connect board
 *********************************************************************/
int main(int argc, char*argv[]){

	game connect_all;

	if (argc!= 7){
		cout<< "Invalid number of arguments!"<< endl;
		exit (0);
	}
	connect_all.is_valid_arguments(argv);
	connect_all.set_game_info(&connect_all, argv);

	//seg faults if you enter duplicate option
	if(connect_all.is_valid_arguments(argv) == true){
		bool check = false;
			//bool digi , digi2, digi3;
		do{
			connect_all.set_alt_info(&connect_all, argv);
			if ((!isdigit(connect_all.get_r()))&& (!isdigit(connect_all.get_c())) && (!isdigit(connect_all.get_p()))|| ((connect_all.get_r() == 0) || (connect_all.get_c() == 0) || (connect_all.get_p() ==0))){
				//cout<< connect_all.c<<endl;
				//cout<< connect_all.r<<endl;
				//cout<< connect_all.p<<endl;
				check =true;
			}


		}while(check == false);
	}



	connect_all.board = connect_all.create_table(connect_all.get_r(), connect_all.get_c());
	//cout<< connect_all.r<<endl;
	//cout << connect_all.c<< endl;
	connect_all.play_game(&connect_all);

}
