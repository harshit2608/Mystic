#include "mcpch.h"

#include "Mystic/Core/Application.h"

#include <iostream>
namespace Mystic
{
	Application::Application()
	{
	}

	void Application::Run()
	{
		int idx = 0;
		for (int i = 0; i < 4; ++i)
		{
			int *test = new int(90);
		}

		MemoryAllocator::Print();
		MemoryAllocator::ResetPool();
		MC_CORE_WARN("POOL RESET", false)

		for (int i = 0; i < 2; ++i)
		{
			double *test = new double[2];
		}
		MemoryAllocator::ResetPool();

		float *bie = new float[2];
		bie[0] = 1.2f;
		std::cout << "value hain " << bie[0];

		MemoryAllocator::Print();

		MC_CORE_INFO("test %d", idx);

		while (m_Running)
		{
			idx++;
		}
		MC_CORE_INFO("Game Loop Terminated", true);
	}
} // namespace Mystic
