#include "input_output.h"


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);
    initialize_board(board);

    print_players(players);
    print_board(board);
    input_move(players, board);
    print_board(board);

    /*
     * Functionality to decide the winner
     *
     *
    int green = 0;
    int red = 0;


    for(int i = 0; i < BOARD_SIZE; i ++){
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j].type == VALID) {
                        if (board[i][j].stack->p_color == GREEN){ green = green + 1;}
                        else if (board[i][j].stack->p_color == RED){ red = red + 1;}
                    }
                }
                if(green == 0 ){
                    printf("\n\nGAME OVER\n\nRED WINS. Congratulations %s", players[1].player_name);
                    return 0;
                }
                if(red == 0 ){
                    printf("\n\nGAME OVER\n\nGREEN WINS. Congratulations %s", players[2].player_name);
                    return 0;
                }
                else{
                    input_move(players, board);
                    print_board(board);
                }

            }

            */

    return 0;
}
