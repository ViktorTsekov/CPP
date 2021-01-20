#include <iostream>
#include <windows.h>

#include "Initialize_playing_field.h"
#include "Interface_attributes.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

/*
	These are the dimensions of the playing field
	Row: 0-11
	Col: 1-10
*/

void printStartScreen() {
	std::cout<< ".########.########.########.########..####..######.\n";
	std::cout<<	"....##....##..........##....##.....##..##..##....##\n";
	std::cout<<	"....##....##..........##....##.....##..##..##......\n";
	std::cout<<	"....##....######......##....########...##...######.\n";
	std::cout<<	"....##....##..........##....##...##....##........##\n";
	std::cout<<	"....##....##..........##....##....##...##..##....##\n";
	std::cout<<	"....##....########....##....##.....##.####..######.\n\n";
	std::cout<< "Z-rotate piece\n";
	std::cout<< "Left arrow-move piece left\n";
	std::cout<< "Right arrow-move piece right\n\n";
	system("pause");
	system("CLS");
}

char** setMemory() {
	char** matrix;
	
	matrix = new char*[13];
	
	for(int i = 0; i < 13; i++) {
		matrix[i] = new char[12];	
		
		for(int j = 0; j < 12; j++) {
			matrix[i][j] = filler;
		}
		
	}
			
	return matrix;
}

char** initialize() {
	char** matrix = setMemory();
	SetConsoleTextAttribute(hConsole, consoleColor);
	
	for(int i = 0; i < 13; i++) {
		matrix[i][0] = walls;
	}
	
	for(int i = 0; i < 13; i++) {
		matrix[i][11] = walls;
	}
	
	for(int i = 0; i < 12; i++) {
		matrix[12][i] = floor;
	}
			
	return matrix;
}
