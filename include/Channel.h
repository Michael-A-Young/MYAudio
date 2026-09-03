/**
@file
	Channel.h
@brief
	A logical instance of a sound playback.
*/

#ifndef MY_CHANNEL_H
#define MY_CHANNEL_H

// MYAudio
#include "AudioTypes.h"

// Standard Library
#include <cstdint>

namespace MY
{

class Channel
{
public:
	Channel();

	Channel(const Channel& other) = default;
	Channel(Channel&& other) = default;

	Channel& operator=(const Channel& other) = default;
	Channel& operator=(Channel&& other) = default;

	~Channel() = default;

public:
	void Play(SoundHandle sound);
	void Pause();
	void Resume();
	void Stop();
	void Restart();

	void SetVolume(float volume);
	void SetMuted(bool muted);
	void SetPitch(float pitch);
	void SetLooping(bool looping);
	void SetFrame(uint32_t frame);

	float GetVolume() const;
	bool IsMuted() const;
	float GetPitch() const;
	bool IsLooping() const;
	BusHandle GetBus() const;
	uint32_t GetFrame() const;

private:
	float mVolume;
	bool mMuted;
	float mPitch;
	bool mLooping;
	uint32_t mFrame;
	BusHandle mBus;
};

} // namespace MY

#endif // MY_CHANNEL_H


