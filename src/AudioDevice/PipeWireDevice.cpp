/**
@file
	PipeWireDevice.cpp
@brief
	Linux audio playback using PipeWire.
*/

// MYAudio
#include "AudioDevice/PipeWireDevice.h"

// PipeWire
#include <pipewire/pipewire.h>

namespace MY
{

PipeWireDevice::PipeWireDevice()
	: AudioDevice()
{
}

void PipeWireDevice::Initialise()
{
	pw_init(nullptr, nullptr);

	MY_LOG("Initialised PipeWire\n"
			"Compiled PipeWire {}\n"
			"Linked PipeWire {}",
			pw_get_headers_version(),
			pw_get_library_version());
}

void PipeWireDevice::Shutdown()
{
}

DeviceVoice* PipeWireDevice::CreateVoice()
{
	return nullptr;
}

bool PipeWireDevice::SubmitBuffer()
{
	return false;
}

bool PipeWireDevice::Start()
{
	return false;
}

bool PipeWireDevice::Stop()
{
	return false;
}

bool PipeWireDevice::Pause()
{
	return false;
}

void PipeWireDevice::SetVolume(float /*volume*/)
{
}

void PipeWireDevice::SetPitch(float /*pitch*/)
{
}

} // namespace MY
