#include "font.h"

bool Graphic::Font::load(const std::string& path, int size)
{
    free();

    m_font = TTF_OpenFont(path.c_str(), size);

    if (m_font == nullptr)
    {
        std::cerr << "Can't open font. TTF error: " << TTF_GetError() << '\n';
        return false;
    }

    return true;
}