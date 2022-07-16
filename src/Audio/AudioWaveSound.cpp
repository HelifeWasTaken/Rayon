#include "Rayon/Audio/Audio.hpp"

namespace rayon {
namespace audio {
    RSound::~RSound()
    {
        if (_loadedWave)
            UnloadWave(this->wave);
        if (_loadedSound)
            UnloadSound(this->sound);
    }
    Sound& RSound::inner() { return this->sound; }
    void RSound::loadSound(const std::string& fileName)
    {
        if (_loadedWave) {
            UnloadWave(this->wave);
            _loadedWave = false;
        }
        _loadedSound = true;
        this->sound = LoadSound(fileName.c_str());
    }
    void RSound::loadWave(const std::string& fileName)
    {
        if (_loadedSound) {
            _loadedSound = false;
            UnloadSound(this->sound);
        }
        this->wave = LoadWave(fileName.c_str());
    }
    void RSound::loadWaveFromMemory(
        const std::string& fileType, std::vector<unsigned char> fileData)
    {
        this->wave = LoadWaveFromMemory(
            fileType.c_str(), fileData.data(), fileData.size());
    }

    void RSound::loadSoundFromWave(void)
    {
        this->sound = LoadSoundFromWave(this->wave);
    }

    void RSound::updateSound(const void* data, int samplesCount)
    {
        UpdateSound(this->sound, data, samplesCount);
    }

    void RSound::unloadWave(void) { UnloadWave(this->wave); }

    bool RSound::exportWave(const std::string& fileName)
    {
        return ExportWave(this->wave, fileName.c_str());
    }

    bool RSound::exportWaveAsCode(const std::string& fileName)
    {
        return ExportWaveAsCode(this->wave, fileName.c_str());
    }

    void RSound::play(void) { PlaySound(this->sound); }

    void RSound::stop(void) { StopSound(this->sound); }

    void RSound::pause(void) { PauseSound(this->sound); }

    void RSound::resume(void) { ResumeSound(this->sound); }

    void RSound::playMulti(void) { PlaySoundMulti(this->sound); }

    void RSound::stopMulti(void) { StopSoundMulti(); }

    int RSound::getSoundsPlaying(void) { return GetSoundsPlaying(); }

    bool RSound::isPlaying(void) { return IsSoundPlaying(this->sound); }

    void RSound::setVolume(float volume)
    {
        SetSoundVolume(this->sound, volume);
    }

    void RSound::setPitch(float pitch) { SetSoundPitch(this->sound, pitch); }

    void RSound::waveFormat(int sampleRate, int sampleSize, int channels)
    {
        WaveFormat(&this->wave, sampleRate, sampleSize, channels);
    }

    Wave RSound::waveCopy(void) { return WaveCopy(this->wave); }

    void RSound::waveCrop(int initSample, int finalSample)
    {
        WaveCrop(&this->wave, initSample, finalSample);
    }

    float* RSound::loadWaveSamples(void) { return LoadWaveSamples(this->wave); }

    void RSound::unloadWaveSamples(float* samples)
    {
        UnloadWaveSamples(samples);
    }
}
}
