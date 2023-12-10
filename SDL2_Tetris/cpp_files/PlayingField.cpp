// Standard C++ libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

// Third-party libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// Header files
#include "../headers/PlayingField.hpp"

using namespace std;

bool gameOver = false;
int score = 0;

int** field = new int* [FIELD_HEIGHT];

SDL_Texture* fieldTexture = NULL;
SDL_Texture* gameOverTexture = NULL;
SDL_Texture* blueBlockTexture = NULL;
SDL_Texture* orangeBlockTexture = NULL;
SDL_Texture* yellowBlockTexture = NULL;
SDL_Texture* redBlockTexture = NULL;
SDL_Texture* purpleBlockTexture = NULL;
SDL_Texture* greenBlockTexture = NULL;
SDL_Texture* cyanBlockTexture = NULL;

int initResources(SDL_Renderer* renderer) {
  SDL_Surface* fieldSurface = IMG_Load("res/GFX/field.png");
  SDL_Surface* gameOverSurface = IMG_Load("res/GFX/game_over_screen.png");
  SDL_Surface* blueBlockSurface = IMG_Load("res/GFX/blocks/blue_block.png");
  SDL_Surface* orangeBlockSurface = IMG_Load("res/GFX/blocks/orange_block.png");
  SDL_Surface* yellowBlockSurface = IMG_Load("res/GFX/blocks/yellow_block.png");
  SDL_Surface* redBlockSurface = IMG_Load("res/GFX/blocks/red_block.png");
  SDL_Surface* purpleBlockSurface = IMG_Load("res/GFX/blocks/purple_block.png");
  SDL_Surface* greenBlockSurface = IMG_Load("res/GFX/blocks/green_block.png");
  SDL_Surface* cyanBlockSurface = IMG_Load("res/GFX/blocks/cyan_block.png");

  fieldTexture = SDL_CreateTextureFromSurface(renderer, fieldSurface);
  gameOverTexture = SDL_CreateTextureFromSurface(renderer, gameOverSurface);
  blueBlockTexture = SDL_CreateTextureFromSurface(renderer, blueBlockSurface);
  orangeBlockTexture = SDL_CreateTextureFromSurface(renderer, orangeBlockSurface);
  yellowBlockTexture = SDL_CreateTextureFromSurface(renderer, yellowBlockSurface);
  redBlockTexture = SDL_CreateTextureFromSurface(renderer, redBlockSurface);
  purpleBlockTexture = SDL_CreateTextureFromSurface(renderer, purpleBlockSurface);
  greenBlockTexture = SDL_CreateTextureFromSurface(renderer, greenBlockSurface);
  cyanBlockTexture = SDL_CreateTextureFromSurface(renderer, cyanBlockSurface);

  SDL_FreeSurface(fieldSurface);
  SDL_FreeSurface(gameOverSurface);
  SDL_FreeSurface(blueBlockSurface);
  SDL_FreeSurface(orangeBlockSurface);
  SDL_FreeSurface(yellowBlockSurface);
  SDL_FreeSurface(redBlockSurface);
  SDL_FreeSurface(purpleBlockSurface);
  SDL_FreeSurface(greenBlockSurface);
  SDL_FreeSurface(cyanBlockSurface);

  return 0;
}

void initField() {
  for(int i = 0; i < FIELD_HEIGHT; i++) {
    field[i] = new int[FIELD_WIDTH];
  }

  for(int i = 0; i < FIELD_HEIGHT; i++) {
    for(int j = 0; j < FIELD_WIDTH; j++) {
      field[i][j] = EMPTY_SPACE;
    }
  }
}

void printField() {
  for(int i = 0; i < FIELD_HEIGHT; i++) {
    for(int j = 0; j < FIELD_WIDTH; j++) {
      std::cout << field[i][j];
    }
    std::cout << std::endl;
  }
}

void playTheme() {
  Mix_Music *music;

  Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);
  music = Mix_LoadMUS("res/SFX/tetris_theme.mp3");
  Mix_VolumeMusic(80);
  Mix_PlayMusic(music, -1);
}

int printInstructionsGUI() {
  SDL_Window* window = SDL_CreateWindow("Instructions", 0, 0, 350, 250, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Surface* surface = IMG_Load("res/GFX/instructions.png");
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  return 0;
}

int printScoreGUI(SDL_Renderer* renderer, SDL_Rect* rect) {
  char scoreText[20];

  snprintf(scoreText, sizeof(scoreText), "Score: %d", score);

  TTF_Font* font = TTF_OpenFont("res/Fonts/font.ttf", 18);
  SDL_Color fontColor = { 255, 255, 255 };
  SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText, fontColor); 	
  SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

  SDL_RenderCopy(renderer, scoreTexture, NULL, rect);

  return 0;
}

