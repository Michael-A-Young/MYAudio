/**
@file
	Channel.h
@brief
	A logical instance of a sound playback.
*/

#ifndef MY_CHANNEL_H
#define MY_CHANNEL_H

namespace MY
{

class Channel
{
public:
	Channel();

	Channel(const Channel& other) = default;
	Channel(Channel&& other) = default;

	Channel& operator=(const Channel& other) = default;
	Channel& operator=(Channel&& other) = default;

	~Channel() = default;

private:
};

} // namespace MY

#endif // MY_CHANNEL_H


