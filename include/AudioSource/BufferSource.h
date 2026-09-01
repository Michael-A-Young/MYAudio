/**
@file
	BufferSource.h
@brief
	Provides PCM from a resident buffer in memory.
*/

#ifndef MY_BUFFER_SOURCE_H
#define MY_BUFFER_SOURCE_H

#include "AudioSource.h"

namespace MY
{

class BufferSource : public AudioSource
{
public:
	BufferSource();

	BufferSource(const BufferSource& other) = default;
	BufferSource(BufferSource&& other) = default;

	BufferSource& operator=(const BufferSource& other) = default;
	BufferSource& operator=(BufferSource&& other) = default;

	~BufferSource() override = default;

private:
};

} // namespace MY

#endif // MY_BUFFER_SOURCE_H

