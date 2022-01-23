#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Asset.hpp"
#include "Animation.hpp"
#include "Input.hpp"
#include "Sprite.hpp"
#include "DeltaTime.hpp"

#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char** argv)
{
    if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        SDL_ClearError();

        return EXIT_FAILURE;
    }

    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    int imgInitted = IMG_Init(imgFlags);

    if ( (imgInitted&imgFlags) != imgFlags )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", IMG_GetError());

        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("Game Engine Timer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    
    if ( window == nullptr )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create window failed");

        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if ( renderer == nullptr )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create window failed");

        return EXIT_FAILURE;
    }

    Asset* asset = new Asset(renderer, "assets/player.png");
    
    SDL_Rect frameData;
    frameData.w = 512 / 8;
    frameData.h = 128 / 2;
    frameData.x = WINDOW_WIDTH / 2 - frameData.w;
    frameData.y = WINDOW_HEIGHT / 2 - frameData.h;
    
    Sprite* sprite = new Sprite(asset, &frameData);
   
    Input* input = new Input();

    float lastTime = (float) SDL_GetTicks();
    float frameTime = 0;

    DeltaTime* deltaTime = new DeltaTime();
    float dt = TARGET_DELTATIME;

    while(input->listen())
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderClear(renderer);

        sprite->update(input, dt);
        sprite->draw(renderer);

        SDL_RenderPresent(renderer);

        frameTime = (SDL_GetTicks() - lastTime);
        dt = deltaTime->compute(frameTime);
        lastTime = SDL_GetTicks();
    }

    asset->destroy();
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}