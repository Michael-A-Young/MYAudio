/**
@file
	AudioManager.cpp
@brief
	Main MYAudio interface and coordinator.
*/

// MYAudio
#include "AudioManager.h"

namespace MY
{

AudioManager::AudioManager()
	: mDevice()
	, mMixer()
	, mSoundManager()
	, mChannelManager()
	, mBusManager()
{
}

void AudioManager::Initialise()
{
	mDevice->Initialise();
}

void AudioManager::Shutdown()
{
	mDevice->Shutdown();
}

SoundHandle AudioManager::Load()
{
	return {};
}

void AudioManager::Unload(SoundHandle sound)
{
}

void AudioManager::Prime(SoundHandle sound, size_t maxBytes)
{
}

ChannelHandle AudioManager::Play(SoundHandle sound)
{
	return {};
}

void AudioManager::Pause(ChannelHandle channel)
{
}

void AudioManager::Resume(ChannelHandle channel)
{
}

void AudioManager::Stop(ChannelHandle channel)
{
}

void AudioManager::Restart(ChannelHandle channel)
{
}

void AudioManager::SetVolume(ChannelHandle channel, float volume)
{
}

void AudioManager::SetMuted(ChannelHandle channel, bool muted)
{
}

void AudioManager::SetPitch(ChannelHandle channel, float pitch)
{
}

void AudioManager::SetLooping(ChannelHandle channel, bool looping)
{
}

void AudioManager::SetBus(ChannelHandle channel, BusHandle bus)
{
}

void AudioManager::SetFrame(ChannelHandle channel, uint32_t frame)
{
}

float AudioManager::GetVolume(ChannelHandle channel) const
{
	return 0.0f;
}

bool AudioManager::IsMuted(ChannelHandle channel) const
{
	return false;
}

float AudioManager::GetPitch(ChannelHandle channel) const
{
	return 0.0f;
}

bool AudioManager::IsLooping(ChannelHandle channel) const
{
	return false;
}

BusHandle AudioManager::GetBus(ChannelHandle channel) const
{
	return {};
}

uint32_t AudioManager::GetFrame(ChannelHandle channel) const
{
	return 0;
}

BusHandle AudioManager::CreateBus(BusHandle parent)
{
	return {};
}

void AudioManager::DestroyBus(BusHandle bus)
{
}

void AudioManager::SetVolume(BusHandle bus, float volume)
{
}

void AudioManager::SetMuted(BusHandle bus, bool muted)
{
}

void AudioManager::SetParent(BusHandle bus, BusHandle parent)
{
}

float AudioManager::GetVolume(BusHandle bus) const
{
	return 0.0f;
}

bool AudioManager::IsMuted(BusHandle bus) const
{
	return false;
}

BusHandle AudioManager::GetParent(BusHandle bus) const
{
	return {};
}

} // namespace MY
