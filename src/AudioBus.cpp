/**
@file
	AudioBus.cpp
@brief
	A point in the audio mixing graph.
*/

// MYAudio
#include "AudioBus.h"

namespace MY
{

AudioBus::AudioBus()
	: mParent(nullptr)
	, mVolume(1.0f)
	, mMuted(false)
{
}

void AudioBus::SetVolume(float volume)
{
	mVolume = volume;
}

void AudioBus::SetMuted(bool muted)
{
	mMuted = muted;
}

void AudioBus::SetParent(AudioBus* parent)
{
	mParent = parent;
}

float AudioBus::GetVolume() const
{
	return mVolume;
}

bool AudioBus::IsMuted() const
{
	return mMuted;
}

AudioBus* AudioBus::GetParent() const
{
	return mParent;
}

} // namespace MY
