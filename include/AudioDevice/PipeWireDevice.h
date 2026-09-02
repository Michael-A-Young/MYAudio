/**
@file
	PipeWireDevice.h
@brief
	Linux audio playback using PipeWire.
*/

#ifndef MY_PIPEWIRE_DEVICE_H
#define MY_PIPEWIRE_DEVICE_H

// MYAudio
#include "AudioDevice.h"

namespace MY
{

class PipeWireDevice : public AudioDevice
{
public:
	PipeWireDevice();

	PipeWireDevice(const PipeWireDevice& other) = default;
	PipeWireDevice(PipeWireDevice&& other) = default;

	PipeWireDevice& operator=(const PipeWireDevice& other) = default;
	PipeWireDevice& operator=(PipeWireDevice&& other) = default;

	~PipeWireDevice() override = default;

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

#endif // MY_PIPEWIRE_DEVICE_H

