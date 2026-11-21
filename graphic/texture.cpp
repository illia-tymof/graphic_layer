#include "texture.h"

#include "font.h"
#include "image.h"
#include "renderer.h"

bool Graphic::Texture::load(const Renderer& renderer, const std::string& path)
{
    free();
    Image loadedImage {};
    if (!loadedImage.load(path.c_str()))
    {
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), loadedImage.getSurface());
    if (m_texture == nullptr)
    {
        std::cerr << "Can't load texture. SDL error: " << SDL_GetError() << '\n';
        return false;
    }

    SDL_QueryTexture(m_texture, nullptr, nullptr, &(m_selectRect.w), &(m_selectRect.h));
    selectAll();

    return true;
}

bool Graphic::Texture::loadText(const Renderer& renderer, const std::string& text, const Font& font, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    free();
    SDL_Surface* textSurface { TTF_RenderUTF8_Solid(font.getFont(), text.c_str(), SDL_Color { r, g, b, a }) };

    if (textSurface == nullptr)
    {
        std::cerr << "Can't load text. TTF error: "  << TTF_GetError() << '\n';
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), textSurface);
    if (m_texture == nullptr)
    {
        std::cerr << "Can't load texture. SDL error: " << SDL_GetError() << '\n';
        return false;
    }

    SDL_QueryTexture(m_texture, nullptr, nullptr, &(m_selectRect.w), &(m_selectRect.h));
    selectAll();

    SDL_FreeSurface(textSurface);

    return true;
}

bool Graphic::Texture::create(const Renderer& renderer, Uint32 format, int access, int w, int h)
{
    free();
    m_texture = SDL_CreateTexture(renderer.getRenderer(), format, access, w, h);
    if (m_texture == nullptr)
    {
        std::cerr << "Can't load texture. SDL error: " << SDL_GetError() << '\n';
        return false;
    }

    SDL_QueryTexture(m_texture, nullptr, nullptr, &(m_selectRect.w), &(m_selectRect.h));
    selectAll();

    return true;
}

bool Graphic::Texture::loadWithColorKey(const Renderer& renderer, const std::string& path, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int flag)
{
    free();
    Image loadedImage {};
    if (!loadedImage.load(path.c_str()))
    {
        return false;
    }

    loadedImage.setColorKey(r, g, b, a, flag);

    m_texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), loadedImage.getSurface());
    if (m_texture == nullptr)
    {
        std::cerr << "Can't load texture. SDL error: " << SDL_GetError() << '\n';
        return false;
    }

    SDL_QueryTexture(m_texture, nullptr, nullptr, &(m_selectRect.w), &(m_selectRect.h));
    selectAll();

    return true;
}

void Graphic::Texture::setBlendMode(SDL_BlendMode mode)
{
    SDL_SetTextureBlendMode(m_texture, mode);
}

void Graphic::Texture::setColorMod(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(m_texture, r, g, b);
}

void Graphic::Texture::setAlphaMod(Uint8 a)
{
    SDL_SetTextureAlphaMod(m_texture, a);
}

void Graphic::Texture::select(int x, int y, int w, int h)
{
    m_selectRect.x = x;
    m_selectRect.y = y;
    m_selectRect.w = w;
    m_selectRect.h = h;
}

void Graphic::Texture::selectAll()
{
    m_selectRect.x = 0;
    m_selectRect.y = 0;
    
    SDL_QueryTexture(m_texture, nullptr, nullptr, &(m_selectRect.w), &(m_selectRect.h));
}