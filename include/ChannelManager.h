/**
@file
	ChannelManager.h
@brief
	Manages individual playbacks.
*/

#ifndef MY_CHANNEL_MANAGER_H
#define MY_CHANNEL_MANAGER_H

namespace MY
{

class ChannelManager
{
public:
	ChannelManager();

	ChannelManager(const ChannelManager& other) = default;
	ChannelManager(ChannelManager&& other) = default;

	ChannelManager& operator=(const ChannelManager& other) = default;
	ChannelManager& operator=(ChannelManager&& other) = default;

	~ChannelManager() = default;

private:
};

} // namespace MY

#endif // MY_CHANNEL_MANAGER_H


