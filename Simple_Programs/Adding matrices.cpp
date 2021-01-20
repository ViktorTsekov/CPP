#include<iostream>
using namespace std;

int screen[10][10];
int image[3][3] = { {1, 0, 0} , 
			        {1, 1, 0} , 
			        {0, 1, 0} };

void initializeMatrices() {
	int i,j;
	
	for(i = 0; i < 10; i++) {
		
		for(j = 0; j < 10; j++) {
			screen[i][j] = 0;
		}
		
	}
	
}

void addTheTwoMatrices(int startingRow, int startingCol) {
	int i, j;
	int imageCurrentRow = 0;
	int imageCurrentCol = 0;

	for(i = startingRow; i < startingRow + 3; i++) {
		
		for(j = startingCol; j < startingCol + 3; j++) {
			screen[i][j] = screen[i][j] + image[imageCurrentRow][imageCurrentCol];
			imageCurrentCol++;
			
			if(imageCurrentCol == 3) {
				imageCurrentCol = 0;
				imageCurrentRow++;
			}
			
			if(imageCurrentRow == 3) {
				i = 10;
			}

		}
		
	}
	
}

void printScreen() {
	
	for(int i = 0; i < 10; i++) {
		
		for(int j = 0; j < 10; j++) {
			cout<< screen[i][j];
		}		
		cout<< endl;
	}
	
}

void printImage() {
	
	for(int i = 0; i < 3; i++) {
		
		for(int j = 0; j < 3; j++) {
			cout<< image[i][j];
		}		
		cout<< endl;
	}
	
}

int main() {
	initializeMatrices();
	cout<<"Starting row is 5 and starting collumn is 5"<<endl<<endl;
	cout<<"Image: "<<endl;
	printImage();
	cout<<endl<<"Screen: "<<endl;
	printScreen();
	addTheTwoMatrices(5, 5);
	cout<<endl<<"Rendered image on screen: "<<endl;
	printScreen();
}
