#include <stdio.h>
#include <stdlib.h>
#include "Chess_Pieces.h"
#include "basicChessMenu.h"

#define chessBoardxSize 8
#define chessBoardySize 8 // 8 + 1 for array sizes since we need to terminate it
#define whiteStartPos 0
#define blackStartPos 7
#define BlackChessNumber 16
#define WhiteChessNumber 16

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

//Initial board is drawn with the entire pieces on the correct pos
void DrawInitialBoardTest(){

    printf("A -> %d\n", chessBoardxSize);

    const char * const *whitePieces = generateWhitePieces();
    const char * const *blackPieces = generateBlackPieces();

    char **chess_board = (char**)malloc(sizeof(char*) * chessBoardySize);
    chess_board[8] = '\0';
    for(int i = 0; i < chessBoardxSize; i++){
        chess_board[i] = (char*)malloc(sizeof(char) * chessBoardxSize);
        chess_board[i][8] = '\0';
    }

    //Fill the positions with the pieces
    for(int whitePiecesRows = 0; whitePiecesRows < 2; whitePiecesRows++){
        for(int pieceInBoard = 0; pieceInBoard < chessBoardxSize; pieceInBoard++){
            if(whitePiecesRows == 0){

                if(pieceInBoard == 0 || pieceInBoard == 7){
                    chess_board[whiteStartPos][pieceInBoard] = whitePieces[2][0];
                }else if(pieceInBoard == 1 || pieceInBoard == 6){
                    chess_board[whiteStartPos][pieceInBoard] = whitePieces[4][0];
                }else if(pieceInBoard == 2 || pieceInBoard == 5){
                    chess_board[whiteStartPos][pieceInBoard] = whitePieces[3][0];
                }else if(pieceInBoard == 3){
                    chess_board[whiteStartPos][pieceInBoard] = whitePieces[1][0];
                }else if(pieceInBoard == 4){
                    chess_board[whiteStartPos][pieceInBoard] = whitePieces[0][0];
                }
            }else if(whitePiecesRows == 1){
                chess_board[whiteStartPos+1][pieceInBoard] = whitePieces[5][0];
            }
        }
        
    }

    for(int blackPiecesRows = 0; blackPiecesRows < 2; blackPiecesRows++){
        for(int pieceInBoard = 0; pieceInBoard < chessBoardxSize; pieceInBoard++){
            if(blackPiecesRows == 0){
                if(pieceInBoard == 0 || pieceInBoard == 7){
                    chess_board[blackStartPos][pieceInBoard] = blackPieces[2][0];
                }else if(pieceInBoard == 1 || pieceInBoard == 6){
                    chess_board[blackStartPos][pieceInBoard] = blackPieces[4][0];
                }else if(pieceInBoard == 2 || pieceInBoard == 5){
                    chess_board[blackStartPos][pieceInBoard] = blackPieces[3][0];
                }else if(pieceInBoard == 3){
                    chess_board[blackStartPos][pieceInBoard] = blackPieces[0][0];
                }else if(pieceInBoard == 4){
                    chess_board[blackStartPos][pieceInBoard] = blackPieces[1][0];
                }
            }else if(blackPiecesRows == 1){
                chess_board[blackStartPos-1][pieceInBoard] = blackPieces[5][0];
            }
        }
    }

    for(int i = 0; i < chessBoardySize; i++){
        for(int j = 0; j < chessBoardxSize; j++){
            printf("%c ", chess_board[i][j]);
        }
        printf("\n");
    }
}

//When a piece is moved the entire board isn't re-rendered, only the pos is redone
char re_render_board){
    return 66;
}

void move_piece(){
    
}

int main(int argc, char* argv[]){

    char userChoice = loadmenu();
    printf("%c\n", userChoice);
    //SimpleKeyPairPrintTest();
    DrawInitialBoardTest();
    return 0;
}