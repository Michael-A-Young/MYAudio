/**
@file
	HandlePool.inl
@brief
	Manages a pool of resources via handles.
*/

namespace MY
{

template <typename Resource, typename Handle>
HandlePool<Resource, Handle>::HandlePool()
	: mData()
{
}

template <typename Resource, typename Handle>
Resource HandlePool<Resource, Handle>::Get(Handle handle)
{
	return {};
}

template <typename Resource, typename Handle>
Handle HandlePool<Resource, Handle>::Store(Resource resource)
{
	return {};
}

template <typename Resource, typename Handle>
bool HandlePool<Resource, Handle>::IsValid(Handle handle)
{
	return false;
}

} // namespace MY

