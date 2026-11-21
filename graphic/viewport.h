#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <SDL2/SDL.h>

namespace Graphic
{
    class Viewport
    {
    public:
        Viewport()
            : m_viewport {}
        {
        }

        void set(int x, int y, int w, int h)
        { 
            m_viewport = SDL_Rect{ x, y, w, h };
        }

        const SDL_Rect* getViewport() const { return &m_viewport; }

        int getWidth() const { return m_viewport.w; }
        int getHeight() const { return m_viewport.h; }

    private:
        SDL_Rect m_viewport {};
    };
}

#endif