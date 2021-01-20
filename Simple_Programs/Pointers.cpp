#include <iostream>

using namespace std;
int main() {
	int A[20];
	int *B[20];
	int **C[20];
	
	for(int i = 0; i < 20; i++) {
		A[i] = i;
		B[i] = &A[i]; 
		C[i] = &B[i];
	}
	
	cout<< "Non-pointer array: "<< endl;
	for(int i = 0; i < 20; i++) {
		cout<< &A[i]<< "-"<< A[i]<< endl; 
	}
	
	cout<< "\nPointer array: "<< endl;
	for(int i = 0; i < 20; i++) {
		cout<< B[i]<< "-"<< *B[i]<< endl; 
	}
	
	cout<< "\nDouble-pointer array: "<< endl;
	for(int i = 0; i < 20; i++) {
		cout<< C[i]<< "-"<< *C[i]<< "-"<< **C[i]<< endl; 
	}
	
	int *a;
	int b = 50;
	int &c = b;
	
	a = &b;
	cout<< endl<< "Pointer to b: "<< endl<< a<< "-"<< *a<< endl;
	
	a = &c;
	cout<< endl<< "Pointer to c: "<< endl<< a<< "-"<< *a<< endl;
	
	return 0;
}
