/**
@file
	HandlePool.h
@brief
	Manages a pool of resources via handles.
*/

#ifndef MY_HANDLE_POOL_H
#define MY_HANDLE_POOL_H

// Standard Library
#include <vector>

namespace MY
{

template <typename Resource, typename Handle>
class HandlePool
{
public:
	HandlePool();

	HandlePool(const HandlePool& other) = default;
	HandlePool(HandlePool&& other) = default;

	HandlePool& operator=(const HandlePool& other) = default;
	HandlePool& operator=(HandlePool&& other) = default;

	~HandlePool() = default;

public:
	Resource Get(Handle handle);
	Handle Store(Resource resource);

	bool IsValid(Handle handle);

private:
	struct Slot
	{
		Resource resource;
		uint32_t generation;
		bool valid;
	};

private:
	std::vector<Slot> mData;
};

} // namespace MY

#include "HandlePool.inl"

#endif // MY_HANDLE_POOL_H

