#include "Move_piece.h"
#include "Interface_attributes.h"

Piece movePieceDown(Piece piece) {
	piece.X += 1;
	return piece;
}

Piece movePieceLeft(Piece piece) {
	piece.Y -= 1;
	return piece;
}

Piece movePieceRight(Piece piece) {
	piece.Y += 1;
	return piece;
}

Piece rotatePiece(Piece piece) {	
	int row = 3;
	int col = 0;
	char** newPiece;
	
	newPiece = new char*[4];
	
	for(int i = 0; i < 4; i++) {			
		newPiece[i] = new char[4];
	}
			
	for(int i = 0; i < 4; i++) {
			
		for(int j = 0; j < 4; j++) {
			newPiece[i][j] = *(*(piece.piece + row) + col);
			row--;
		}
				
		row = 3;
		col++;
	}
	
	piece.piece = newPiece;		
	return piece;	
}

char** deleteOldPiece(char** screen, Piece piece) {
	
	for(int i = 0; i < 4; i++) {
		int X = piece.X + piece.Xcoordinates[i];
		int Y = piece.Y + piece.Ycoordinates[i];
		screen[X][Y] = filler;
	}
    
    return screen;	
}
