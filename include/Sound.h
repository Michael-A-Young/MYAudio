/**
@file
	Sound.h
@brief
	A reusable audio asset.
*/

#ifndef MY_SOUND_H
#define MY_SOUND_H

namespace MY
{

class Sound
{
public:
	Sound();

	Sound(const Sound& other) = default;
	Sound(Sound&& other) = default;

	Sound& operator=(const Sound& other) = default;
	Sound& operator=(Sound&& other) = default;

	~Sound() = default;

private:
};

} // namespace MY

#endif // MY_SOUND_H


