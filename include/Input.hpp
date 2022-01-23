#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

class Input
{
    public:
        Input();
        bool listen();
        bool isKeyDown(SDL_Scancode key);


    private:
        const Uint8* _keyboard;
};

#endif