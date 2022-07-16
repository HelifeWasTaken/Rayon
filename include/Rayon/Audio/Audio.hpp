#pragma once

#include "raylib.h"
#include <string>
#include <vector>

namespace rayon {
namespace audio {
    /**
     * @brief AudioDevice class
     * @details This class is used to handle audio device
     */
    class AudioDevice {
    public:
        /**
         * @brief
         * @details Constructor.
         */
        AudioDevice();
        ~AudioDevice();
        /**
         * @brief
         * @details Check if audio device has been initialized successfully
         * @return true or false
         */
        bool isReady(void);
        /**
         * @brief Set the Master Volume object
         * @param volume
         */
        void setMasterVolume(float volume);
    };

    /**
     * @brief RSound class
     * @details This class is used to handle sound
     */

    class RSound {
    private:
        /**
         * @brief audio wave data
         *
         */
        Wave wave = { 0 };
        Sound sound = { 0 };

        bool _loadedWave = false;
        bool _loadedSound = false;

    public:
        ~RSound();

        /**
         *@brief get the sound inner object
         *
         */

        Sound& inner();
        /**
         * @brief  Load wave data from file
         *
         *
         * @param fileName
         */
        void loadWave(const std::string& fileName);

        /**
         * @brief Load wave from memory buffer
         *
         *
         * @param fileType
         * @param fileData
         */
        void loadWaveFromMemory(
            const std::string& fileType, std::vector<unsigned char> fileData);

        /**
         * @brief Load sound from file
         *
         * @param fileName
         */
        void loadSound(const std::string& fileName);

        /**
         * @brief Load sound from wave data
         *
         */
        void loadSoundFromWave(void);

        /**
         * @brief Update sound buffer with new data
         *
         * @param data
         * @param samplesCount
         */
        void updateSound(const void* data, int samplesCount);

        /**
         * @brief Unload wave data
         *
         */
        void unloadWave(void);

        /**
         * @brief Export wave data to file, returns true on success
         *
         * @param fileName
         * @return true
         * @return false
         */
        bool exportWave(const std::string& fileName);

        /**
         * @brief Export wave sample data to code (.h), returns true on success
         *
         * @param fileName
         * @return true
         * @return false
         */
        bool exportWaveAsCode(const std::string& fileName);

        /**
         * @brief Play a sound
         *
         */

        void play(void);

        /**
         * @brief Stop playing a sound
         *
         */
        void stop(void);

        /**
         * @brief Pause a sound
         *
         */
        void pause(void);

        /**
         * @brief Resume a paused sound
         *
         */
        void resume(void);

        /**
         * @brief Play a sound (using multichannel buffer pool)
         *
         */
        void playMulti(void);

        /**
         * @brief Stop any sound playing (using multichannel buffer pool)
         *
         */
        void stopMulti(void);

        /**
         * @brief Get number of sounds playing in the multichannel
         *
         * @return int
         */
        int getSoundsPlaying(void);

        /**
         * @brief Check if a sound is currently playing
         *
         * @return true
         * @return false
         */
        bool isPlaying(void);
        /**
         * @brief Set volume for a sound (1.0 is max level)
         *
         * @param volume
         */
        void setVolume(float volume);

        /**
         * @brief Set pitch for a sound (1.0 is base level)
         *
         * @param pitch
         */
        void setPitch(float pitch);
        /**
         * @brief Convert wave data to desired format
         *
         * @param sampleRate
         * @param sampleSize
         * @param channels
         */
        void waveFormat(int sampleRate, int sampleSize, int channels);

        /**
         * @brief Copy a wave to a new wave
         *
         * @return Wave
         */
        Wave waveCopy(void);

        /**
         * @brief Crop a wave to defined samples range
         *
         * @param initSample
         * @param finalSample
         */
        void waveCrop(int initSample, int finalSample);

        /**
         * @brief Load samples data from wave as a floats array
         *
         * @return float*
         */
        float* loadWaveSamples(void);

