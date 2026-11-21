#include "window.h"

#include "image.h"

Graphic::Window::Window(const std::string& title,
        int w, int h, Uint32 flags,
        int x, int y)

        : m_title { title }
        , m_w { w }
        , m_h { h }
        , m_flags { flags }
        , m_x { x }
        , m_y { y }
        , m_window { SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_w, m_h, m_flags) }
        , m_surface { nullptr }
    {    
        if (m_window == nullptr)
        {
            std::cerr << "Can't create '" << m_title << "' window. SDL error: " << SDL_GetError() << '\n';
        }
    }

bool Graphic::Window::createSurface()
    {
        m_surface = SDL_GetWindowSurface(m_window);
        if (m_surface == nullptr)
        {
            std::cerr << "Can't create surface for '" << m_title << "' window. SDL error: " << SDL_GetError() << '\n';
            return false;
        }

        return true;
    }

bool Graphic::Window::blit(const Image& image, int x, int y, int w, int h) const
{
    if (image.getSurface() == nullptr)
    {
        std::cerr << "Can't blit null surface.\n";
        return false;
    }

    SDL_Rect pasteRect { x, y, w, h };

    if (w == 0 || h == 0)
    {
        SDL_BlitSurface(image.getSurface(), nullptr, m_surface, &pasteRect);
    }

    else
    {
        SDL_BlitScaled(image.getSurface(), NULL, m_surface, &pasteRect);
    }

    return true;
}

void Graphic::Window::update() const
    {
        if (m_window != nullptr)
        {
            SDL_UpdateWindowSurface(m_window);
        }
    }