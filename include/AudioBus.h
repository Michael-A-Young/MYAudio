/**
@file
	AudioBus.h
@brief
	A node for routing and mixing audio.
*/

#ifndef MY_AUDIO_BUS_H
#define MY_AUDIO_BUS_H

namespace MY
{

class AudioBus
{
public:
	AudioBus();

	AudioBus(const AudioBus& other) = default;
	AudioBus(AudioBus&& other) = default;

	AudioBus& operator=(const AudioBus& other) = default;
	AudioBus& operator=(AudioBus&& other) = default;

	~AudioBus() = default;

private:
};

} // namespace MY

#endif // MY_AUDIO_BUS_H

