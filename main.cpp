#include <iostream>
extern "C"{
#include <SDL.h>
#include <stdio.h>
}

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
    std::cout << "Hello, World!" << std::endl;

    SDL_Window* window = nullptr;
//    SDL_Texture *tex = SDL_CreateTextureFromSurface()
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow(
            "hello_sdl2",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event e;

    while(true){
        SDL_PollEvent(&e);
        if (SDL_QUIT == e.type){
            break;
        }
        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);
                SDL_Delay(5);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}