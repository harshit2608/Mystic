#pragma once

#include "Mystic/Core/Application.h"
#include "Mystic/Memory/MemoryAllocator.h"
#include "Mystic/Log/Log.h"

#include "Utils/MemoryUtils.h"

extern Mystic::Application *Mystic::CreateApplication();

// TODO: Clean Up the Entry Main.h
// FIXME: Overriding new and delete throws segmentation fault
void *operator new(std::size_t size)
{
	printf("%zu\n", size);
	return Mystic::MemoryAllocator::allocate(size);
}

void *operator new[](std::size_t size)
{
	printf("Insidenew arry %zu\n", size);
	return Mystic::MemoryAllocator::allocate(size);
}

void operator delete(void *ptr) noexcept
{
	Mystic::MemoryAllocator::deallocate(ptr);
}

// TODO: Handle gracefull shutdown of the application

int main(int argc, const char **argv)
{
	Mystic::Log::Init();

	std::size_t memoryToAllocate = Mystic::MemoryUtils::ConvertToBytes("128B");
	Mystic::MemoryAllocator::Init(memoryToAllocate);

	Mystic::Application *app = Mystic::CreateApplication();
	app->Run();
	delete app;
	return EXIT_SUCCESS;
}