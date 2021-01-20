#include <conio.h>
#include <windows.h>

#include "Initialize_playing_field.h"
#include "Render.h"
#include "Pick_playing_piece.h"
#include "Project_piece_on_screen.h"
#include "Move_piece.h"
#include "Interface_attributes.h"
#include "Piece_attributes.h"
#include "Coordinates_manager.h"
#include "Check_for_game_over.h"
#include "Check_for_tetris.h"
#include "Stats.h"

int main() {
	char** field = initialize();
	Stats stats;
	Piece piece;
	
	initializeSeed();
	printStartScreen();
	
	piece = pickPiece();
	piece = findCoordinatesOfSegmentsWithBlocks(piece);
	field = project_Piece(field, piece);
	printMatrix(field);
	showScore(stats);
	showSpeed(stats);
	
	while(!gameOver(field)) {
		Sleep(stats.speed);
		system("CLS");
		
		if (GetAsyncKeyState(rotateKey)) {
			setCountToZero();
			field = deleteOldPiece(field, piece);
			piece = rotatePiece(piece);
			piece = findCoordinatesOfSegmentsWithBlocks(piece);
        } else if (GetAsyncKeyState(leftKey)) {
        	setCountToZero();
        	if(!checkIfThereIsSolidLeftOfPiece(piece, field)) {
        		field = deleteOldPiece(field, piece);
				piece = movePieceLeft(piece);
			}
        } else if (GetAsyncKeyState(rightKey)) {
        	setCountToZero();
        	if(!checkIfThereIsSolidRightOfPiece(piece, field)) {
        		field = deleteOldPiece(field, piece);
				piece = movePieceRight(piece);
			}
        } else if(!pickNextPiece(piece, field)) {
			field = deleteOldPiece(field, piece);
        	piece = movePieceDown(piece);
		} else {
			field = checkForTetris(field);
			stats = increaseScore(stats);
			piece = pickPiece();
			piece = findCoordinatesOfSegmentsWithBlocks(piece);
		}
        
		field = project_Piece(field, piece);	
		printMatrix(field);	
		showScore(stats);
		showSpeed(stats);
	}
	
	Sleep(2000);
	showEndScreen();
	return 0;
}
