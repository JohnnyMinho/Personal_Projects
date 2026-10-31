#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <stdbool.h>

struct chess_piece{ 
    char Type; // K, Q, R, B, N, P for white pieces and k, q, r, b, n, p for black pieces
    int y_pos; //0-7
    int x_pos; //a-g is 0-7
};

struct board_pos{
    char current_piece;
    int y_pos;
    int x_pos;
};


bool isValidMovement(int *xPos, int *yPos,char *movement, char pieceType, int isPosOccupied);
int * convertMovementToPos(char *charToInt);
char convertPiece(); //When a pawn hit the last spot in the opposing side we ask the user if he wants to convert the pawn and to which piece


#endif