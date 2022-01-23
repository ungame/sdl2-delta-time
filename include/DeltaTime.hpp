#ifndef DELTATIME_H
#define DELTATIME_H

#include <SDL2/SDL.h>

#define TARGET_FPS 60.0f
#define SECOND_IN_MS 1000.0f
#define TARGET_DELTATIME 1.5f

class DeltaTime
{
    public:
        DeltaTime();
        float compute(float frameTime);
};

#endif