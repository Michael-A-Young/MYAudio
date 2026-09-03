/**
@file
	Channel.cpp
@brief
	A logical instance of a sound playback.
*/

// MYAudio
#include "Channel.h"

namespace MY
{

Channel::Channel()
	: mVolume(1.0f)
	, mMuted(false)
	, mPitch(1.0)
	, mLooping(false)
	, mFrame(0)
	, mBus({})
{
}

void Channel::Play(SoundHandle sound)
{
}

void Channel::Pause()
{
}

void Channel::Resume()
{
}

void Channel::Stop()
{
}

void Channel::Restart()
{
}

void Channel::SetVolume(float volume)
{
	mVolume = volume;
}

void Channel::SetMuted(bool muted)
{
	mMuted = muted;
}

void Channel::SetPitch(float pitch)
{
	mPitch = pitch;
}

void Channel::SetLooping(bool looping)
{
	mLooping = looping;
}

void Channel::SetFrame(uint32_t frame)
{
	mFrame = frame;
}

float Channel::GetVolume() const
{
	return mVolume;
}

bool Channel::IsMuted() const
{
	return mMuted;
}

float Channel::GetPitch() const
{
	return mPitch;
}

bool Channel::IsLooping() const
{
	return mLooping;
}

BusHandle Channel::GetBus() const
{
	return mBus;
}

uint32_t Channel::GetFrame() const
{
	return mFrame;
}

} // namespace MY