int printFieldGUI(SDL_Renderer* renderer) {
  SDL_Rect fieldPosRect;
  SDL_Rect gameOverPosRect;
  SDL_Rect scorePosRect;

  fieldPosRect.w = BLOCK_WIDTH_PX;
  fieldPosRect.h = BLOCK_HEIGHT_PX;

  gameOverPosRect.x = 50;
  gameOverPosRect.y = 150;
  gameOverPosRect.h = 200;
  gameOverPosRect.w = 200;

  scorePosRect.x = 5;
  scorePosRect.y = 0;
  scorePosRect.w = 80;
  scorePosRect.h = 30;

  SDL_RenderCopy(renderer, fieldTexture, NULL, NULL);

  for(int i = 0; i < FIELD_HEIGHT; i++) {
    for(int j = 0; j < FIELD_WIDTH; j++) {
      int block = field[i][j];

      fieldPosRect.x = j * BLOCK_WIDTH_PX;
      fieldPosRect.y = i * BLOCK_HEIGHT_PX;

      switch(block) {
        case BLUE_BLOCK: SDL_RenderCopy(renderer, blueBlockTexture, NULL, &fieldPosRect); break;
        case ORANGE_BLOCK: SDL_RenderCopy(renderer, orangeBlockTexture, NULL, &fieldPosRect); break;
        case YELLOW_BLOCK: SDL_RenderCopy(renderer, yellowBlockTexture, NULL, &fieldPosRect); break;
        case RED_BLOCK: SDL_RenderCopy(renderer, redBlockTexture, NULL, &fieldPosRect); break;
        case PURPLE_BLOCK: SDL_RenderCopy(renderer, purpleBlockTexture, NULL, &fieldPosRect); break;
        case GREEN_BLOCK: SDL_RenderCopy(renderer, greenBlockTexture, NULL, &fieldPosRect); break;
        case CYAN_BLOCK: SDL_RenderCopy(renderer, cyanBlockTexture, NULL, &fieldPosRect); break;
      }
    }
  }

  if(gameOver) {
    SDL_RenderCopy(renderer, gameOverTexture, NULL, &gameOverPosRect);
  }
  
  printScoreGUI(renderer, &scorePosRect);
  
  SDL_RenderPresent(renderer);

  return 0;
}

void projectFigureOntoScreen(int** figure, int figureX, int figureY, int figureSize) {
  for(int i = 0; i < figureSize; i++) {
    for(int j = 0; j < figureSize; j++) {
      if(figureX + i < FIELD_HEIGHT && figureY + j < FIELD_WIDTH && figureY + j >= 0) {
        if(figure[i][j] != EMPTY_SPACE) {
          field[figureX + i][figureY + j] = figure[i][j];
        }
      }
    }
  }
}

void deleteOldFigure(int** figure, int figureX, int figureY, int figureSize) {
  for(int i = 0; i < figureSize; i++) {
    for(int j = 0; j < figureSize; j++) {
      if(figureX + i < FIELD_HEIGHT && figureY + j < FIELD_WIDTH && figureY + j >= 0) {
        if(figure[i][j] != EMPTY_SPACE) {
          field[figureX + i][figureY + j] = EMPTY_SPACE;
        }
      }
    }
  }
}

vector<vector<int>> visitedNodes;

bool checkForGameOver(int x, int y) {
  if(x == FIELD_HEIGHT - 1) {
    gameOver = true;
    return true;
  }

  int flag = 0;

  for(int i = 0; i < visitedNodes.size(); i++) {
    int visitedX = visitedNodes[i][0];
    int visitedY = visitedNodes[i][1];

    if(x == visitedX && y == visitedY) {
      flag = 1;
    }
  }

  if(flag == 1) {
    return false;
  } else {
    visitedNodes.push_back({x, y});
  }

  if(x + 1 < FIELD_HEIGHT) {
    if(field[x + 1][y] != EMPTY_SPACE) {
      checkForGameOver(x + 1, y);
    }
  }

  if(y + 1 < FIELD_WIDTH) {
    if(field[x][y + 1] != EMPTY_SPACE) {
      checkForGameOver(x, y + 1);
    }
  }

  if(y - 1 >= 0) {
    if(field[x][y - 1] != EMPTY_SPACE) {
      checkForGameOver(x, y - 1);
    }
  }

  return false;
}

void resetVisitedNodes() {
  visitedNodes.clear();
}

bool getGameOver() {
  return gameOver;
}

int getScore() {
  return score;
}

int** getField() {
  return field;
}

void checkForTetris() {
  int** newField = field;
  int rowsCleared = 0;

  for(int i = 0; i < FIELD_HEIGHT; i++) {
    bool tetrisFound = true;
    int lastRow = 0;

    for(int j = 0; j < FIELD_WIDTH; j++) {
      if(field[i][j] == EMPTY_SPACE) {
			  tetrisFound = false;	
		  }
    }

    if(tetrisFound) {
      lastRow = i;
      rowsCleared++;

      for(int j = 0; j < FIELD_WIDTH; j++) {
			  newField[lastRow][j] = EMPTY_SPACE;
      }

      for(int i = lastRow; i > 0; i--) {
        for(int j = 0; j < FIELD_WIDTH; j++) {
          newField[i][j] = field[i - 1][j];
        }
      }
    }
  }

  switch(rowsCleared) {
    case 1: score += 40; break;
    case 2: score += 100; break;
    case 3: score += 300; break;
    case 4: score += 1200; break;
  }

  field = newField;
}
