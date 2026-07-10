#ifdef GAMELOGIC_H
#define GAMELOGIC_H

bool isValidMovement(int xPos, int yPos,char *movement, char pieceType, int isPosOccupied);
int * convertMovementToPos(char *charToInt);
char convertPiece(); //When a pawn hit the last spot in the opposing side we ask the user if he wants to convert the pawn and to which piece



#endif