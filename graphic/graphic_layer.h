#ifndef GRAPHIC_LAYER_H
#define GRAPHIC_LAYER_H

#include <iostream>

#include "camera.h"
#include "font.h"
#include "image.h"
#include "renderer.h"
#include "sound.h"
#include "sprite.h"
#include "texture.h"
#include "timer.h"
#include "viewport.h"
#include "window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

namespace Graphic
{
    namespace Init
    {
        enum InitType
        {
            init_undefined = 0,
            init_sdl = 0x1 << 0,
            init_img = 0x1 << 1,
            init_ttf = 0x1 << 2,
            init_mix = 0x1 << 3,
            init_all = 0xF
        };
    }

    bool init(int subsystem);
    void quit();

    inline unsigned initedSubsystems {};

    /* IMG flags */
    inline int imgFlags { IMG_INIT_AVIF | IMG_INIT_JPG | IMG_INIT_JXL | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP };

    /* Mixer parameters */
    inline int mixerFlags { MIX_INIT_MP3 | MIX_INIT_WAVPACK | MIX_INIT_OGG };
    inline int soundFrequency { MIX_DEFAULT_FREQUENCY };
    inline Uint16 soundFormat { MIX_DEFAULT_FORMAT };
    inline int soundChannels { MIX_DEFAULT_CHANNELS };
    inline int soundChunkSize { 2048 };
}

#endif