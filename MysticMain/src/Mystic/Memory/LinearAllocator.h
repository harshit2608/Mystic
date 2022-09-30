#pragma once

#include "Mystic/Core/Base.h"

namespace Mystic
{
	class LinearAllocator
	{
	public:
		LinearAllocator() {}
		~LinearAllocator()
		{
		}

		void Init(std::size_t allocationSize);
		void *allocate(std::size_t size, std::size_t alignment);
		void deallocate(void *ptr);
		void deallocate(void *ptr, std::size_t size);
		void FreePool();
		void ResetPool();
		void Print();

	private:
		LinearAllocator(LinearAllocator &other) = delete;

		std::size_t alignMemory(std::size_t currentAddress, std::size_t alignment);

	private:
		void *m_StartPtr = nullptr;
		std::size_t m_Offset;
		std::size_t m_TotalSize;
	};
} // namespace Mystic
