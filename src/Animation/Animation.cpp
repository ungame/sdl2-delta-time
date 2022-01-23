#include "Animation.hpp"
#include "Input.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <chrono>

Animation::Animation(Asset* asset, std::string name, int row, int frames, int speed)
{
    _asset = asset;
    _name = name;
    _row = row;
    _frames = frames;
    _currentFrame = 0;
    _speed = speed; // valor em milissegundos entre um frame e outro
    _start = std::chrono::system_clock::now();
}

void Animation::animate(SDL_Renderer* renderer, SDL_Rect* frameData, SDL_RendererFlip flip)
{
    
    Uint32 tick = SDL_GetTicks();
    int _lastFrame = _currentFrame;
    _currentFrame = (tick  / _speed ) % _frames;

    if (_lastFrame != _currentFrame)
    {
        _end = std::chrono::system_clock::now() - _start;
        std::cout << "Tick=" << tick << ", ";
        std::cout << "Secs=" << _end.count() << ", ";
        std::cout << "Frame=" << _currentFrame << std::endl;
        _start = std::chrono::system_clock::now();
    }


    int x = frameData->x;
    int y = frameData->y;
    int w = frameData->w;
    int h = frameData->h;

    _asset->draw(renderer, x, y, w, h, _row, _currentFrame, flip);
}
