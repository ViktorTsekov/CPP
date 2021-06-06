#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

#include "Engine.h"
#include "Controls.h"
#include "Point.h"
#include "AI.h";

using namespace std;

int** board;

int row;
int col;

int score;
int gameMode;

int emptySpace;
int snake;
int food;
int wall;

bool gameOver;
bool foodIsEaten;

string direction;

vector<Point> snakeBody;
vector<string> path;

PathFinder pathFinder;

void initBoard() {
	
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			board[i][j] = emptySpace;
		}
	}
	
	for (int i = 0; i < row; i++) {
		board[i][0] = wall;
		board[i][col - 1] = wall;
	}
		
	for (int j = 0; j < col; j++) {
		board[0][j] = wall;
		board[row - 1][j] = wall;
	}
	
}

void print() {
	
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			int cur = board[i][j];
			
			if(cur == emptySpace) {
				cout << " ";
			} else if(cur == snake) {
				cout << "o";
			} else if(cur == food) {
				cout << "@";
			} else if(cur == wall) {
				cout << "#";
			}
			
		}
		cout << endl;
	}
	
	cout << "Score: " << score << endl;
}

void setMemory() {
	board = new int*[row];
	
	for(int i = 0; i < row; i++) {
		board[i] = new int[col];
	}
}

void freeMemory() {
	for(int i = 0 ; i < row ; i++) {
	    delete[] board[i];
	}

	delete[] board;
	
	snakeBody.clear();
	path.clear();
}

void getInput() {
	
	if (GetAsyncKeyState(UP_ARROW) && direction != "down") {
		direction = "up";
    } else if (GetAsyncKeyState(DOWN_ARROW) && direction != "up") {
		direction = "down";
    } else if (GetAsyncKeyState(LEFT_ARROW) && direction != "right") {
		direction = "left";
    } else if (GetAsyncKeyState(RIGHT_ARROW) && direction != "left") {
		direction = "right";
    } else if(GetAsyncKeyState(SPACE)) {
    	system("pause");
	}
    
}

void projectSnake() {
	
	for(int i = 0; i < snakeBody.size(); i++) {
		Point cur = snakeBody[i];
		board[cur.x][cur.y] = snake;
	}
	
}

void generateFood() {
	int x;
	int y;
	int cur;

	if(foodIsEaten) {
		try {

			do {
				score += 100;
				x = 2 + (rand() % row - 2);
				y = 2 + (rand() % col - 2);
				cur = board[x][y];
			} while(cur != emptySpace);
			
		} catch(const exception& e){
			generateFood();
		}
		
		//Here we find a path to the food
		if(gameMode == 2) {
			path = pathFinder.returnPath(x, y, snakeBody);
		}
		
		board[x][y] = food;
		foodIsEaten = false;
	}
		
}

void checkIfFoodIsEaten(int x, int y) {
	
	if(board[x][y] == food) {
		foodIsEaten = true;
	} else {
		board[snakeBody[0].x][snakeBody[0].y] = emptySpace; 
		snakeBody.erase(snakeBody.begin());
	}
	
}

void checkForGameOver(int x, int y) {
	
	if(board[x][y] == wall || board[x][y] == snake) {
		gameOver = true;
	}
	
}

void move() {
	Point p = Point(snakeBody[snakeBody.size() - 1].x, snakeBody[snakeBody.size() - 1].y);
	
	if(direction == "right") {
		p.y += 1;
		snakeBody.push_back(p);
		checkForGameOver(p.x, p.y);
		checkIfFoodIsEaten(p.x, p.y);
		projectSnake();
	} else if(direction == "left") {
		p.y -= 1;
		snakeBody.push_back(p);
		checkForGameOver(p.x, p.y);
		checkIfFoodIsEaten(p.x, p.y);
		projectSnake();
	} else if(direction == "down") {
		p.x += 1;
		snakeBody.push_back(p);
		checkForGameOver(p.x, p.y);
		checkIfFoodIsEaten(p.x, p.y);
		projectSnake();
	} else if(direction == "up") {
		p.x -= 1;
		snakeBody.push_back(p);
		checkForGameOver(p.x, p.y);
		checkIfFoodIsEaten(p.x, p.y);	
		projectSnake();
	} 
	
}

void Start(int size, int _gameMode) {
	srand((unsigned) time(NULL));
	score = 0;
	row = size / 2;
	col = size;
	emptySpace = 0;
	snake = 1;
	food = 2;
	wall = 3;
	direction = "right";
	snakeBody.push_back(Point(1, 1));
	snakeBody.push_back(Point(1, 2));
	snakeBody.push_back(Point(1, 3));
	gameOver = false;
	foodIsEaten = true;
    gameMode = _gameMode;
    
    setMemory();
    initBoard();
    pathFinder.initGrid(row, col);
}

void Update() {

	if(gameMode == 1) {
		
		while(!gameOver) {
			cout << "USE THE ARROWS TO MOVE, PRESS SPACE TO PAUSE\n";
			
			generateFood();
			move();
			print();
			getInput();
			
			Sleep(50);
			system("cls");
		}
		
	} else {
		
		while(!gameOver) {
			cout << "PRESS ESCAPE TO EXIT\n";
			
			generateFood();
			
			direction = path[0];
			path.erase(path.begin());
	
			move();
			print();
			
			if(GetAsyncKeyState(ESCAPE)) {
				gameOver = true;
			}
			
			Sleep(20);
			system("cls");
		}
		
	}
	
	freeMemory();
	pathFinder.freeMemory();
	cout << "Game Over!\n";
}
