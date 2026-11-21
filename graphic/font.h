#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <string>

#include <SDL2/SDL_ttf.h>

namespace Graphic
{
    class Font
    {
    public:
        Font()
        {
        }

        ~Font()
        {
            free();
        }

        bool load(const std::string& path, int size);

        void free()
        {
            if (m_font != nullptr) { TTF_CloseFont(m_font); }
        }

        TTF_Font* getFont() const { return m_font; }

        Font(const Font&) = delete;
        Font& operator=(const Font&) = delete;

    private:
        TTF_Font* m_font { nullptr };
    };
}

#endif