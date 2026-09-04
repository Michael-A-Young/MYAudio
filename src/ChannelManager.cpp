/**
@file
	ChannelManager.cpp
@brief
	Manages individual playbacks.
*/

// MYAudio
#include "ChannelManager.h"

namespace MY
{

ChannelManager::ChannelManager()
	: mChannelPool(kInitialMaxChannels)
{
}

ChannelHandle ChannelManager::Play(SoundHandle sound)
{
	return {};
}

void ChannelManager::Pause(ChannelHandle channel)
{
}

void ChannelManager::Resume(ChannelHandle channel)
{
}

void ChannelManager::Stop(ChannelHandle channel)
{
}

void ChannelManager::Restart(ChannelHandle channel)
{
}

void ChannelManager::SetVolume(ChannelHandle channel, float volume)
{
}

void ChannelManager::SetMuted(ChannelHandle channel, bool muted)
{
}

void ChannelManager::SetPitch(ChannelHandle channel, float pitch)
{
}

void ChannelManager::SetLooping(ChannelHandle channel, bool looping)
{
}

void ChannelManager::SetBus(ChannelHandle channel, BusHandle bus)
{
}

void ChannelManager::SetFrame(ChannelHandle channel, uint32_t frame)
{
}

float ChannelManager::GetVolume(ChannelHandle channel) const
{
	return 1.0f;
}

bool ChannelManager::IsMuted(ChannelHandle channel) const
{
	return false;
}

float ChannelManager::GetPitch(ChannelHandle channel) const
{
	return 1.0f;
}

bool ChannelManager::IsLooping(ChannelHandle channel) const
{
	return false;
}

BusHandle ChannelManager::GetBus(ChannelHandle channel) const
{
	return {};
}

uint32_t ChannelManager::GetFrame(ChannelHandle channel) const
{
	return 0;
}

bool ChannelManager::IsValid(ChannelHandle channel) const
{
	return false;
}

} // namespace MY
