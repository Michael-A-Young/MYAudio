/**
@file
	SoundManager.h
@brief
	Manages audio assets.
*/

#ifndef MY_SOUND_MANAGER_H
#define MY_SOUND_MANAGER_H

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

private:
};

} // namespace MY

#endif // MY_SOUND_MANAGER_H


