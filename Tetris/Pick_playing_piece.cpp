#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "Pick_playing_piece.h"

using namespace std;

int seed[1000];

void initializeSeed() {
	srand((unsigned)time(NULL));

    for(int i = 0; i < 1000; i++) {
        seed[i] = rand() % 7 + 1;
    }
    
}

char** setMemoryForPiece() {
	char** piece;
	piece = new char*[4];
	
	for(int i = 0; i < 4; i++) {
		piece[i] = new char[4];
		
		for(int j = 0; j < 4; j++) {
			piece[i][j] = '*';
		}
		
	}
	
	return piece;
}

char** setBlockPiece(char** piece) {
	piece[0][0] = '#';
	piece[0][1] = '#';
	piece[1][0] = '#';
	piece[1][1] = '#';
	return piece;
}

char** setLinePiece(char** piece) {
	piece[0][0] = '#';
	piece[0][1] = '#';
	piece[0][2] = '#';
	piece[0][3] = '#';
	return piece;
}

char** setLPiece(char** piece) {
	piece[0][0] = '#';
	piece[1][0] = '#';
	piece[2][0] = '#';
	piece[2][1] = '#';
	return piece;
}

char** setReversedLPiece(char** piece) {
	piece[0][1] = '#';
	piece[1][1] = '#';
	piece[2][1] = '#';
	piece[2][0] = '#';
	return piece;
}

char** setTPiece(char** piece) {
	piece[0][0] = '#';
	piece[0][1] = '#';
	piece[0][2] = '#';
	piece[1][1] = '#';
	return piece;
}

char** setSquiggly(char** piece) {
	piece[0][0] = '#';
	piece[1][0] = '#';
	piece[1][1] = '#';
	piece[2][1] = '#';
	return piece;
}

char** setReversedSquiggly(char** piece) {
	piece[0][1] = '#';
	piece[1][1] = '#';
	piece[1][0] = '#';
	piece[2][0] = '#';
	return piece;
}

Piece pickPiece() {
	Piece piece;
	piece.piece = setMemoryForPiece();
	int i = rand() % 1000 + 0;
	int randomNumber = seed[i];

	switch(randomNumber) {
		case 1: piece.piece = setBlockPiece(piece.piece); break;
		case 2: piece.piece = setLinePiece(piece.piece); break;
		case 3: piece.piece = setLPiece(piece.piece); break;
		case 4: piece.piece = setReversedLPiece(piece.piece); break;
		case 5: piece.piece = setTPiece(piece.piece); break;
		case 6: piece.piece = setSquiggly(piece.piece); break;
		case 7: piece.piece = setReversedSquiggly(piece.piece); break;
	}
	
	//These are our starting coordinates
	piece.X = 0;
	piece.Y = 4;
	return piece;
}
