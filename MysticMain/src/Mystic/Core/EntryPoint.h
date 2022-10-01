#pragma once

#include "Mystic/Core/Application.h"
#include "Mystic/Log/Log.h"
#include "Mystic/Memory/MemoryAllocator.h"
#include "Mystic/Memory/InBuiltOverrides.h"
#include "Systems/Configuration.h"

#include "Utils/MemoryUtils.h"

extern Mystic::Application *Mystic::CreateApplication();

// FIXME: Overriding new and delete throws segmentation fault
// TODO: Handle gracefull shutdown of the application

int main(int argc, const char **argv)
{
	Mystic::Log::Init();

	std::size_t memoryToAllocate = Mystic::MemoryUtils::ConvertToBytes("128B");
	Mystic::MemoryAllocator::Init(memoryToAllocate);

	//Mystic::Configuration::ReadConfig(); // TODO : YAML throws error on msvc regarding dll

	Mystic::Application *app = Mystic::CreateApplication();
	app->Run();
	delete app;
	return EXIT_SUCCESS;
}