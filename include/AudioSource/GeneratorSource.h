/**
@file
	GeneratorSource.h
@brief
	Generates PCM incrementally during playback.
*/

#ifndef MY_GENERATOR_SOURCE_H
#define MY_GENERATOR_SOURCE_H

#include "AudioSource.h"

namespace MY
{

class GeneratorSource : public AudioSource
{
public:
	GeneratorSource();

	GeneratorSource(const GeneratorSource& other) = default;
	GeneratorSource(GeneratorSource&& other) = default;

	GeneratorSource& operator=(const GeneratorSource& other) = default;
	GeneratorSource& operator=(GeneratorSource&& other) = default;

	~GeneratorSource() override = default;

private:
};

} // namespace MY

#endif // MY_GENERATOR_SOURCE_H

