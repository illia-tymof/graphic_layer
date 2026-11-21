#include "image.h"

#include "window.h"

bool Graphic::Image::load(const std::string& path)
    {
        free();

        m_surface = IMG_Load(path.c_str());
        if (m_surface == nullptr)
        {
            std::cerr << "Can't load '" << path << "' image. IMG error: " << IMG_GetError() << '\n';
            return false;
        }

        return true;
    }

void Graphic::Image::setColorKey(Uint8 r, Uint8 g, Uint8 b, Uint8 a, int flag)
{
    /* ignore following color */
    SDL_SetColorKey(m_surface, flag, SDL_MapRGBA(m_surface->format, r, g, b, a));
}

/* Used only in CPU rendering, i don't know why the fuck I wrote this */
bool Graphic::Image::optimiseFor(const Window& window)
{
    SDL_Surface* optimasedSurf { nullptr };
    if (window.getSurface() == nullptr)
    {
        std::cerr << "Can't optimise for null surface.\n";
        return false;
    }

    optimasedSurf = SDL_ConvertSurface(m_surface, window.getSurface()->format, 0);
    if (optimasedSurf == nullptr)
    {
        std::cerr << "Can't optimise image for surface. SDL error: " << SDL_GetError() << '\n';
        return false;
    }

    if (m_surface != nullptr) SDL_FreeSurface(m_surface);
    m_surface = optimasedSurf;

    return true;
}