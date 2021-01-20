#include<iostream>
using namespace std;

int rotationValue = 0;

int** createMatrix() {
	int** matrix = 0;
	int i,j;
	int br = -1;
	
	matrix = new int*[10];
	
	for(i = 0; i < 10; i++) {
			
		br = -1;
		matrix[i] = new int[10];
		
		for(j = 0; j < 10; j++) {
			br++;
			matrix[i][j] = br;
		}
		
	}
	
	return matrix;
}

template<typename T>
void printMatrix(T matrix) {
	
    for(int i = 0; i < 10; i++) {
    	
        for(int j = 0; j < 10; j++) {
            cout<<*(*(matrix + i) + j);
        }        
        cout<<endl;
    }

}

int commandPanel() {
	int inp;
	
	cout<<endl;
	cout<<"1-rotate"<<endl;
	cout<<"0-abort"<<endl;
	cout<<"Enter command: ";
	cin>>inp;
	
	return inp;
}

template<typename T>
int** copyMatrix(T matrixToCopy) {
	int** matrixCopy;
	int i,j;
	
	matrixCopy = new int*[10];
	
	for(i = 0; i < 10; i++) {			
		matrixCopy[i] = new int[10];
	}
	
	for(i = 0; i < 10; i++) {
			
		for(j = 0; j < 10; j++) {
			matrixCopy[i][j] = *(*(matrixToCopy + i) + j);
		}
	
	}
	
	return matrixCopy;
}

template<typename T>
int** overwriteMatrix(T matrixCopy) {
	int i, j, k ,l;
	int** newMatrix;
	
	k = 9;
	l = 0;
	
	newMatrix = new int*[10];
	
	for(i = 0; i < 10; i++) {			
		newMatrix[i] = new int[10];
	}
			
	for(i = 0; i < 10; i++) {
			
		for(j = 0; j < 10; j++) {
			newMatrix[i][j] = *(*(matrixCopy + k) + l);
			k--;
		}
				
		k = 9;
		l++;
	}
			
	return newMatrix;
}

void changeRotationValue() {
	rotationValue += 90;
	
	if(rotationValue == 360) {
		cout<<endl;
		cout<<"Matrix is rotated on "<<rotationValue<<" degrees"<<endl;
		rotationValue = 0;
	} else {
		cout<<endl;
		cout<<"Matrix is rotated on "<<rotationValue<<" degrees"<<endl;
	}
	
}

int main() {
	int** myMatrix;
	int** matrixCopy;
	int input;
	bool abort = false;
	
	cout<<"Initial matrix: "<<endl<<endl;
	myMatrix = createMatrix();
	printMatrix(myMatrix);
	
	while(!abort) {
		
		input = commandPanel();
		
		switch(input) {
			case 0: abort = true; break;
			case 1: matrixCopy = copyMatrix(myMatrix);
					myMatrix = overwriteMatrix(matrixCopy);
					cout<<endl;
					printMatrix(myMatrix); 
					changeRotationValue(); break;
		}
		
	}
	
}
