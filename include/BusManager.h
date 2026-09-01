/**
@file
	BusManager.h
@brief
	Manages bus hierarchy and the routing graph.
*/

#ifndef MY_BUS_MANAGER_H
#define MY_BUS_MANAGER_H

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

private:
};

} // namespace MY

#endif // MY_BUS_MANAGER_H

