#include "Rayon/Audio/Audio.hpp"
#include "raylib.h"

namespace rayon {
namespace audio {

    AudioDevice::AudioDevice(void) { InitAudioDevice(); }

    AudioDevice::~AudioDevice() { CloseAudioDevice(); }

    bool AudioDevice::isReady() { return IsAudioDeviceReady(); }

    void AudioDevice::setMasterVolume(float volume) { SetMasterVolume(volume); }
}
}
