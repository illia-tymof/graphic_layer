#include "graphic_layer.h"

bool Graphic::init(int subsystem)
{
    bool succeed { true };

    initedSubsystems |= subsystem;

    if (subsystem && Init::init_sdl)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING))
        {
            std::cout << "Can't init SDL. SDL error: " << SDL_GetError() << '\n';
            succeed = false;
        }
    }

    if (subsystem && Init::init_img)
    {
        if ((IMG_Init(imgFlags) & imgFlags) != imgFlags)
        {
            std::cerr << "Can't init IMG. IMG error: " << IMG_GetError() << '\n';
            succeed = false;
        }
    }

    if (subsystem && Init::init_ttf)
    {
        if (TTF_Init())
        {
            std::cerr << "Can't init TTF. TTF error: " << TTF_GetError() << '\n';
            SDL_Quit();
            succeed = false;
        }
    }

    if (subsystem && Init::init_mix)
    {
        if ((Mix_Init(mixerFlags) & mixerFlags) != mixerFlags)
        {
            std::cerr << "Can't init Mixer. Mixer error: " << Mix_GetError() << '\n';
            succeed = false;
        }

        if (Mix_OpenAudio(soundFrequency, soundFormat, soundChannels, soundChunkSize) < 0)
        {
            std::cerr << "Can't init Mixer. Mixer error: " << Mix_GetError() << '\n';
            succeed = false;
        }
    }

    return succeed;
}

void Graphic::quit()
{
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}