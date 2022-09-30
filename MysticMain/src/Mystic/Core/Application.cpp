#include "mcpch.h"

#include "Mystic/Core/Application.h"

namespace Mystic
{
	Application::Application()
	{
	}

	void Application::Run()
	{
		int i = 0;
		for (int i = 0; i < 4; ++i)
		{
			void *test = new int[2];
		}

		MemoryAllocator::Print();
		MemoryAllocator::ResetPool();
		MC_CORE_WARN("POOL RESET", false)

		for (int i = 0; i < 4; ++i)
		{
			void *test = new double[3];
		}
		MemoryAllocator::Print();

		MC_CORE_INFO("test %d", i);

		while (m_Running)
		{
		}
		MC_CORE_INFO("Game Loop Terminated", true);
	}
} // namespace Mystic
