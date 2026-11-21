#ifndef GRAPHIC_LAYER_H
#define GRAPHIC_LAYER_H

#include <iostream>

#include "camera.h"
#include "font.h"
#include "image.h"
#include "renderer.h"
#include "sprite.h"
#include "texture.h"
#include "timer.h"
#include "viewport.h"
#include "window.h"

#include <SDL2/SDL.h>

namespace Graphic
{
    static inline bool init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING))
        {
            std::cout << "Can't init SDL. SDL error: " << SDL_GetError() << '\n';
            return false;
        }

        /* init all image extensions */
        int imgFlags { IMG_INIT_AVIF | IMG_INIT_JPG | IMG_INIT_JXL | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP };

        if ((IMG_Init(0) & imgFlags) != imgFlags)
        {
            if ((IMG_Init(imgFlags) & imgFlags) != imgFlags)
            {
                std::cerr << "Can't init IMG. IMG error: " << IMG_GetError() << '\n';
                return false;
            }
        }

        if (TTF_Init())
        {
            std::cout << "Can't init TTF. TTF error: " << TTF_GetError() << '\n';
            SDL_Quit();
            return false;
        }
        return true;
    }

    static inline void quit()
    {
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }
}

#endif