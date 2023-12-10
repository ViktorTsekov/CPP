// Standard C++ libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

// Header files
#include "../headers/PlayingField.hpp"
#include "../headers/PlayingFigure.hpp"

using namespace std;

const int SELECTION_FIGURES[NUMBER_SELECTION_FIGURES][3][3] = {
  // J Block
  { 
    {0, 1, 0}, 
    {0, 1, 0}, 
    {1, 1, 0}
  },
  // L Block
  { 
    {2, 0, 0}, 
    {2, 0, 0}, 
    {2, 2, 0}
  },
  // O Block
  { 
    {3, 3, 0}, 
    {3, 3, 0}, 
    {0, 0, 0}
  },
  // Z Block
  { 
    {4, 4, 0}, 
    {0, 4, 4}, 
    {0, 0, 0}
  },
  // T Block
  { 
    {0, 5, 0}, 
    {5, 5, 5}, 
    {0, 0, 0}
  },
  // S Block
  { 
    {0, 6, 6}, 
    {6, 6, 0}, 
    {0, 0, 0}
  }
};

const int SELECTION_I_BLOCK[4][4] = { 
  {0, 7, 0, 0}, 
  {0, 7, 0, 0}, 
  {0, 7, 0, 0}, 
  {0, 7, 0, 0} 
};

int** currentFigure;
int figureSize;
int figureIndex;

vector<vector<int>> downExtremeBlocks;
vector<vector<int>> leftExtremeBlocks;
vector<vector<int>> rightExtremeBlocks;

int Xpos = FIGURE_STARTING_X;
int Ypos = FIGURE_STARTING_Y;

int** getFigure() {
  return currentFigure;
}

int getFigureIndex() {
  return figureIndex;
}

int getFigureX() {
  return Xpos;
}

int getFigureY() {
  return Ypos;
}

int getFigureSize() {
  return figureSize;
}

void setFigureMemory() {
  currentFigure = new int* [figureSize];

  for(int i = 0; i < figureSize; i++) {
    currentFigure[i] = new int[figureSize];
  }
}

vector<int> pieceHistory;
static int iterationsWithoutIBlock = 0;

void pickRandomFigure() {
  int pickedFigure = getRandomNumberInRange(NUMBER_SELECTION_FIGURES) - 1;
  
  if(pieceHistory.size() >= 2) {
    if(pieceHistory[pieceHistory.size() - 1] == pickedFigure && pieceHistory[pieceHistory.size() - 2] == pickedFigure) {
      pickedFigure +=  1;

      if(pickedFigure >= NUMBER_SELECTION_FIGURES) {
        pickedFigure = J_BLOCK;
      }
    }
  }

  if(iterationsWithoutIBlock == 7) {
    pickedFigure = I_BLOCK;
  }

  if(pickedFigure == I_BLOCK) {
    iterationsWithoutIBlock = 0;
    figureSize = 4;

    setFigureMemory();

    for(int i = 0; i < figureSize; i++) {
      for(int j = 0; j < figureSize; j++) {
        currentFigure[i][j] = SELECTION_I_BLOCK[i][j];
      }
    }
  } else {
    iterationsWithoutIBlock++;
    figureSize = 3;

    setFigureMemory();

    for(int i = 0; i < figureSize; i++) {
      for(int j = 0; j < figureSize; j++) {
        currentFigure[i][j] = SELECTION_FIGURES[pickedFigure][i][j];
      }
    }
  }

  figureIndex = pickedFigure;
  pieceHistory.push_back(pickedFigure);
}

int getRandomNumberInRange(int range) {
  srand((int) time(0));

  int randomSeed[100];

  for(int i = 0; i < 100; i++) {
    int r = (rand() % range) + 1;
    
    randomSeed[i] = r;
  }

  int randIndex = (rand() % 100) + 1;

  return randomSeed[randIndex - 1];
}

void decreaseFigure() {
  Xpos++;
}

void moveFigureLeft() {
  Ypos--;
}

void moveFigureRight() {
  Ypos++;
}

void rotateFigure(int** field) {
  int** rotatedFigure = new int* [figureSize];
  int x = 0;
  int y = 0;

  // Set memory
  for(int i = 0; i < figureSize; i++) {
    rotatedFigure[i] = new int[figureSize];
  }

  for(int j = 0; j < figureSize; j++) {
    y = 0;

    for(int i = figureSize - 1; i >= 0; i--) {
      rotatedFigure[x][y] = currentFigure[i][j];
      y++;
    }

    x++;
  }

  bool canBeRotated = true;
  int** oldFigure = currentFigure;

  currentFigure = rotatedFigure;
  calculateExtremeBlocks();
  
  // Check if a piece can be rotated
  for(int i = 0; i < figureSize; i++) {
    for(int j = 0; j < figureSize; j++) {
      if(rotatedFigure[i][j] != EMPTY_SPACE) {
        if(field[Xpos + i][Ypos + j] != EMPTY_SPACE) {
          canBeRotated = false;
        }
      }
    }
  }

  if(!canBeRotated) {
    currentFigure = oldFigure;
    calculateExtremeBlocks();
  }
}

