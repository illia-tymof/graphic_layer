#include "renderer.h"

#include "texture.h"
#include "viewport.h"
#include "window.h"

bool Graphic::Renderer::create(const Window& window, int index, Uint32 flags)
{
    free();
    m_renderer = SDL_CreateRenderer(window.getWindow(), index, flags);
    
    if (m_renderer == nullptr)
    {
        std::cerr << "Can't create renderer. SDL error: " << SDL_GetError() << '\n';
        return false;
    }

    return true;
}

void Graphic::Renderer::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void Graphic::Renderer::setViewport(const Viewport& viewport)
{
    SDL_RenderSetViewport(m_renderer, viewport.getViewport());
}

void Graphic::Renderer::setLogicalSize(int w, int h)
{
    SDL_RenderSetLogicalSize(m_renderer, w, h);
}

void Graphic::Renderer::getLogicalSize(int& w, int& h)
{
    SDL_Rect vp {};
    SDL_RenderGetViewport(m_renderer, &vp);

    w = vp.w;
    h = vp.h;
}

void Graphic::Renderer::getLogicalCoords(int& x, int& y)
{
    SDL_Rect vp {};
    SDL_RenderGetViewport(m_renderer, &vp);

    x = vp.x;
    y = vp.y;
}

void Graphic::Renderer::clear()
{
    SDL_RenderClear(m_renderer);
}

bool Graphic::Renderer::copy(const Texture& texture, int x, int y, int w, int h, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    if (texture.getTexture() == nullptr)
    {
        std::cerr << "Can't copy null texture.\n";
        return false;
    }

    SDL_Rect pasteRect { x, y, w, h };

    SDL_RenderCopyEx(m_renderer, texture.getTexture(), &texture.getSelectRect(), &pasteRect, angle, center, flip);

    return true;
}

void Graphic::Renderer::present() const
{
    SDL_RenderPresent(m_renderer);    
}