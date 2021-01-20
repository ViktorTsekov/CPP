#include <iostream>
#include <windows.h>

#include "Interface_attributes.h"
#include "Check_for_game_over.h" 

static int count;

bool gameOver(char** screen) {
	int flag = 0;

	for(int j = 1; j <= 10; j++) {
		if(screen[0][j] != filler) {
			flag = 1;	
		}
	}
	
	if(flag == 0) {
		setCountToZero();
	} else {
		count++;
	}
	
	if(count == 2) {
		return true;
	}
	
	return false;
}

void showEndScreen() {
	system("CLS");
	std::cout<< "..######......###....##.....##.########.....#######..##.....##.########.########.\n";
	std::cout<< ".##....##....##.##...###...###.##..........##.....##.##.....##.##.......##.....##\n";
	std::cout<< ".##.........##...##..####.####.##..........##.....##.##.....##.##.......##.....##\n";
	std::cout<< ".##...####.##.....##.##.###.##.######......##.....##.##.....##.######...########.\n";
	std::cout<< ".##....##..#########.##.....##.##..........##.....##..##...##..##.......##...##..\n";
	std::cout<< ".##....##..##.....##.##.....##.##..........##.....##...##.##...##.......##....##.\n";
	std::cout<< "..######...##.....##.##.....##.########.....#######.....###....########.##.....##\n\n";
	system("pause");
}

void setCountToZero() {
	count = 0;
}
