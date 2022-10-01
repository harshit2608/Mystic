#pragma once

#include "Mystic/Memory/MemoryAllocator.h"

void* operator new(std::size_t size)
{
	printf("%zu\n", size);
	return Mystic::MemoryAllocator::allocate(size);
}

void* operator new[](std::size_t size)
{
	printf("Inside new array %zu\n", size);
	return Mystic::MemoryAllocator::allocate(size);
}

void operator delete(void* ptr) noexcept
{
	Mystic::MemoryAllocator::deallocate(ptr);
}

void operator delete(void* ptr, std::size_t size) noexcept
{
	Mystic::MemoryAllocator::deallocate(ptr, size);
}