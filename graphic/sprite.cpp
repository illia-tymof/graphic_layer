#include "sprite.h"

#include "renderer.h"
#include "texture.h"
#include "timer.h"

void Graphic::Sprite::init(Texture& spriteSheet, Timer& timer, int totalFrames, Uint32 frameDuration,
        int frameW, int frameH, bool shouldLoop, bool manualUpdate)
{
    m_spriteSheet = &spriteSheet ;
    m_timer = &timer;
    m_totalFrames = totalFrames;
    m_frameDuration = frameDuration;
    m_frameWidth = frameW;
    m_frameHeight = frameH;
    m_shouldLoop = shouldLoop;
    m_manualUpdate = manualUpdate;
    m_convertWidth = frameW;
    m_convertHeight = frameH;
}

void Graphic::Sprite::setPosition(int x, int y, int w, int h)
{
    m_x = x;
    m_y = y;
    m_convertWidth = w;
    m_convertHeight = h;
}

void Graphic::Sprite::setRotation(SDL_RendererFlip flipType, double angle)
{
    m_flipType = flipType;
    m_angle = angle;
    
    m_center.x = m_convertWidth / 2;
    m_center.y = m_convertHeight / 2;
}

void Graphic::Sprite::setRotation(SDL_RendererFlip flipType, double angle, SDL_Point center)
{
    m_flipType = flipType;
    m_angle = angle;

    m_center.x = center.x;
    m_center.y = center.y;
}

bool Graphic::Sprite::update()
{
    bool wasUpdated { false };
    if (!m_shouldLoop && !m_isEnded && m_currentFrame >= m_totalFrames )
    {
        m_isEnded = true;
    }

    if (!m_isEnded && m_timer->getTicks() - m_lastUpdate >= m_frameDuration)
    {
        if (!m_manualUpdate)
        {
            m_currentFrame = (m_currentFrame + 1) % m_totalFrames;

            if (!m_shouldLoop && m_currentFrame + 1 == m_totalFrames)
            {
                m_isEnded = true;
            }
        }

        m_spriteSheet->select(m_frameWidth * m_currentFrame, 0, m_frameWidth, m_frameHeight);

        m_lastUpdate = m_timer->getTicks();

        wasUpdated = true;
    }

    return wasUpdated;
}

void Graphic::Sprite::render(Renderer& renderer)
{
    renderer.copy(*m_spriteSheet, m_x, m_y, m_convertWidth, m_convertHeight, m_angle, &m_center, m_flipType);
}