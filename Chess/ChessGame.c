#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Chess_Pieces.h"
#include "gamelogic.h"
#include "basicInputReader.h"

#define chessBoardxSize 8
#define chessBoardySize 8 // 8 + 1 for array sizes since we need to terminate it
#define whiteStartPos 0
#define blackStartPos 7
#define BlackChessNumber 16
#define WhiteChessNumber 16

struct board_pos ** generate_board(){

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

    return chess_board;
}

void render_board(struct board_pos **current_board){
    for(int i = 0; i < chessBoardxSize; i++){
        for(int j = 0; j < chessBoardySize; j++){
            if(current_board[i][j].current_piece == NULL){
                printf("| |");
            }else{
                printf("|%c|",current_board[i][j].current_piece);
            }
        }
        printf("\n");
    }
}

void move_piece(){
    
}

//When a piece is moved the entire board isn't re-rendered, only the pos is redone
char re_render_board(){
    return 66;
}


//This is gonna be the chess game program itself
//If any of the user input presents an error we will goto the beginning of the cycle.
int main(){

    printf("Chess Game\n");
    int game_ended = 0;
    int player_turn = 0; // 0 -> whites, 1 -> black
    

    struct board_pos **chess_board = generate_board();
    render_board(chess_board);
    
    while(game_ended == 0){
        char *player_input = (char *)malloc(sizeof(char)*2);
        int validGameInput = 0;
        switch (player_turn){
            case 1:
                printf("White side turn\n");
                printf("Choose which piece to move:");
                while(quickReadGameInput(2, player_input) == 0){
                    clear_console();
                    printf("")
                }
                break;
            case 0:
                printf("Black side turn\n");
                printf("Choose which piece to move:");
                if(quickReadGameInput(2, player_input) == 1){

                }
                
                break;
        }
        free(player_input);
    }

    return 1;
}