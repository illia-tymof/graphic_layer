#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace Graphic
{
    class Window;

    class Image
    {
    public:
        Image()
        : m_surface { nullptr }
        {
        }

        ~Image()
        {
            free();
        }

        bool load(const std::string& path);

        void setColorKey(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 0, int flag = SDL_TRUE);

        bool optimiseFor(const Window& window);

        void free()
        {
            if (m_surface != nullptr) { SDL_FreeSurface(m_surface); m_surface = nullptr; }
        }

        SDL_Surface* getSurface() const { return m_surface; }

        Image(const Image&) = delete;
        Image operator=(const Image&) = delete;

    private:
        SDL_Surface* m_surface { nullptr };
    };
}
#endif