void calculateOffsets() {
  int maxY = rightExtremeBlocks[0][1];

  for(int i = 1; i < rightExtremeBlocks.size(); i++) {
    int y = rightExtremeBlocks[i][1];

    if(y > maxY) {
      maxY = y;
    }
  }

  if(Ypos + maxY > FIELD_WIDTH - 1) {
    Ypos -= ((Ypos + maxY) - (FIELD_WIDTH - 1));
  }

  int maxX = downExtremeBlocks[0][0];

  for(int i = 1; i < downExtremeBlocks.size(); i++) {
    int x = downExtremeBlocks[i][0];

    if(x > maxX) {
      maxX = x;
    }
  }

  if(Xpos + maxX > FIELD_HEIGHT - 1) {
    Xpos -= ((Xpos + maxX) - (FIELD_HEIGHT - 1));
  }

  int minY = leftExtremeBlocks[0][1];

  for(int i = 1; i < leftExtremeBlocks.size(); i++) {
    int y = leftExtremeBlocks[i][1];

    if(y < minY) {
      minY = y;
    }
  }

  if(Ypos - minY < 0) {
    Ypos += abs(Ypos - minY);
  }
}

void calculateExtremeBlocks() {
  downExtremeBlocks.clear();
  leftExtremeBlocks.clear();
  rightExtremeBlocks.clear();

  // Calculate extreme blocks that are down
  for(int j = 0; j < figureSize; j++) {
    bool blockHasBeenFound = false;

    for(int i = figureSize - 1; i >= 0; i--) {
      if(currentFigure[i][j] != EMPTY_SPACE && !blockHasBeenFound) {
        downExtremeBlocks.push_back({i, j});
        blockHasBeenFound = true;
      }
    }
  }

  // Calculate extreme blocks that are on the left
  for(int i = 0; i < figureSize; i++) {
    bool blockHasBeenFound = false;

    for(int j = 0; j < figureSize; j++) {
      if(currentFigure[i][j] != EMPTY_SPACE && !blockHasBeenFound) {
        leftExtremeBlocks.push_back({i, j});
        blockHasBeenFound = true;
      }
    }
  }

  // Calculate extreme blocks that are on the right
  for(int i = 0; i < figureSize; i++) {
    bool blockHasBeenFound = false;

    for(int j = figureSize - 1; j >= 0; j--) {
      if(currentFigure[i][j] != EMPTY_SPACE && !blockHasBeenFound) {
        rightExtremeBlocks.push_back({i, j});
        blockHasBeenFound = true;
      }
    }
  }

  calculateOffsets();
}

bool thereIsAnObstacleDown(int** field) {
  bool thereIsAnObstacle = false;
  int maxX = downExtremeBlocks[0][0];

  for(int i = 1; i < downExtremeBlocks.size(); i++) {
    int x = downExtremeBlocks[i][0];

    if(x > maxX) {
      maxX = x;
    }
  }

  if(Xpos + maxX + 1 >= FIELD_HEIGHT) {
    return true;
  }

  for(int i = 0; i < downExtremeBlocks.size(); i++) {
    int x = downExtremeBlocks[i][0];
    int y = downExtremeBlocks[i][1];

    if(field[Xpos + x + 1][Ypos + y] != EMPTY_SPACE) {
      thereIsAnObstacle = true;
    }
  }

  return thereIsAnObstacle;
}

bool thereIsAnObstacleLeft(int** field) {
  bool thereIsAnObstacle = false;
  int minY = leftExtremeBlocks[0][1];

  for(int i = 1; i < leftExtremeBlocks.size(); i++) {
    int y = leftExtremeBlocks[i][1];

    if(y < minY) {
      minY = y;
    }
  }

  if(Ypos + minY - 1 < 0) {
    return true;
  }

  for(int i = 0; i < leftExtremeBlocks.size(); i++) {
    int x = leftExtremeBlocks[i][0];
    int y = leftExtremeBlocks[i][1];

    if(field[Xpos + x][Ypos + y - 1] != EMPTY_SPACE) {
      thereIsAnObstacle = true;
    }
  }
  
  return thereIsAnObstacle;
}

bool thereIsAnObstacleRight(int** field) {
  bool thereIsAnObstacle = false;
  int maxY = rightExtremeBlocks[0][1];

  for(int i = 1; i < rightExtremeBlocks.size(); i++) {
    int y = rightExtremeBlocks[i][1];

    if(y > maxY) {
      maxY = y;
    }
  }

  if(Ypos + maxY + 1 >= FIELD_WIDTH) {
    return true;
  }

  for(int i = 0; i < rightExtremeBlocks.size(); i++) {
    int x = rightExtremeBlocks[i][0];
    int y = rightExtremeBlocks[i][1];

    if(field[Xpos + x][Ypos + y + 1] != EMPTY_SPACE) {
      thereIsAnObstacle = true;
    }
  }

  return thereIsAnObstacle;
}

void resetFigurePositions() {
  Xpos = FIGURE_STARTING_X;
  Ypos = FIGURE_STARTING_Y;
}
