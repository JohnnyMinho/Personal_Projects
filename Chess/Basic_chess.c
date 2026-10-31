#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "Chess_Pieces.h"
#include "basicChessMenu.h"
#include "gamelogic.h"

#define chessBoardxSize 8
#define chessBoardySize 8 // 8 + 1 for array sizes since we need to terminate it
#define whiteStartPos 0
#define blackStartPos 7
#define BlackChessNumber 16
#define WhiteChessNumber 16

//Initial board is drawn with the entire pieces on the correct pos
void render_board_test(){

    struct board_pos **chess_board = (struct board_pos**)malloc(sizeof(struct board_pos*) * chessBoardySize);
    for(int i = 0; i < chessBoardySize; i++){
        chess_board[i] = (struct board_pos*)malloc(sizeof(struct board_pos) * chessBoardxSize);
    }

    const char * const *whitePieces = generateWhitePieces();
    const char * const *blackPieces = generateBlackPieces();

    //Fill the positions with the pieces
    for(int whitePiecesRows = 0; whitePiecesRows < 2; whitePiecesRows++){
        for(int pieceInBoard = 0; pieceInBoard < chessBoardxSize; pieceInBoard++){
            if(whitePiecesRows == 0){
                chess_board[whiteStartPos][pieceInBoard].y_pos = whiteStartPos;
                chess_board[whiteStartPos][pieceInBoard].x_pos = pieceInBoard;
                if(pieceInBoard == 0 || pieceInBoard == 7){
                    chess_board[whiteStartPos][pieceInBoard].current_piece = whitePieces[2][0];
                }else if(pieceInBoard == 1 || pieceInBoard == 6){
                    chess_board[whiteStartPos][pieceInBoard].current_piece = whitePieces[4][0];
                }else if(pieceInBoard == 2 || pieceInBoard == 5){
                    chess_board[whiteStartPos][pieceInBoard].current_piece = whitePieces[3][0];
                }else if(pieceInBoard == 3){
                    chess_board[whiteStartPos][pieceInBoard].current_piece = whitePieces[1][0];
                }else if(pieceInBoard == 4){
                    chess_board[whiteStartPos][pieceInBoard].current_piece = whitePieces[0][0];
                }
            }else if(whitePiecesRows == 1){
                chess_board[whiteStartPos+1][pieceInBoard].current_piece = whitePieces[5][0];
            }
        }
        
    }

    for(int blackPiecesRows = 0; blackPiecesRows < 2; blackPiecesRows++){
        for(int pieceInBoard = 0; pieceInBoard < chessBoardxSize; pieceInBoard++){
            chess_board[blackPiecesRows][pieceInBoard].y_pos = blackPiecesRows;
            chess_board[blackPiecesRows][pieceInBoard].x_pos = pieceInBoard;
            if(blackPiecesRows == 0){
                if(pieceInBoard == 0 || pieceInBoard == 7){
                    chess_board[blackStartPos][pieceInBoard].current_piece = blackPieces[2][0];
                }else if(pieceInBoard == 1 || pieceInBoard == 6){
                    chess_board[blackStartPos][pieceInBoard].current_piece = blackPieces[4][0];
                }else if(pieceInBoard == 2 || pieceInBoard == 5){
                    chess_board[blackStartPos][pieceInBoard].current_piece = blackPieces[3][0];
                }else if(pieceInBoard == 3){
                    chess_board[blackStartPos][pieceInBoard].current_piece = blackPieces[0][0];
                }else if(pieceInBoard == 4){
                    chess_board[blackStartPos][pieceInBoard].current_piece = blackPieces[1][0];
                }
            }else if(blackPiecesRows == 1){
                chess_board[blackStartPos-1][pieceInBoard].current_piece = blackPieces[5][0];
            }
        }
    }

    for(int yPos = 0; yPos < chessBoardySize; yPos++){
        for(int xPos = 0; xPos < chessBoardxSize; xPos++){
            printf("%c ", chess_board[yPos][xPos].current_piece);
        }
        printf("\n");
    }

}


void *Runit(void *arg)
{
    (void)arg;
    if (system("gnome-terminal -- bash -lc './ChessGame; exec bash'") != 0) {
        perror("gnome-terminal");
    }
    return NULL;
}

int main(int argc, char* argv[]){

    char userChoice = loadmenu();
    
    printf("%c\n", userChoice);
    
    if(userChoice == '3'){
        //Mapping of chess pieces test
        SimpleKeyPairPrintTest();
        //Chess board rendering part
        render_board_test();
        //Need a way to choose a chess piece, current location, next location and other information for this gamelogic part
        int x = 4;
        int y = 4;
        char testpiece = 'b';
        char movement[2] = {"A6"};
        isValidMovement(&x,&y,movement,testpiece,0);
        pthread_t child;
        pthread_create(&child, NULL, Runit, NULL);
        sleep(10);
    }
    return 0;
}