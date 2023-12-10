#define NUMBER_SELECTION_FIGURES 7
#define FIGURE_STARTING_X 0
#define FIGURE_STARTING_Y 4

enum PLAYING_FIGURES { J_BLOCK, L_BLOCK, O_BLOCK, Z_BLOCK, T_BLOCK, S_BLOCK, I_BLOCK };

int** getFigure();
int getFigureIndex();
int getFigureX();
int getFigureY();
int getFigureSize();
void setFigureMemory();
void pickRandomFigure();
int getRandomNumberInRange(int range);
void decreaseFigure();
void moveFigureLeft();
void moveFigureRight();
void rotateFigure(int** field);
bool thereIsAnObstacleDown(int** field);
bool thereIsAnObstacleLeft(int** field);
bool thereIsAnObstacleRight(int** field);
void resetFigurePositions();
void calculateExtremeBlocks();
void calculateOffsets();
