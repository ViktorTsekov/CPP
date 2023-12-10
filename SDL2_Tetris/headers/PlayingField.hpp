#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FIELD_HEIGHT 20
#define FIELD_WIDTH 10

#define FIELD_HEIGHT_PX 600
#define FIELD_WIDTH_PX 300

#define BLOCK_HEIGHT_PX 30
#define BLOCK_WIDTH_PX 30

enum PLAYING_BLOCKS { EMPTY_SPACE, BLUE_BLOCK, ORANGE_BLOCK, YELLOW_BLOCK, RED_BLOCK, PURPLE_BLOCK, GREEN_BLOCK, CYAN_BLOCK };

int** getField();
void initField();
void printField();
void projectFigureOntoScreen(int** figure, int figureX, int figureY, int figureSize);
void deleteOldFigure(int** figure, int figureX, int figureY, int figureSize);
bool checkForGameOver(int x, int y);
bool getGameOver();
int getScore();
void checkForTetris();
void resetVisitedNodes();
int initResources(SDL_Renderer* renderer);
int printFieldGUI(SDL_Renderer* renderer);
int printScoreGUI(SDL_Renderer* renderer, SDL_Rect* rect);
int printInstructionsGUI();
void playTheme();
