/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Julian Weisbord
 ** Date: 4/12/15
 ** Description: this header file contains the struct and the function prototypes.
 ** Output: Struct and function uses
 *********************************************************************/
#ifndef CONNECT_ANY_H
#define CONNECT_ANY_H


class game{
private:

int r, c, p;
char p1;
char p2;

public:
char **board;
char get_p1();
void set_p1(char);
char get_p2();
void set_p2(char);

int get_r();
void set_r(int);
int get_c();
void set_c(int);
int get_p();
void set_p(int);

bool is_valid_arguments(char*info[]);
void set_game_info(game*, char*info[]);
void set_alt_info(game*, char* info[]);
char **create_table(int,int);
void play_game(game*);
bool check_winner(game);
bool diagonal_left(game);
void print_array(game*);
bool diagonal_left_b(game);
bool diagonal_left_y(game);
void delete_table(game*);
};

#endif
