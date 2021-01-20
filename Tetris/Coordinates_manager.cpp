#include "Coordinates_manager.h"
#include "Interface_attributes.h"
#include "iostream"

int findMinCol(Piece piece) {
	int minCol = 10;
	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(piece.piece[i][j] == block && minCol > j) {
				minCol = j;
			}
		}
	}
	
	return minCol;
}

int findMaxCol(Piece piece) {
	int maxCol = -1;
	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(piece.piece[i][j] == block && maxCol < j) {
				maxCol = j;
			}
		}
	}
	
	return maxCol;
}

int* setMem() {
	int* arr = new int[10];
	for(int i = 0; i < 10; i++) {
		arr[i] = -1;
	}
	return arr;
}

int* findCoordinatesOfFloatingBlocks(Piece piece, int flag) {
	int* Xcoordinates = setMem();
	int* Ycoordinates = setMem();
	int index = 0;
	char currentBlock;
	
	for(int i = 0; i < 4; i++) {
		int X = piece.Xcoordinates[i];
		int Y = piece.Ycoordinates[i];
		int newX = X + 1;
		currentBlock = (newX > 3) ? '*' : piece.piece[newX][Y];
		
		if(currentBlock != block) {
			Xcoordinates[index] = piece.Xcoordinates[i];
			Ycoordinates[index] = piece.Ycoordinates[i];
			index++;
		}
	}

	if(flag == 1) {
		return Ycoordinates;
	}
	
	return Xcoordinates;
}

bool pickNextPiece(Piece piece, char** screen) {
	int* Xcoordinates = findCoordinatesOfFloatingBlocks(piece, 0);
	int* Ycoordinates = findCoordinatesOfFloatingBlocks(piece, 1);
	int i = 0;
	
	while(Xcoordinates[i] != -1 && Ycoordinates[i] != -1) {
		int X = piece.X + Xcoordinates[i] + 1;
		int Y = piece.Y + Ycoordinates[i];
		i++;
		
		if(screen[X][Y] == floor || screen[X][Y] == block) {
			return true;
		}
	}

	return false;
}

bool checkIfThereIsSolidLeftOfPiece(Piece piece, char** screen) {
	int minCol = findMinCol(piece);
	
	for(int i = 0; i < 4; i++) {
		if(piece.piece[i][minCol] == block) {
			int X = piece.X + i;
			int Y = piece.Y + minCol - 1;
			
			if(screen[X][Y] == walls || screen[X][Y] == block) {
				return true;
			}
		} 
	}

	return false;
}

bool checkIfThereIsSolidRightOfPiece(Piece piece, char** screen) {
	int maxCol = findMaxCol(piece);
	
	for(int i = 0; i < 4; i++) {
		if(piece.piece[i][maxCol] == block) {
			int X = piece.X + i;
			int Y = piece.Y + maxCol + 1;
			if(screen[X][Y] == walls || screen[X][Y] == block) {
				return true;
			}
		} 
	}

	return false;
}

Piece findCoordinatesOfSegmentsWithBlocks(Piece piece) {
	piece.Xcoordinates = new int[10];
	piece.Ycoordinates = new int[10];
	int index = 0;
	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(piece.piece[i][j] == block) {
				piece.Xcoordinates[index] = i;
				piece.Ycoordinates[index] = j;
				index++;
			}
		}
	}
	
	return piece;
}
