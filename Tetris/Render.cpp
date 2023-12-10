#include <iostream>
#include "Render.h"

void printMatrix(char** matrix) {
	
    for(int i = 0; i < 13; i++) {
    	
        for(int j = 0; j < 12; j++) {
            std::cout<<*(*(matrix + i) + j);
        
        }        
        std::cout<<'\n';
    }

}
