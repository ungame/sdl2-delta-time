#include "Asset.hpp"
#include "Animation.hpp"
#include "Input.hpp"
#include "Sprite.hpp"
#include <vector>

Sprite::Sprite(Asset* asset, SDL_Rect* frameData)
{
    int row = 0;
    int frames = 2;
    // os frames serão alternados a cada 200 milissegundos
    Animation* idle = new Animation(asset, "idle", row, frames, 200);
    _animations[idle->getName()] = idle;
    _currentAnimation = idle->getName();

    row = 1;
    frames = 8;
    // os frames serão alternados a cada 100 milissegundos
    Animation* walk = new Animation(asset, "walk", row, frames, 100);
    _animations[walk->getName()] = walk;
   
    _frameData = frameData;
    _flip = SDL_FLIP_NONE;
    _x = _frameData->x;
    _y = _frameData->y;
}

void Sprite::update(Input* input, float deltaTime)
{
    bool isWalking = false;

    if (input->isKeyDown(SDL_SCANCODE_LEFT))
    {    
        _x -= WALK_SPEED * deltaTime;
        _currentAnimation = "walk";
        _flip = SDL_FLIP_HORIZONTAL;
        isWalking = true;
    }

    if (input->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        _x += WALK_SPEED * deltaTime;
        _currentAnimation = "walk";
        _flip = SDL_FLIP_NONE;
        isWalking = true;
    }

    if (!isWalking) 
    {
        _currentAnimation = "idle";
    }
}

void Sprite::draw(SDL_Renderer* renderer)
{
    _frameData->x = _x; // truncate float to integer
    _frameData->y = _y; // truncate float to integer
    _animations.at(_currentAnimation)->animate(renderer, _frameData, _flip);
}