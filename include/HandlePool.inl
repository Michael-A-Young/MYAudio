/**
@file
	HandlePool.inl
@brief
	Manages a generational pool of resources via handles.
*/

namespace MY
{

template <typename Resource, typename Handle>
HandlePool<Resource, Handle>::HandlePool(size_t initialCapacity)
	: mSlots()
	, mFreeIndices()
{
	mSlots.reserve(initialCapacity);
	mFreeIndices.reserve(initialCapacity);
}

template <typename Resource, typename Handle>
const Resource* HandlePool<Resource, Handle>::Get(Handle handle) const
{
	Resource* output = nullptr;

	if (IsValid(handle))
	{
		output = &mSlots[handle.index].resource.value();
	}

	return output;
}

template <typename Resource, typename Handle>
Resource* HandlePool<Resource, Handle>::Get(Handle handle)
{
	Resource* output = nullptr;

	if (IsValid(handle))
	{
		output = &mSlots[handle.index].resource.value();
	}

	return output;
}

template <typename Resource, typename Handle>
template <typename... Args>
Handle HandlePool<Resource, Handle>::Create(Args&&... args)
{
	uint32_t index;
	if (mFreeIndices.empty())
	{
		index = mFreeIndices.back();
		mFreeIndices.pop_back();
	}
	else
	{
		index = static_cast<uint32_t>(mSlots.size());
		mSlots.emplace_back(std::nullopt, 0);
	}

	Slot& slot = mSlots[index];
	slot.resource.emplace(std::forward<Args>(args)...);
	slot.generation++;

	return Handle
	{
		.index = index,
		.generation = slot.generation
	};
}

template <typename Resource, typename Handle>
void HandlePool<Resource, Handle>::Remove(Handle handle)
{
	MY_ASSERT(IsValid(handle), "Trying to remove invalid handle.");

	mSlots[handle.index].resource.reset();
	mFreeIndices.push_back(handle.index);
}

template <typename Resource, typename Handle>
bool HandlePool<Resource, Handle>::IsValid(Handle handle)
{
	MY_ASSERT(handle.index < mSlots.size(),
			  "Trying to access beyond bounds of pool {}/{}",
			  handle.index, mSlots.size());

	const Slot& slot = mSlots[handle.index];
	return (slot.resource.has_value() &&
			slot.generation == handle.generation);
}

} // namespace MY

