#include "graphic/graphic_layer.h"
#include <SDL2/SDL.h>

#include <array>
int main()
{
    if (Graphic::init(Graphic::Init::init_sdl | Graphic::Init::init_img | Graphic::Init::init_mix))
    {
        std::array<bool, 5*5> mono {
            1, 0, 1, 0, 0,
            0, 1, 1, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 1, 1, 0,
            0, 0, 1, 0, 1
        };

        Graphic::Window win { "GRaphic LaYeR" };
        Graphic::Renderer rend {};
        rend.create(win);

        Graphic::Texture texture {};
        texture.create(rend, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, 5, 5);
        
        std::array<Uint32, 5*5> newTexture {};
        for (std::size_t i {}; i < newTexture.size(); ++i)
        {
            newTexture[i] = (mono[i]) ? 0x00FFB000 : 0x000A0600;
        }

        texture.update(&newTexture);

        SDL_Event event;
        bool running { true };
        while (running)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
            }

            rend.setColor(0, 0, 0);
            rend.clear();
            rend.setColor(43, 54, 98);

            /* for layer-undefined functionality: */
            SDL_Rect rect { 69, 23, 245, 181 };
            SDL_RenderFillRect(rend.getRenderer(), &rect);
            rend.setColor(200, 0, 200, 255);
            SDL_RenderDrawLine(rend.getRenderer(), 0, 0, win.getWidth(), win.getHeight());

            rend.copy(texture, 0, 0, 100, 100);
            rend.present();
        }
    }
    Graphic::quit();
    return 0;
}