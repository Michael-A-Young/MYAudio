/**
@file
	AudioManager.h
@brief
	Main MYAudio interface and coordinator.
*/

#ifndef MY_AUDIO_MANAGER_H
#define MY_AUDIO_MANAGER_H

namespace MY
{

class AudioManager
{
public:
	AudioManager();

	AudioManager(const AudioManager& other) = default;
	AudioManager(AudioManager&& other) = default;

	AudioManager& operator=(const AudioManager& other) = default;
	AudioManager& operator=(AudioManager&& other) = default;

	~AudioManager() = default;

private:
};

} // namespace MY

#endif // MY_AUDIO_MANAGER_H

