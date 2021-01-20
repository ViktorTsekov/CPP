#include <iostream>

#include "Engine.h"
#include "Point.h"
#include "AI.h"

using namespace std;

int mode;

void chooseGameMode() {
	
	cout << "Press 1 to use the controls and press 2 to play the AI: ";
	
	do {
		cin >> mode;
		
		if(mode != 1 && mode != 2) {
			cout << "Press 1 to use the controls and press 2 to play the AI: ";
		}
		
	} while(mode != 1 && mode != 2);
	
}

void printStartScreen() {
	cout << ":'######::'##::: ##::::'###::::'##:::'##:'########:" << endl;
	cout << "'##... ##: ###:: ##:::'## ##::: ##::'##:: ##.....::" << endl;
	cout << " ##:::..:: ####: ##::'##:. ##:: ##:'##::: ##:::::::" << endl;
	cout << ". ######:: ## ## ##:'##:::. ##: #####:::: ######:::" << endl;
	cout << ":..... ##: ##. ####: #########: ##. ##::: ##...::::" << endl;
	cout << "'##::: ##: ##:. ###: ##.... ##: ##:. ##:: ##:::::::" << endl;
	cout << ". ######:: ##::. ##: ##:::: ##: ##::. ##: ########:" << endl;
	cout << endl;
	chooseGameMode();
}

int main() {
	printStartScreen();
	Start(30, mode);
	Update();
}
