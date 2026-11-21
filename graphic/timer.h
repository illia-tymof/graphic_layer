#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

namespace Graphic
{
    class Timer
    {
    public:
        Timer()
            : m_startTicks {}
            , m_pauseTicks {}
            , m_isStarted { false }
            , m_isPaused { false }
        {
        }

        void start();
        void pause();
        void unpause();
        Uint32 getTicks();
        void stop();

        bool isStarted() const { return m_isStarted; }
        bool isPaused() const { return m_isPaused; }

    private:
        Uint32 m_startTicks {};
        Uint32 m_pauseTicks {};
        bool m_isStarted {};
        bool m_isPaused {};
    };
}

#endif