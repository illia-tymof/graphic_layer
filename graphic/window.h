#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>

namespace Graphic
{
    class Image;

    class Window
    {
    public:
        Window(const std::string& title = "?",
            int w = 300, int h = 200, Uint32 flags = SDL_WINDOW_SHOWN,
            int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED);


        ~Window()
        {
            free();
        }

        bool createSurface();
        bool blit(const Image& image, int x = 0, int y = 0, int w = 0, int h = 0) const;
        void update() const;
    
        void free()
        {
            if (m_surface != nullptr) SDL_FreeSurface(m_surface);
            if (m_window != nullptr) SDL_DestroyWindow(m_window);
        }

        int getWidth() { SDL_GetWindowSize(m_window, &m_w, &m_h); return m_w; }
        int getHeight() { SDL_GetWindowSize(m_window, &m_w, &m_h); return m_h; }

        SDL_Window* getWindow() const { return m_window; }
        SDL_Surface* getSurface() const { return m_surface; }

        Window(const Window&) = delete;
        Window operator=(const Window&) = delete;

    private:
        std::string m_title {};
        int m_w {};
        int m_h {};
        Uint32 m_flags {};
        int m_x {};
        int m_y {};
        SDL_Window* m_window { nullptr };
        SDL_Surface* m_surface { nullptr };
    };
}

#endif