#include "Rayon/Audio/Audio.hpp"

namespace rayon {
namespace audio {
    RMusicStream::RMusicStream(const std::string& fileName)
    {
        this->music = LoadMusicStream(fileName.c_str());
    }

    RMusicStream::RMusicStream(
        const std::string& fileType, std::vector<unsigned char> data)
    {
        this->music = LoadMusicStreamFromMemory(
            fileType.c_str(), data.data(), data.size());
    }

    RMusicStream::~RMusicStream()
    {
        StopMusicStream(this->music);
        UnloadMusicStream(this->music);
    }

    Music& RMusicStream::inner() { return this->music; }

    void RMusicStream::play(void) { PlayMusicStream(this->music); }

    bool RMusicStream::isPlaying(void)
    {
        return IsMusicStreamPlaying(this->music);
    }

    void RMusicStream::update(void) { UpdateMusicStream(this->music); }

    void RMusicStream::pause(void) { PauseMusicStream(this->music); }

    void RMusicStream::resume(void) { ResumeMusicStream(this->music); }

    void RMusicStream::seek(float position)
    {
        SeekMusicStream(this->music, position);
    }

    void RMusicStream::setVolume(float volume)
    {
        SetMusicVolume(this->music, volume);
    }

    void RMusicStream::setPitch(float pitch)
    {
        SetMusicPitch(this->music, pitch);
    }

    float RMusicStream::getTimeLength(void)
    {
        return GetMusicTimeLength(this->music);
    }

    float RMusicStream::getTimePlayed(void)
    {
        return GetMusicTimePlayed(this->music);
    }
}
}
