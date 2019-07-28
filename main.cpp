#include <cmath>
#include <iostream>
#include <limits>
#include <cstdio>
extern "C"{
#include <SDL.h>

}

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
int i = 0;
int main() {
    std::cout << "Hello, World!" << std::endl;

    SDL_Window* window = nullptr;
//    SDL_Texture *tex = SDL_CreateTextureFromSurface()
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow(
            "Colors",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event e;

    while(true){
        SDL_PollEvent(&e);
        if (SDL_QUIT == e.type){
            break;
        }

        SDL_SetRenderDrawColor(ren,
                abs(sin((i*0.01)     ) * UINT8_MAX),
                abs(sin((i*0.01) + 10) * UINT8_MAX),
                abs(sin((i*0.01) + 5 ) * UINT8_MAX),
                255);
        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);
        SDL_Delay(5);
        i++;

    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}