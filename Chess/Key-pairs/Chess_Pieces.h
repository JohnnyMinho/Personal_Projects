#ifndef CHESS_PIECES_CONSTANTS_H
#define CHESS_PIECES_CONSTANTS_H

// The following is the ordenation of the representation of the chess pieces in this simple key-symbol mapping
// A to G are for the white pieces, a to g are for the black pieces
const char * const * generateBlackPieces(void);

const char * const * generateWhitePieces(void);

void SimpleKeyPairPrintTest(void);

#endif