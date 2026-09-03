/**
@file
	BusManager.h
@brief
	Manages bus hierarchy and the routing graph.
*/

#ifndef MY_BUS_MANAGER_H
#define MY_BUS_MANAGER_H

// MYAudio
#include "AudioBus.h"
#include "AudioTypes.h"
#include "HandlePool.h"

namespace MY
{

class BusManager
{
public:
	BusManager();

	BusManager(const BusManager& other) = default;
	BusManager(BusManager&& other) = default;

	BusManager& operator=(const BusManager& other) = default;
	BusManager& operator=(BusManager&& other) = default;

	~BusManager() = default;

public:
	void Initialise();

	BusHandle CreateBus(BusHandle parent);
	void DestroyBus(BusHandle bus);

	void SetVolume(BusHandle bus, float volume);
	void SetMuted(BusHandle bus, bool muted);
	void SetParent(BusHandle bus, BusHandle parent);

	float GetVolume(BusHandle bus) const;
	bool IsMuted(BusHandle bus) const;
	BusHandle GetParent(BusHandle bus) const;

	bool IsValid(BusHandle bus) const;

private:
	void CreateMasterBus();

private:
	HandlePool<AudioBus, BusHandle> mBusPool;
};

} // namespace MY

#endif // MY_BUS_MANAGER_H

