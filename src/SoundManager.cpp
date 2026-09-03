/**
@file
	SoundManager.cpp
@brief
	Manages audio assets.
*/

// MYAudio
#include "SoundManager.h"

namespace MY
{

SoundManager::SoundManager()
	: mSoundPool()
{
}

SoundHandle SoundManager::Load()
{
	return {};
}

void SoundManager::Unload(SoundHandle sound)
{
}

void SoundManager::Prime(SoundHandle sound, size_t maxBytes)
{
}

bool SoundManager::IsLoaded(SoundHandle sound) const
{
	return false;
}

} // namespace MY
