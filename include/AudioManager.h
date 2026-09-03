/**
@file
	AudioManager.h
@brief
	Main MYAudio interface and coordinator.
*/

#ifndef MY_AUDIO_MANAGER_H
#define MY_AUDIO_MANAGER_H

// MYAudio
#include "AudioDevice/AudioDevice.h"
#include "AudioTypes.h"
#include "BusManager.h"
#include "ChannelManager.h"
#include "SoundManager.h"

// Standard Library
#include <cstdint>

namespace MY
{

class AudioManager
{
public:
	AudioManager();

	AudioManager(const AudioManager& other) = default;
	AudioManager(AudioManager&& other) = default;

	AudioManager& operator=(const AudioManager& other) = default;
	AudioManager& operator=(AudioManager&& other) = default;

	~AudioManager() = default;

public:
	// Lifecycle
	void Initialise();
	void Shutdown();

	// Sounds
	SoundHandle Load();
	void Unload(SoundHandle sound);
	void Prime(SoundHandle sound, size_t maxBytes = 0);

	// Channels and playback
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

	// Buses
	BusHandle CreateBus(BusHandle parent);
	void DestroyBus(BusHandle bus);

	void SetVolume(BusHandle bus, float volume);
	void SetMuted(BusHandle bus, bool muted);
	void SetParent(BusHandle bus, BusHandle parent);

	float GetVolume(BusHandle bus) const;
	bool IsMuted(BusHandle bus) const;
	BusHandle GetParent(BusHandle bus) const;

private:
	AudioDevice* mDevice;
	SoundManager mSoundManager;
	ChannelManager mChannelManager;
	BusManager mBusManager;
};

} // namespace MY

#endif // MY_AUDIO_MANAGER_H

