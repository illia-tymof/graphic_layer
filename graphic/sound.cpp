#include "sound.h"

bool Graphic::Sound::load(const std::string& path, bool isMusic)
{
    free();
    if (isMusic)
    {
        m_isMusic = true;
        m_music = Mix_LoadMUS(path.c_str());
    }

    else
    {
        m_isMusic = false;
        m_sound = Mix_LoadWAV(path.c_str());        
    }

    if (m_music == nullptr && m_sound == nullptr)
    {
        std::cerr << "Can't load sound. Mixer error: " << Mix_GetError() << '\n';
        return false;
    }

    return true;
}

void Graphic::Sound::play(int loops, int channel)
{
    if (m_isMusic)
    {
        Mix_PlayMusic(m_music, loops);
    }

    else
    {
        Mix_PlayChannel(channel, m_sound, loops);
    }
}

void Graphic::Sound::pause()
{
    if (Mix_PausedMusic() != 1)
    {
        if (m_isMusic)
        {
            Mix_PauseMusic();
        }
    }
}

void Graphic::Sound::unpause()
{
    if (Mix_PausedMusic() == 1)
    {
        if (m_isMusic)
        {
            Mix_ResumeMusic();
        }
    }
}

void Graphic::Sound::stop()
{
    if (m_isMusic)
    {
        Mix_HaltMusic();
    }
}