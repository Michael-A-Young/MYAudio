/**
@file
	AudioSource.h
@brief
	Abstraction for an object that can provide PCM.
*/

#ifndef MY_AUDIO_SOURCE_H
#define MY_AUDIO_SOURCE_H

// Standard Library
#include <cstdint>

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

public:
	virtual uint64_t Read(float* outPCM, uint64_t frames) = 0;
	virtual bool Seek(uint64_t frames) = 0;

	virtual uint64_t GetLength() const = 0;
	virtual uint64_t GetFrame() const = 0;

	virtual bool IsFinished() const = 0;
	virtual bool IsInfinite() const = 0;

};

} // namespace MY

#endif // MY_AUDIO_SOURCE_H

