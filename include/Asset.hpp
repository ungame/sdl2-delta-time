#ifndef ASSET_H
#define ASSET_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Asset 
{

    public:
        Asset(SDL_Renderer* renderer, std::string filename);
        void draw(SDL_Renderer* renderer, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void destroy();

    private:
        SDL_Texture* _texture;

};

#endif