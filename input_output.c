#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"

/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R |
 * The number of pieces in the stack are printed before the colour | 0: -|*/

void print_players(player players[PLAYERS_NUM]){
    for(int i = 1; i <= PLAYERS_NUM; i++){
        printf("\nPlayer%d name: %s", i, players[i].player_name);
        printf("Player%d colour: ", i);
        if(players[i].player_colour == RED)  printf("RED\n");
        if(players[i].player_colour == GREEN) printf("GREEN\n");
        printf("Player%d own pieces: %d\n", i, players[i].player_pieces);
        printf("Player%d captured pieces: %d\n", i, players[i].opponent_pieces);
    }

}

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("\n******************* The Board *******************\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("| %d: -", board[i][j].num_pieces);
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



int x_p1, y_p1, x_p2, y_p2; // Variables to store UI for position of their piece
int m_p1, m_p2; // Variable to store UI for new position to move to
int choice_p1, choice_p2; // Variables to store UI for number of positions to move
int z_p1, w_p1, z_p2, w_p2; // Variables to store the position of the desired square to move to



void input_move(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE]) {

// Player 1 turn
    printf("\nPlayer1: %s ", players[1].player_name);
    printf("\nSelect the position of a RED piece to move (e.g 1  2):");
    scanf("%d %d", &x_p1, &y_p1);
    // Check for a valid piece
    if (board[x_p1][y_p1].type == VALID && board[x_p1][y_p1].stack->p_color == RED) {
        z_p1 = x_p1;
        w_p1 = y_p1;
        printf("\nHow any moves would you like to make? :");
        scanf("%d", &m_p1);
        // Check for a valid size of the stack to move
        if (m_p1 <= board[x_p1][y_p1].num_pieces) {
            // While the number of moves isn't exceeded
            for (int i = 0; i < m_p1; i++) {
                printf("\nMove (1)UP, (2)DOWN, (3)LEFT or (4)RIGHT? :"); // Prompt for each iteration
                scanf("%d", &choice_p1);
                if (choice_p1 == 1) {
                    z_p1 = z_p1 - 1;// Decrease by 1 the x coordinate to make a move to the up
                    printf("%s: UP", players[1].player_name);
                } else if (choice_p1 == 2) {
                    z_p1 = z_p1 + 1;// Increase by 1 the x coordinate to make a move to the down
                    printf("%s: DOWN", players[1].player_name);
                } else if (choice_p1 == 3) {
                    w_p1 = w_p1 - 1;// Decrease by 1 the y coordinate to make a move to the left
                    printf("%s: LEFT", players[1].player_name);
                } else if (choice_p1 == 4) {
                    w_p1 = w_p1 + 1;// Increase by 1 the y coordinate to make a move to the right
                    printf("%s: RIGHT", players[1].player_name);
                }
            }
            // Condition to make sure new position is on the board
            if (board[z_p1][w_p1].type == VALID) {
                // Call function to merge stacks at x_p1, y_p1 and z_p1, w_p1
                // push(board[x_p1][y_p1], piece * top);
                // Update the number of pieces
                board[x_p1][y_p1].num_pieces = board[x_p1][y_p1].num_pieces - m_p1;
                // Update the number of pieces
                board[z_p1][w_p1].num_pieces = board[z_p1][w_p1].num_pieces + m_p1;
            } else {
                printf("\nNot a valid square to move to.");
            }
        } else {
            printf("Error: Not a valid input. Stack not big enough\nTry Again\n");
        }
    } else {
        printf("Error: Not a valid position for a RED piece\nTry Again\n");
    }

// Player 2 turn
    printf("\nPlayer2: %s ", players[2].player_name);
    printf("\nSelect the position of a GREEN piece to move (e.g 2  1):");
    scanf("%d %d", &x_p2, &y_p2);
    // Check for a valid piece
    if (board[x_p2][y_p2].type == VALID && board[x_p2][y_p2].stack->p_color == GREEN) {
        z_p2 = x_p2;
        w_p2 = y_p2;
        printf("\nHow any moves would you like to make? :");
        scanf("%d", &m_p2);
        // Check for a valid size of the stack to move
        if (m_p2 <= board[x_p2][y_p2].num_pieces) {
            // While the number of moves isn't exceeded
            for (int i = 0; i < m_p2; i++) {
                printf("\nMove (1)UP, (2)DOWN, (3)LEFT or (4)RIGHT? :"); // Prompt for each iteration
                scanf("%d", &choice_p2);
                if (choice_p2 == 1) {
                    z_p2 = z_p2 - 1;// Decrease by 1 the x coordinate to make a move to the up
                    printf("%s: UP", players[1].player_name);
                } else if (choice_p2 == 2) {
                    z_p2 = z_p2 + 1;// Increase by 1 the x coordinate to make a move to the down
                    printf("%s: DOWN", players[1].player_name);
                } else if (choice_p2 == 3) {
                    w_p2 = w_p2 - 1;// Decrease by 1 the y coordinate to make a move to the left
                    printf("%s: LEFT", players[1].player_name);
                } else if (choice_p2 == 4) {
                    w_p2 = w_p2 + 1;// Increase by 1 the y coordinate to make a move to the right
                    printf("%s: RIGHT", players[2].player_name);
                }
            }
            // Condition to make sure new position is on the board
            if (board[z_p2][w_p2].type == VALID) {
                // Call function to merge stacks at x_p2, y_p2 and z_p2, w_p2

                // Update the number of pieces
                board[x_p2][y_p2].num_pieces = board[x_p2][y_p2].num_pieces - m_p2;
                // Update the number of pieces
                board[z_p2][w_p2].num_pieces = board[z_p2][w_p2].num_pieces + m_p2;
            } else {
                printf("Error: Not a valid input. Stack not big enough.\nTry Again\n");
            }
        } else {
            printf("Error: Not a valid position for a GREEN piece.\nTry Again\n");
        }
    }
}



/*
piece *push(piece * top, square board[BOARD_SIZE][BOARD_SIZE]){

    piece *curr = top;
    top = malloc(sizeof(piece));
    top->p_color = board[z_p1][w_p1].stack->p_color;
    piece * next = curr;
    return top;

}

piece * pop(piece *top){
    piece *curr = top;
    if(curr!=NULL){
        top = curr->next;
        free(curr);
    }
    return top;
}

 */