        /**
         * @brief Unload samples data loaded with LoadWaveSamples()
         *
         * @param samples
         */
        void unloadWaveSamples(float* samples);
    };

    /**
     * @brief RMusicStream class
     * @details Music management functions
     */
    class RMusicStream {
    private:
        /**
         * @brief  Music, audio stream, anything longer than ~10 seconds should
         * be streamed
         *
         */
        Music music;

    public:
        /**
         * @brief Construct a new RMusicStream object
         *
         * @param fileName
         */
        RMusicStream(const std::string& fileName);

        /**
         * @brief Construct a new RMusicStream object with a data
         *
         * @param fileType
         * @param data
         */
        RMusicStream(
            const std::string& fileType, std::vector<unsigned char> data);
        ~RMusicStream();

        /**
         * @brief get the music inner object
         *
         * @return Music&
         */
        Music& inner();

        /**
         * @brief Load music stream from file
         *
         * @param fileName
         */
        void load(const std::string& fileName);

        /**
         * @brief Load music stream from data
         *
         * @param fileType
         * @param data
         */
        void loadFromMemory(
            const std::string& fileType, std::vector<unsigned char> data);

        /**
         * @brief Start music playing
         *
         */
        void play(void);

        /**
         * @brief Check if music is playing
         *
         * @return true
         * @return false
         */
        bool isPlaying(void);

        /**
         * @brief Updates buffers for music streaming
         *
         */
        void update(void);

        /**
         * @brief Pause music playing
         *
         */
        void pause(void);

        /**
         * @brief Resume playing paused music
         *
         */
        void resume(void);

        /**
         * @brief Seek music to a position (in seconds)
         *
         * @param position
         */
        void seek(float position);

        /**
         * @brief Set volume for music (1.0 is max level)
         *
         * @param volume
         */
        void setVolume(float volume);

        /**
         * @brief Set pitch for a music (1.0 is base level)
         *
         * @param pitch
         */
        void setPitch(float pitch);
        /**
         * @brief Get music time length (in seconds)
         *
         * @return float
         */
        float getTimeLength(void);

        /**
         * @brief Get current music time played (in seconds)
         *
         * @return float
         */
        float getTimePlayed(void);
    };

    /**
     * @brief RAudioStream class
     * @details AudioStream management functions
     */
    class RAudioStream {
    private:
        /**
         * @brief get AudioStream, custom audio stream object
         *
         */
        AudioStream audio;

    public:
        /**
         * @brief Construct a new RAudioStream object
         *
         * @param sampleRate
         * @param sampleSize
         * @param channels
         */
        RAudioStream(unsigned int sampleRate, unsigned int sampleSize,
            unsigned int channels);
        ~RAudioStream();

        /**
         * @brief get the inner AudioStream object
         *
         * @return AudioStream&
         */
        AudioStream& inner();

        /**
         * @brief Update audio stream buffers with data
         *
         * @param data
         * @param samplesCount
         */
        void update(const void* data, int samplesCount);

        /**
         * @brief Check if any audio stream buffers requires refill
         *
         * @return true
         * @return false
         */
        bool isProcessed(void);

        /**
         * @brief Play audio stream
         *
         */
        void play(void);

        /**
         * @brief Pause audio stream
         *
         */
        void pause(void);

        /**
         * @brief Resume audio stream
         *
         */
        void resume(void);

        /**
         * @brief Check if audio stream is playing
         *
         * @return true
         * @return false
         */

        bool isPlaying(void);

        /**
         * @brief Set volume for audio stream (1.0 is max level)
         *
         * @param volume
         */
        void setVolume(float volume);

        /**
         * @brief Set pitch for audio stream (1.0 is base level)
         *
         * @param pitch
         */
        void setPitch(float pitch);

        /**
         * @brief Set default size for new audio streams
         *
         * @param size
         */
        void setBufferSizeDefault(int size);
    };
};
}
