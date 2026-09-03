/**
@file
	AudioTypes.h
@brief
	Common types used across MYAudio.
*/

#ifndef MY_AUDIO_TYPES_H
#define MY_AUDIO_TYPES_H

// Standard Library
#include <cstdint>

namespace MY
{

struct SoundHandle
{
	uint32_t index;
	uint32_t generation;
};

struct ChannelHandle
{
	uint32_t index;
	uint32_t generation;
};

struct BusHandle
{
	uint32_t index;
	uint32_t generation;
};

} // namespace MY

#endif // MY_AUDIO_TYPES_H

