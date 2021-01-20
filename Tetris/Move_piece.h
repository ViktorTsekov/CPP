#include "Piece_attributes.h"

Piece movePieceDown(Piece piece);
Piece movePieceLeft(Piece piece);
Piece movePieceRight(Piece piece);
Piece rotatePiece(Piece piece);
int findLowestRowContainingBlocks(Piece piece);
char** deleteOldPiece(char** screen, Piece piece);
