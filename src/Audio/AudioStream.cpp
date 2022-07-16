#include "Rayon/Audio/Audio.hpp"

namespace rayon {
namespace audio {
    RAudioStream::RAudioStream(
        unsigned int sampleRate, unsigned int sampleSize, unsigned int channels)
    {
        this->audio = LoadAudioStream(sampleRate, sampleSize, channels);
    }

    RAudioStream::~RAudioStream()
    {
        StopAudioStream(this->audio);
        UnloadAudioStream(this->audio);
    }

    AudioStream& RAudioStream::inner() { return this->audio; }

    void RAudioStream::update(const void* data, int samplesCount)
    {
        UpdateAudioStream(this->audio, data, samplesCount);
    }
    bool RAudioStream::isProcessed(void)
    {
        return IsAudioStreamProcessed(this->audio);
    }
    void RAudioStream::play(void) { PlayAudioStream(this->audio); }
    void RAudioStream::pause(void) { PauseAudioStream(this->audio); }
    void RAudioStream::resume(void) { ResumeAudioStream(this->audio); }
    bool RAudioStream::isPlaying(void)
    {
        return IsAudioStreamPlaying(this->audio);
    }
    void RAudioStream::setVolume(float volume)
    {
        SetAudioStreamVolume(this->audio, volume);
    }
    void RAudioStream::setPitch(float pitch)
    {
        SetAudioStreamPitch(this->audio, pitch);
    }
    void RAudioStream::setBufferSizeDefault(int size)
    {
        SetAudioStreamBufferSizeDefault(size);
    }
}
}
