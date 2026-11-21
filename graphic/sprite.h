#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

namespace Graphic
{
    class Renderer;
    class Texture;
    class Timer;

    class Sprite
    {
    public:
        Sprite()
        {
        }

        Sprite(Texture& spriteSheet, Timer& timer, int totalFrames, Uint32 frameDuration,
            int frameW, int frameH, bool shouldLoop = true, bool manualUpdate = false)
        {
            init(spriteSheet, timer, totalFrames, frameDuration, frameW, frameH, shouldLoop, manualUpdate);
        }

        void init(Texture& spriteSheet, Timer& timer, int totalFrames, Uint32 frameDuration,
            int frameW, int frameH, bool shouldLoop = true, bool manualUpdate = false);

        void setPosition(int x, int y, int w, int h);
        void setRotation(SDL_RendererFlip flipType, double angle);
        void setRotation(SDL_RendererFlip flipType, double angle, SDL_Point center);

        bool update();
        void render(Renderer& renderer);
    
        void setFrame(int frame) { m_currentFrame = frame; }
        int getTotalFrames() { return m_totalFrames; }

    private:
        Texture* m_spriteSheet { nullptr };
        Timer* m_timer { nullptr };

        int m_totalFrames {};
        Uint32 m_frameDuration {};
        int m_frameWidth {};
        int m_frameHeight {};

        int m_x { 0 };
        int m_y { 0 };

        bool m_shouldLoop { true };
        bool m_manualUpdate { false };

        /* Width and height that will be on screen (in pixels). */
        int m_convertWidth { 0 };
        int m_convertHeight { 0 };

        SDL_RendererFlip m_flipType { SDL_FLIP_NONE };
        double m_angle { 0.0 };
        SDL_Point m_center { 0, 0 };

        bool m_isEnded { false };

        Uint32 m_lastUpdate { 0 };
        int m_currentFrame { 0 };
    };
}

#endif