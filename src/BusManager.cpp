/**
@file
	BusManager.cpp
@brief
	Manages bus hierarchy and the routing graph.
*/

// MYAudio
#include "BusManager.h"

namespace MY
{

BusManager::BusManager()
	: mBusPool()
{
}

void BusManager::Initialise()
{
	CreateMasterBus();
}

BusHandle BusManager::CreateBus(BusHandle parent)
{
	return {};
}

void BusManager::DestroyBus(BusHandle bus)
{
}

void BusManager::SetVolume(BusHandle bus, float volume)
{
}

void BusManager::SetMuted(BusHandle bus, bool muted)
{
}

void BusManager::SetParent(BusHandle bus, BusHandle parent)
{
}

float BusManager::GetVolume(BusHandle bus) const
{
	return 0.0f;
}

bool BusManager::IsMuted(BusHandle bus) const
{
	return false;
}

BusHandle BusManager::GetParent(BusHandle bus) const
{
	return {};
}

bool BusManager::IsValid(BusHandle bus) const
{
	return false;
}

void BusManager::CreateMasterBus()
{
}

} // namespace MY
