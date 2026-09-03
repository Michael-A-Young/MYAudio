/**
@file
	StreamSource.cpp
@brief
	Provides PCM data incrementally from an encoded file.
*/

// MYAudio
#include "AudioSource/StreamSource.h"

namespace MY
{

StreamSource::StreamSource()
	: AudioSource()
{
}

uint64_t StreamSource::Read(float* outPCM, uint64_t frames)
{
	return 0;
}

bool StreamSource::Seek(uint64_t frames)
{
	return false;
}

uint64_t StreamSource::GetLength() const
{
	return 0;
}

uint64_t StreamSource::GetFrame() const
{
	return 0;
}

bool StreamSource::IsFinished() const
{
	return false;
}

bool StreamSource::IsInfinite() const
{
	return false;
}

} // namespace MY
