// Standard C++ libraries
#include <iostream>

// Third-party libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Header files
#include "../headers/PlayingField.hpp"
#include "../headers/PlayingFigure.hpp"
#include "../headers/Engine.hpp"

SDL_Window* window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, FIELD_WIDTH_PX, FIELD_HEIGHT_PX, SDL_WINDOW_INPUT_FOCUS);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

void init() {
  initField();
  initResources(renderer);
  playTheme();
}

void run() {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  pickRandomFigure();
  calculateExtremeBlocks();

  bool buttonPressed = false;
  bool rapidDecrease = false;
  bool quit = false;
  int** figure = getFigure();
  int updateRate = 1000;

  projectFigureOntoScreen(figure, getFigureX(), getFigureY(), getFigureSize());
  printFieldGUI(renderer);
  SDL_Delay(updateRate);
  SDL_RenderClear(renderer);

  while(!quit) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    SDL_Event Event;

    while (SDL_PollEvent(&Event)) {
      if (Event.type == SDL_KEYDOWN) {
        // Left arrow
        if (Event.key.keysym.sym == SDLK_LEFT) {
          if(!thereIsAnObstacleLeft(getField())) {
            deleteOldFigure(getFigure(), getFigureX(), getFigureY(), getFigureSize());
            moveFigureLeft();
            projectFigureOntoScreen(figure, getFigureX(), getFigureY(), getFigureSize());
            buttonPressed = true;
          }
        } 
        // Right arrow
        else if(Event.key.keysym.sym == SDLK_RIGHT) {
          if(!thereIsAnObstacleRight(getField())) {
            deleteOldFigure(getFigure(), getFigureX(), getFigureY(), getFigureSize());
            moveFigureRight();
            projectFigureOntoScreen(figure, getFigureX(), getFigureY(), getFigureSize());
            buttonPressed = true;
          }
        } 
        // Z key
        else if(Event.key.keysym.sym == SDLK_z) {
          // O_BLOCK cannot be rotated
          if(getFigureIndex() != O_BLOCK) {
            deleteOldFigure(getFigure(), getFigureX(), getFigureY(), getFigureSize());
            rotateFigure(getField());
            figure = getFigure();
            projectFigureOntoScreen(figure, getFigureX(), getFigureY(), getFigureSize());
          }
        } 
        // Escape key
        else if(Event.key.keysym.sym == SDLK_ESCAPE) {
          quit = true;
        }
      }
    }

    // Down arrow
    if(currentKeyStates[SDL_SCANCODE_DOWN]) {
      updateRate = 200;
      rapidDecrease = true;
    } else {
      updateRate = 1000;
      rapidDecrease = false;
    }

    if(buttonPressed) {
      buttonPressed = false;
    } else {
      if(!rapidDecrease) {
        updateRate = 1000;
      }
      
      if(!thereIsAnObstacleDown(getField())) {
        deleteOldFigure(getFigure(), getFigureX(), getFigureY(), getFigureSize());
        decreaseFigure();
        projectFigureOntoScreen(figure, getFigureX(), getFigureY(), getFigureSize());
      } else {
        checkForTetris();
        pickRandomFigure();
        resetFigurePositions();
        calculateExtremeBlocks();
        figure = getFigure();
        projectFigureOntoScreen(figure, getFigureX(), getFigureY(), getFigureSize());
      }
    }

    int** field = getField();
    
    // Check for game over
    for(int j = 0; j < FIELD_WIDTH; j++) {
      if(field[0][j] != EMPTY_SPACE) {
        resetVisitedNodes();
        checkForGameOver(0, j);

        if(getGameOver()) {
          updateRate = 3000;
        }
      }
    }

    printFieldGUI(renderer);
    SDL_Delay(updateRate);

    if(!getGameOver()) {
      SDL_RenderClear(renderer);
    } else {
      quit = true;
    }
  }

  if(getGameOver()) {
    system("CLS");
    std::cout << "GAME OVER!" << std::endl;
    std::cout << "FINAL SCORE: " << getScore() << std::endl;
  }
}
