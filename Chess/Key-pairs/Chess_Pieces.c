#include <stdio.h>
#include <stdlib.h>

static const char *WhitePieces[6] = {
    "K",
    "Q",
    "R",
    "B",
    "N",
    "P"
};

static const char *BlackPieces[6] = {
    "k",
    "q",
    "r",
    "b",
    "n",
    "p"
};

const char * const * generateBlackPieces(void){
    return BlackPieces;
}

const char * const * generateWhitePieces(void){
    return WhitePieces;
}

void SimpleKeyPairPrintTest(void){
    const char * const * whitePieces = generateWhitePieces();
    const char * const * blackPieces = generateBlackPieces();
    /*Mapped_Pieces[0][0] = '♚';
    Mapped_Pieces[1][0] = '♛';
    Mapped_Pieces[2][0] = '♜';
    Mapped_Pieces[3][0] = '♝';
    Mapped_Pieces[4][0] = '♞';
    Mapped_Pieces[5][0] = '♟';
    Mapped_Pieces[6][0] = '♔';
    Mapped_Pieces[7][0] = '♕';
    Mapped_Pieces[8][0] = '♖';
    Mapped_Pieces[9][0] = '♗';
    Mapped_Pieces[10][0] = '♘';
    Mapped_Pieces[11][0] = '♙';*/

    for(int i = 0 ; i < 6; i++){
        printf("White Pieces: %c\nBlack Pieces: %c\n", whitePieces[i][0], blackPieces[i][0]);
    }

}