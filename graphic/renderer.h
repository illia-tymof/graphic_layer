#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

namespace Graphic
{
    class Texture;
    class Viewport;
    class Window;

    class Renderer
    {
    public:
        Renderer()
            : m_renderer { nullptr }
        {
        }

        ~Renderer()
        {
            free();
        }

        bool create(const Window& window, int index = -1, Uint32 flags = SDL_RENDERER_ACCELERATED);
        void setColor(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 0) const;

        void setViewport(const Viewport& viewport);

        /* usefull for auto scaling */
        void setLogicalSize(int w, int h);

        void getLogicalSize(int& w, int& h) const;
    
        void getLogicalCoords(int& x, int& y) const;

        void clear();
        bool copy(const Texture& texture, int x = 0, int y = 0, int w = 0, int h = 0,
            double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void present() const;

        void free()
        {
            if (m_renderer != nullptr) { SDL_DestroyRenderer(m_renderer); m_renderer = nullptr; }
        }

        SDL_Renderer* getRenderer() const { return m_renderer; }

        Renderer(const Renderer&) = delete;
        Renderer operator=(const Renderer&) = delete;

    private:
        SDL_Renderer* m_renderer { nullptr };
    };
}

#endif