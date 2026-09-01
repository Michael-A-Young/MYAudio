/**
@file
	StreamSource.h
@brief
	Provides PCM data incrementally from an encoded file.
*/

#ifndef MY_STREAM_SOURCE_H
#define MY_STREAM_SOURCE_H

#include "AudioSource.h"

namespace MY
{

class StreamSource : public AudioSource
{
public:
	StreamSource();

	StreamSource(const StreamSource& other) = default;
	StreamSource(StreamSource&& other) = default;

	StreamSource& operator=(const StreamSource& other) = default;
	StreamSource& operator=(StreamSource&& other) = default;

	~StreamSource() override = default;

private:
};

} // namespace MY

#endif // MY_STREAM_SOURCE_H

