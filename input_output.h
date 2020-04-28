#ifndef FOCUS_INPUT_OUTPUT_H
#define FOCUS_INPUT_OUTPUT_H

#endif //FOCUS_INPUT_OUTPUT_H

#include "game_init.h"

//Function to print the board
void print_board(square board[BOARD_SIZE][BOARD_SIZE]);
//Function to print the player details
void print_players(player players[PLAYERS_NUM]);
//Function to input the player's moves
void input_move(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE]);

//Function to merge the player's desired stacks
piece *push(piece *top, square board[BOARD_SIZE][BOARD_SIZE]);
//Function to free the player's old stacks piece
piece *pop(piece *top);