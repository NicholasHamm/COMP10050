//
// Created by Lili on 26/03/2020.
//

//
// Created by Lili on 24/03/2020.
//

#include <stdio.h>
#include "input_output.h"

/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_players(player players[PLAYERS_NUM]){
    for(int i = 1; i <= PLAYERS_NUM; i++){
        printf("\nPlayer%d name: %s", i, players[i].player_name);
        printf("Player%d colour:", i);
        if(players[i].player_colour == RED)  printf("RED\n");
        if(players[i].player_colour == GREEN) printf("GREEN\n");
        printf("Player%d own pieces: %d\n", i, players[i].player_pieces);
        printf("Player%d captured pieces: %d\n", i, players[i].opponent_pieces);
    }

}

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("| %d:  ", board[i][j].num_pieces);
                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| %d:G ", board[i][j].num_pieces);
                    else printf("| %d:R ", board[i][j].num_pieces);
                }
            }
            else
                printf("|  -  ");
        }
        printf("|\n");
    }
}