/**
@file
	ChannelManager.h
@brief
	Manages individual playbacks.
*/

#ifndef MY_CHANNEL_MANAGER_H
#define MY_CHANNEL_MANAGER_H

// MYAudio
#include "AudioTypes.h"
#include "Channel.h"
#include "HandlePool.h"

// Standard Library
#include <cstdint>

namespace MY
{

class ChannelManager
{
public:
	ChannelManager();

	ChannelManager(const ChannelManager& other) = default;
	ChannelManager(ChannelManager&& other) = default;

	ChannelManager& operator=(const ChannelManager& other) = default;
	ChannelManager& operator=(ChannelManager&& other) = default;

	~ChannelManager() = default;

public:
	ChannelHandle Play(SoundHandle sound);
	void Pause(ChannelHandle channel);
	void Resume(ChannelHandle channel);
	void Stop(ChannelHandle channel);
	void Restart(ChannelHandle channel);

	void SetVolume(ChannelHandle channel, float volume);
	void SetMuted(ChannelHandle channel, bool muted);
	void SetPitch(ChannelHandle channel, float pitch);
	void SetLooping(ChannelHandle channel, bool looping);
	void SetBus(ChannelHandle channel, BusHandle bus);
	void SetFrame(ChannelHandle channel, uint32_t frame);

	float GetVolume(ChannelHandle channel) const;
	bool IsMuted(ChannelHandle channel) const;
	float GetPitch(ChannelHandle channel) const;
	bool IsLooping(ChannelHandle channel) const;
	BusHandle GetBus(ChannelHandle channel) const;
	uint32_t GetFrame(ChannelHandle channel) const;

	bool IsValid(ChannelHandle channel) const;

private:
	static constexpr size_t kInitialMaxChannels = 16;

	HandlePool<Channel, ChannelHandle> mChannelPool;
};

} // namespace MY

#endif // MY_CHANNEL_MANAGER_H


