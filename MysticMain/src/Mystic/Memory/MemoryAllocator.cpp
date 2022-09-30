#include "mcpch.h"

#include "Mystic/Memory/MemoryAllocator.h"

namespace Mystic
{
	void MemoryAllocator::Init(std::size_t allocationSize)
	{
		// GetInstance().GetInstance().m_PoolAllocator.Init(allocationSize);
		GetInstance().m_LinearAllcator.Init(allocationSize);
	}

	void MemoryAllocator::Init(Config &vals)
	{
		// GetInstance().GetInstance().m_PoolAllocator.Init(vals);
	}

	void *MemoryAllocator::allocate(std::size_t size, std::size_t alignment)
	{
		return GetInstance().m_LinearAllcator.allocate(size, alignment);
	}

	void MemoryAllocator::deallocate(void *ptr)
	{
		GetInstance().m_LinearAllcator.deallocate(ptr);
	}

	void MemoryAllocator::deallocate(void *ptr, size_t size)
	{
		GetInstance().m_LinearAllcator.deallocate(ptr, size);
	}

	MemoryAllocator &MemoryAllocator::GetInstance()
	{
		static MemoryAllocator m_MemoryAllocator;
		return m_MemoryAllocator;
	}

} // namespace Mystic
