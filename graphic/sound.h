#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <string>

#include <SDL2/SDL_mixer.h>

namespace Graphic
{
    class Sound
    {
    public:
        Sound()
        {
        }

        ~Sound()
        {
            free();
        }

        void free()
        {
            if (m_music != nullptr) { Mix_FreeMusic(m_music); m_music = nullptr; }
            if (m_sound != nullptr) { Mix_FreeChunk(m_sound); m_sound = nullptr; }
        }

        bool load(const std::string& path, bool isMusic);
        void play(int loops, int channel = -1);
        void pause();
        void unpause();
        void stop();
        bool isPaused() const { return (Mix_PausedMusic() == 1) ? true : false; }
        
        Sound(const Sound&) = delete;
        Sound operator=(const Sound&) = delete;

    private:
       Mix_Music* m_music { nullptr };
       Mix_Chunk* m_sound { nullptr };
       
       bool m_isMusic {};
    };
}

#endif