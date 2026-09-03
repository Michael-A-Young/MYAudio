/**
@file
	BufferSource.cpp
@brief
	Provides PCM from a resident buffer in memory.
*/

// MYAudio
#include "AudioSource/BufferSource.h"

namespace MY
{

BufferSource::BufferSource()
	: AudioSource()
{
}

uint64_t BufferSource::Read(float* outPCM, uint64_t frames)
{
	return 0;
}

bool BufferSource::Seek(uint64_t frames)
{
	return false;
}

uint64_t BufferSource::GetLength() const
{
	return 0;
}

uint64_t BufferSource::GetFrame() const
{
	return 0;
}

bool BufferSource::IsFinished() const
{
	return false;
}

bool BufferSource::IsInfinite() const
{
	return false;
}


} // namespace MY
