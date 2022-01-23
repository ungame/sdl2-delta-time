#include "Asset.hpp"

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Asset::Asset(SDL_Renderer* renderer, std::string filePath)
{
    SDL_Surface* surface = IMG_Load(filePath.c_str());

    if (surface == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl load image failed: %s, %s", filePath.c_str(), IMG_GetError());

        return;
    }

    _texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    if ( _texture == nullptr )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create image from surface failed: %s, %s", filePath.c_str(), SDL_GetError());
    }
}

void Asset::draw(SDL_Renderer* renderer, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect src;
    src.x = width * frame;
    src.y = height * row;
    src.w = width;
    src.h = height;

    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = width * 2;
    dst.h = height * 2;

    SDL_RenderCopyEx(renderer, _texture, &src, &dst, 0, nullptr, flip);
}

void Asset::destroy()
{
    if (_texture != nullptr)
    {
        SDL_DestroyTexture(_texture);
    }
}