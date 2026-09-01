/**
@file
	WAVDecoder.h
@brief
	Decodes WAV audio source into PCM.
*/

#ifndef MY_WAV_DECODER_H
#define MY_WAV_DECODER_H

#include "AudioDecoder.h"

namespace MY
{

class WAVDecoder : public AudioDecoder
{
public:
	WAVDecoder();

	WAVDecoder(const WAVDecoder& other) = default;
	WAVDecoder(WAVDecoder&& other) = default;

	WAVDecoder& operator=(const WAVDecoder& other) = default;
	WAVDecoder& operator=(WAVDecoder&& other) = default;

	~WAVDecoder() override = default;

private:
};

} // namespace MY

#endif // MY_WAV_DECODER_H

