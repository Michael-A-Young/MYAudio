/**
@file
	XAudio2Device.h
@brief
	Windows audio playback using XAudio2.
*/

#ifndef MY_XAUDIO2_DEVICE_H
#define MY_XAUDIO2_DEVICE_H

// MYAudio
#include "AudioDevice.h"

namespace MY
{

class XAudio2Device : public AudioDevice
{
public:
	XAudio2Device();

	XAudio2Device(const XAudio2Device& other) = default;
	XAudio2Device(XAudio2Device&& other) = default;

	XAudio2Device& operator=(const XAudio2Device& other) = default;
	XAudio2Device& operator=(XAudio2Device&& other) = default;

	~XAudio2Device() override = default;

public:
	void Initialise() override;
	void Shutdown() override;

	DeviceVoice* CreateVoice() override;
	bool SubmitBuffer() override;

	bool Start() override;
	bool Stop() override;
	bool Pause() override;

	void SetVolume(float volume) override;
	void SetPitch(float pitch) override;

private:
};

} // namespace MY

#endif // MY_XAUDIO2_DEVICE_H

