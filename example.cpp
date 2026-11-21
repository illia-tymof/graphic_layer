#include "graphic/graphic_layer.h"
#include <SDL2/SDL.h>

int main()
{
    if (Graphic::init())
    {
        Graphic::Window win { "GRaphic LaYeR" };
        Graphic::Renderer rend {};
        rend.create(win);

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

            rend.present();
        }
    }
    Graphic::quit();
    return 0;
}