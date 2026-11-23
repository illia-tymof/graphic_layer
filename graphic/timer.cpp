#include "timer.h"

void Graphic::Timer::start()
{
    m_startTicks = SDL_GetTicks();
    m_pauseTicks = 0;
    m_isStarted = true;
    m_isPaused = false;
}

void Graphic::Timer::pause()
{
    if (m_isStarted && !m_isPaused)
    {
        m_isPaused = true;
        m_pauseTicks = SDL_GetTicks() - m_startTicks;
        m_startTicks = 0;
    }
}

void Graphic::Timer::unpause()
{
    if (m_isStarted && m_isPaused)
    {
        m_isPaused = false;
        m_startTicks = SDL_GetTicks() - m_pauseTicks;
        m_pauseTicks = 0;
    }
}

Uint32 Graphic::Timer::getTicks() const
{
    Uint32 ticks { 0 };
    if (m_isStarted)
    {
        if (m_isPaused)
        {
            ticks = m_pauseTicks;
        }

        else
        {
            ticks = SDL_GetTicks() - m_startTicks;
        }
    }

    return ticks;
}

void Graphic::Timer::stop()
{
    m_startTicks = 0;
    m_pauseTicks = 0;
    m_isStarted = false;
    m_isPaused = false;
}