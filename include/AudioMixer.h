/**
@file
	AudioMixer.h
@brief
	Mixes audio playback from multiple channels into one PCM output.
*/

#ifndef MY_AUDIO_MIXER_H
#define MY_AUDIO_MIXER_H

// Standard Library
#include <cstdint>

namespace MY
{

class AudioMixer
{
public:
	AudioMixer();

	AudioMixer(const AudioMixer& other) = default;
	AudioMixer(AudioMixer&& other) = default;

	AudioMixer& operator=(const AudioMixer& other) = default;
	AudioMixer& operator=(AudioMixer&& other) = default;

	~AudioMixer() = default;

public:
    void Render(float* output, uint64_t frames);

private:
};

} // namespace MY

#endif // MY_AUDIO_MIXER_H

