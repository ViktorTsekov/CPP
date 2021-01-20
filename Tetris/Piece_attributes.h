#ifndef PIECE_H_
#define PIECE_H_

struct Piece {
	char** piece;
	int X;
	int Y;
	int* Xcoordinates;
	int* Ycoordinates;
	int lenght = 4;
};

typedef struct Piece Piece;

#endif
