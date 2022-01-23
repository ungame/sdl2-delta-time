#ifndef ANIMATION_H
#define ANIMATION_H

#include "Asset.hpp"
#include "Input.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <chrono>

class Animation
{
    public:
        Animation(Asset* asset, std::string name, int row, int frames, int speed);
        void animate(SDL_Renderer* renderer, SDL_Rect* frameData, SDL_RendererFlip flip);
        inline std::string getName() { return _name; }

    private:
        Asset* _asset;
        std::string _name;
        int _row;
        int _frames;
        int _currentFrame;
        int _speed;
        std::chrono::time_point<std::chrono::system_clock> _start;
        std::chrono::duration<double> _end;
};

#endif