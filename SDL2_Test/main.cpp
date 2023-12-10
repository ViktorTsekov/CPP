#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);

  // Create a window
  SDL_Window* window = SDL_CreateWindow("SDL2 Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 300, 300, SDL_WINDOW_SHOWN);

  // Create a renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Load an image
  SDL_Surface* image = IMG_Load("image.png");

  // Create a texture from the loaded image
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

  // Make a rectangle for partitioning the image
  SDL_Rect imgPartRect;
  
  imgPartRect.w = 180;
  imgPartRect.h = 250;

  // Free the image surface as we have the texture now
  SDL_FreeSurface(image);

  // Main loop
  bool quit = false;
  int frame = 1;
  SDL_Event event;

  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      } else if(event.type == SDL_KEYDOWN) {
      	std::cout << "Key pressed!" << std::endl;
	  }
    }

    if(frame == 1) {
      imgPartRect.x = 0;
      imgPartRect.y = 0;
    } else if(frame == 6) {
      imgPartRect.x = 0;
      imgPartRect.y = 250;
    } else if(frame == 11) {
      imgPartRect.x = 920;
      imgPartRect.y = 250;
    } else if(frame == 12) {
      frame = 1;
      imgPartRect.x = 0;
      imgPartRect.y = 0;
    }

    // Clear the renderer
    SDL_RenderClear(renderer);

    // Render the texture to the window
    SDL_RenderCopy(renderer, texture, &imgPartRect, NULL);

    // Update the screen
    SDL_RenderPresent(renderer);

    imgPartRect.x += 180;
    frame++;

    SDL_Delay(70);
  }

  // Clean up and quit
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();

  return 0;
}
