#include "Project_piece_on_screen.h"
#include "Interface_attributes.h"

char** project_Piece(char** screen, Piece piece) {
	int X;
	int Y;
	
	for(int i = 0; i < 4; i++) {
		X = piece.X + piece.Xcoordinates[i];
		Y = piece.Y + piece.Ycoordinates[i];
		screen[X][Y] = block;
	}

	return screen;
}
