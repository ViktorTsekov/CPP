#include <iostream>

#include "Interface_attributes.h"
#include "Check_for_tetris.h"
#include "Stats.h"

int value;

void showScore(Stats stats) {
	std::cout<<"Score: "<< stats.score<< "\n";
}

void showSpeed(Stats stats) {
	std::cout<<"Render time: "<< stats.speed<< "\n";
}

Stats increaseScore(Stats stats) {
	stats.score += value;
	
	if(stats.score >= 6000) {
		stats.speed = 400;
	} else if(stats.score >= 5000) {
		stats.speed = 500;
	} else if(stats.score >= 4000) {
		stats.speed = 600;
	} else if(stats.score >= 3000) {
		stats.speed = 700;
	} else if(stats.score >= 2000) {
		stats.speed = 800;
	} else if(stats.score >= 1000) {
		stats.speed = 900;
	}
	
	value = 0;
	return stats;
}

char** checkForTetris(char** screen) {
	int flag = 0;
	char** newScreen = screen;

	for(int i = 11; i >= 0; i--) {
		for(int j = 1; j <= 10; j++) {
			if(screen[i][j] == filler) {
				flag = 1;
			}
		}
		
		if(flag == 0) {
			for(int k = i; k >= 0; k--){
				for(int j = 1; j <= 10; j++) {
					int index = (k - 1 < 0) ? k = 0 : k - 1;
					newScreen[k][j] = screen[index][j];
				}
			}
			
			//Here we remove the top line
			for(int j = 1; j <= 10; j++) {
				newScreen[0][j] = filler;
			}	
			
			i++;
			value += 200;
		} else {
			flag = 0;
		}
	}

	return newScreen;
}
