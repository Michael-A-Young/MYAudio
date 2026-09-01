/**
@file
	AudioDecoder.h
@brief
	Abstracts audio file encoding and decodes into PCM.
*/

#ifndef MY_AUDIO_DECODER_H
#define MY_AUDIO_DECODER_H

namespace MY
{

class AudioDecoder
{
public:
	AudioDecoder();

	AudioDecoder(const AudioDecoder& other) = default;
	AudioDecoder(AudioDecoder&& other) = default;

	AudioDecoder& operator=(const AudioDecoder& other) = default;
	AudioDecoder& operator=(AudioDecoder&& other) = default;

	virtual ~AudioDecoder() = default;

private:
};

} // namespace MY

#endif // MY_AUDIO_DECODER_H

