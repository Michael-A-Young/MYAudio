/**
@file
	XAudio2Device.cpp
@brief
	Windows audio playback using XAudio2.
*/

// MYAudio
#include "AudioDevice/XAudio2Device.h"

namespace MY
{

XAudio2Device::XAudio2Device()
	: AudioDevice()
{
}

void XAudio2Device::Initialise()
{
}

void XAudio2Device::Shutdown()
{
}

DeviceVoice* XAudio2Device::CreateVoice()
{
	return nullptr;
}

bool XAudio2Device::SubmitBuffer()
{
	return false;
}

bool XAudio2Device::Start()
{
	return false;
}

bool XAudio2Device::Stop()
{
	return false;
}

bool XAudio2Device::Pause()
{
	return false;
}

void XAudio2Device::SetVolume(float volume)
{
}

void XAudio2Device::SetPitch(float pitch)
{
}

} // namespace MY
