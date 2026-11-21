#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace Graphic
{
    class Font;
    class Image;
    class Renderer;

    class Texture
    {
    public:
        Texture()
            : m_texture { nullptr }
            , m_selectRect {}
        {
        }

        Texture(const Renderer& renderer, const std::string& path)
        {
            m_texture = nullptr;
            load(renderer, path);
            selectAll();
        }

        ~Texture()
        {
            free();
        }

        template <typename T>
        void update(T* pixels)
        {
            selectAll();
            SDL_UpdateTexture(m_texture, nullptr, pixels, sizeof(*pixels) / m_selectRect.h);
            selectAll();
        }

        bool load(const Renderer& renderer, const std::string& path);
        bool loadText(const Renderer& renderer, const std::string& text, const Font& font, Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 0);

        bool create(const Renderer& renderer, Uint32 format, int access, int w, int h);

        /* load and ignore specific color */
        bool loadWithColorKey(const Renderer& renderer, const std::string& path, Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 0, int flag = SDL_TRUE);

        /* needed for alphamod and colormod */
        void setBlendMode(SDL_BlendMode mode);

        void setColorMod(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255);
        void setAlphaMod(Uint8 a = 255);

        void select(int x, int y, int w, int h);
        void selectAll();

        void free()
        {
            if (m_texture != nullptr) SDL_DestroyTexture(m_texture);
        }

        SDL_Texture* getTexture() const { return m_texture; }
        const SDL_Rect& getSelectRect() const { return m_selectRect; }

        int getWidth() const { return m_selectRect.w; }
        int getHeight() const { return m_selectRect.h; }

        Texture(const Texture&) = delete;
        Texture operator=(const Texture&) = delete;

    private:
        SDL_Texture* m_texture { nullptr };
        SDL_Rect m_selectRect {};
    };
}

#endif