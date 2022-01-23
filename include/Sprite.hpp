#ifndef SPRITE_H
#define SPRITE_H

#include "Asset.hpp"
#include "Animation.hpp"
#include "Input.hpp"

#include <SDL2/SDL.h>
#include <map>
#include <string>

#define WALK_SPEED 3.0f

class Sprite
{
    public:
        Sprite(Asset *asset, SDL_Rect* frameData);
        void update(Input* input, float deltaTime);
        void draw(SDL_Renderer* renderer);

    private:
        std::map<std::string, Animation*> _animations;
        std::string _currentAnimation;
        SDL_Rect* _frameData;
        SDL_RendererFlip _flip;
        float _x, _y;
};

#endif