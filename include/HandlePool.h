/**
@file
	HandlePool.h
@brief
	Manages a generational pool of resources via handles.
*/

#ifndef MY_HANDLE_POOL_H
#define MY_HANDLE_POOL_H

// Standard Library
#include <cstdint>
#include <optional>
#include <vector>

namespace MY
{

template <typename Resource, typename Handle>
class HandlePool
{
public:
	HandlePool(size_t initialCapacity);

	HandlePool(const HandlePool& other) = default;
	HandlePool(HandlePool&& other) = default;

	HandlePool& operator=(const HandlePool& other) = default;
	HandlePool& operator=(HandlePool&& other) = default;

	~HandlePool() = default;

public:
	const Resource* Get(Handle handle) const;
	Resource* Get(Handle handle);

	template <typename... Args>
	Handle Create(Args&&... args);
	void Remove(Handle handle);

	bool IsValid(Handle handle);

private:
	struct Slot
	{
		std::optional<Resource> resource;
		uint32_t generation;
	};

private:
	std::vector<Slot> mSlots;
	std::vector<uint32_t> mFreeIndices;
};

} // namespace MY

#include "HandlePool.inl"

#endif // MY_HANDLE_POOL_H

