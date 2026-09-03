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

// PipeWire
#include "pipewire/pipewire.h"

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

public:
	struct PipeWireData
	{
        struct pw_main_loop* loop;
        struct pw_stream* stream;
        double accumulator;
	};

private:
	static constexpr size_t kBufferSize = 1024;
	static constexpr uint32_t kDefaultChannels = 2;
	static constexpr uint32_t kDefaultRate = 44100;

	PipeWireData mData;
	pw_stream_events mStreamEvents;
};

} // namespace MY

#endif // MY_PIPEWIRE_DEVICE_H

