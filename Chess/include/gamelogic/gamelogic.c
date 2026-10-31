#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Aux function declaration *
int convertXOrYToInt(char xOrY);

//*

int * convertMovementToPos(char *charToInt);

//0 -> false | 1 -> positive, also alters the received x and y
int isValidMovement(int *xPos, int *yPos, char *movement ,char pieceType,int isPosOccupied){
    printf("%s\n",movement);
    int *convertedMovement = convertMovementToPos(movement);
    if(convertedMovement[0] == 9){
        printf("Your movement is invalid [bad input] \n");
        return 0;
    }
    int currentXPOS = *(xPos);
    printf("Hello\n");
    int currentYPOS = *(yPos);
    
    int convertedXMovement = convertedMovement[0];
    int convertedYMovement = convertedMovement[1];
    
    if(convertedXMovement == currentXPOS && convertedYMovement == currentYPOS){
            printf("Invalid %c movement\n", pieceType);
            return 0;
        }
    //Pawn
    if(pieceType == 'P' || pieceType == 'p'){
        if(convertedYMovement<currentYPOS){
            printf("Invalid Pawn movement\n");
            return 0;
        }
        if(isPosOccupied == 0){
            if(currentXPOS != convertedXMovement || (convertedYMovement>currentYPOS+2)){
                printf("Invalid Pawn movement\n");
                return 0;
            }
        }else{
            if((convertedXMovement > currentXPOS+1) || (convertedYMovement>currentYPOS+1)){
                printf("Invalid Pawn movement\n");
                return 0;
            }
        }
    }
    //King
    if(pieceType == 'K' || pieceType == 'k'){
        int x_difference = currentXPOS - convertedXMovement;
        int y_difference = currentYPOS - convertedYMovement;
        if(y_difference < 0 ){
            y_difference = -(y_difference);
        }
        if(x_difference < 0){
            x_difference = -(x_difference);
        }
        if((x_difference > 1) || (y_difference > 1)){
            printf("Invalid King movement\n");
            return 0;
        }
    }
    //Rook
    if(pieceType == 'R' || pieceType == 'r'){
        if((convertedXMovement == currentXPOS && convertedYMovement != currentYPOS) || (convertedXMovement != currentXPOS && convertedYMovement == currentYPOS)){
            //One of the rare cases where doing this is actually easier
        }else{
            printf("Invalid Rook movement\n");
            return 0;
        }
    }
    //Knight / Horse / Noble
    if(pieceType == 'N' || pieceType == 'n'){
        int x_difference = currentXPOS - convertedXMovement;
        int y_difference = currentYPOS - convertedYMovement;
        if(y_difference < 0 ){
            y_difference = -(y_difference);
        }
        if(x_difference < 0){
            x_difference = -(x_difference);
        }
        if(!((x_difference == 2 && y_difference == 1) || (x_difference == 1 && y_difference == 2))){
            printf("Invalid Noble movement\n");
            return 0;
        }
    }
    //Bishop
    if(pieceType == 'B' || pieceType == 'b'){
        if((convertedXMovement-currentXPOS != convertedYMovement-currentYPOS)){
            printf("Invalid Bishop movement\n");
            return 0;
        }
    }
    //Queen
    if(pieceType == 'Q' || pieceType == 'q'){
        //Horizotal-Vertical movement
        if((convertedXMovement == currentXPOS && convertedYMovement != currentYPOS) || (convertedXMovement != currentXPOS && convertedYMovement == currentYPOS)){
            //One of the rare cases where doing this is actually easier
        }else{
            //Diagonal movement
            if((convertedXMovement-currentXPOS != convertedYMovement-currentYPOS)){
                printf("Invalid Bishop movement\n");
                return 0;
            }
        }
    }

    *xPos = convertedXMovement;

    *yPos = convertedYMovement;
    return 1;
} 

char convertPiece(){
    return 'a';
}

//x -> A to H y-> 1 to 8
int * convertMovementToPos(char *charToInt){
    int * convertedMovement = (int*)malloc(sizeof(int)*2);
    convertedMovement[0] = 9;
    convertedMovement[1] = 9;
    int string_size = 0;
    if(!(charToInt[0] != '\0' && charToInt[1] != '\0')){
        return convertedMovement;
    }
    while(charToInt[string_size] != '\0'){
        string_size++;
    }
    if(string_size >= 3){
        size_t size = sizeof(charToInt);
        return convertedMovement; //We have too much text in the position string
    }
    int asciiValueYPos = (int) charToInt[0];
    int asciiValueXPos = (int) charToInt[1];
    printf("%d | %d\n",asciiValueXPos,asciiValueYPos);
    if((asciiValueYPos >= 49 && asciiValueYPos <= 56) || (asciiValueYPos >= 65 && asciiValueYPos <= 72) || (asciiValueYPos >= 97 && asciiValueYPos <= 104)){
        if((asciiValueXPos >= 49 && asciiValueXPos <= 56) || (asciiValueXPos >= 65 && asciiValueXPos <= 72) || (asciiValueXPos >= 97 && asciiValueXPos <= 104)){
            if((asciiValueYPos >= 65 && asciiValueYPos <= 72) && (asciiValueXPos >= 65 && asciiValueXPos <= 72)){
                return convertedMovement; //Both are numbers so it is an invalid movement (we use the A1, b2 movements)
            }else if(((asciiValueYPos >= 49 && asciiValueYPos <= 56) || (asciiValueYPos >= 97 && asciiValueYPos <= 104)) && ((asciiValueXPos >= 49 && asciiValueXPos <= 56) || (asciiValueXPos >= 97 && asciiValueXPos <= 104))){
                return convertedMovement; //Both are letters
            }
            //Now for swapped values (A7 or 7A)
            //At this point, it is only possible for them to be swapped so we use the easiest way
            if((asciiValueXPos >= 49 && asciiValueXPos <= 56)){
                convertedMovement[0] = convertXOrYToInt(charToInt[1]);
                convertedMovement[1] = convertXOrYToInt(charToInt[0]);
            }else{
                convertedMovement[0] = convertXOrYToInt(charToInt[0]);
                convertedMovement[1] = convertXOrYToInt(charToInt[1]);
            }
        }else{
            return convertedMovement;
        }
    }else{
        return convertedMovement;
    }
    return convertedMovement;
}

int isValidPosition(char *chosenPosition){

}

//Aux function implementation

int convertXOrYToInt(char xOrY){
    switch(xOrY){
        case '1':
        case 'a':
        case 'A':
            return 0;
        case '2':
        case 'b':
        case 'B':
            return 1;
        case '3':
        case 'c':
        case 'C':
            return 2;
        case '4':
        case 'd':
        case 'D':
            return 3;
        case '5':
        case 'e':
        case 'E':
            return 4;
        case '6':
        case 'f':
        case 'F':
            return 5;
        case '7':
        case 'G':
        case 'g':
            return 6;
        case '8':
        case 'h':
        case 'H':
            return 7;
        default:
            return 9;
    }
}