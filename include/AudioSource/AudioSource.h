/**
@file
	AudioSource.h
@brief
	Abstraction for an object that can provide PCM.
*/

#ifndef MY_AUDIO_SOURCE_H
#define MY_AUDIO_SOURCE_H

namespace MY
{

class AudioSource
{
public:
	AudioSource();

	AudioSource(const AudioSource& other) = default;
	AudioSource(AudioSource&& other) = default;

	AudioSource& operator=(const AudioSource& other) = default;
	AudioSource& operator=(AudioSource&& other) = default;

	virtual ~AudioSource() = default;

private:
};

} // namespace MY

#endif // MY_AUDIO_SOURCE_H

