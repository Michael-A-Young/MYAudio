/**
@file
	SoundManager.h
@brief
	Manages audio assets.
*/

#ifndef MY_SOUND_MANAGER_H
#define MY_SOUND_MANAGER_H

// MYAudio
#include "AudioTypes.h"
#include "HandlePool.h"
#include "Sound.h"

namespace MY
{

class SoundManager
{
public:
	SoundManager();

	SoundManager(const SoundManager& other) = default;
	SoundManager(SoundManager&& other) = default;

	SoundManager& operator=(const SoundManager& other) = default;
	SoundManager& operator=(SoundManager&& other) = default;

	~SoundManager() = default;

public:
	SoundHandle Load();
	void Unload(SoundHandle sound);
	void Prime(SoundHandle sound, size_t maxBytes = 0);

	bool IsLoaded(SoundHandle sound) const;

private:
	HandlePool<Sound, SoundHandle> mSoundPool;
};

} // namespace MY

#endif // MY_SOUND_MANAGER_H


