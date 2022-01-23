#include "Input.hpp"

#include <SDL2/SDL.h>

Input::Input()
{
    _keyboard = SDL_GetKeyboardState(nullptr);
}

bool Input::listen()
{
    SDL_Event event;
  
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            return false;
            
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            _keyboard = SDL_GetKeyboardState(nullptr);
            break;
        
        default:
            break;
        }
    }

    return true;
}

bool Input::isKeyDown(SDL_Scancode key)
{
    return _keyboard[key] == 1;
}
