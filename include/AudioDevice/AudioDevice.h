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

private:
};

} // namespace MY

#endif // MY_AUDIO_DEVICE_H

