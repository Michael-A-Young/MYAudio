/**
@file
	AudioDevice.h
@brief
	Abstraction for platform-specific audio playback.
*/

#ifndef MY_AUDIO_DEVICE_H
#define MY_AUDIO_DEVICE_H

namespace MY
{

class AudioDevice
{
public:
	AudioDevice();

	AudioDevice(const AudioDevice& other) = default;
	AudioDevice(AudioDevice&& other) = default;

	AudioDevice& operator=(const AudioDevice& other) = default;
	AudioDevice& operator=(AudioDevice&& other) = default;

	virtual ~AudioDevice() = default;

public:
	virtual void Initialise() = 0;
	virtual void Shutdown() = 0;

	virtual DeviceVoice* CreateVoice(); = 0;
	virtual bool SubmitBuffer() = 0;

	virtual void Start() = 0;
	virtual void Stop() = 0;
	virtual void Pause() = 0;

	virtual void SetVolume(float volume) = 0;
	virtual void SetPitch(float pitch) = 0;

private:
};

} // namespace MY

#endif // MY_AUDIO_DEVICE_H

