#pragma once

#include "Mystic/Core/Base.h"
#include "Mystic/Memory/MemoryAllocator.h"

int main(int argc, const char **argv);

// void *operator new(std::size_t size)
// {
// 	return Mystic::MemoryAllocator::allocate(size);
// }

// void operator delete(void *ptr) noexcept
// {
// 	Mystic::MemoryAllocator::deallocate(ptr);
// }

namespace Mystic
{
	class MC_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

	private:
		void Run();

	private:
		bool m_Running = true;
		friend int ::main(int argc, const char **argv);
	};

	Application *CreateApplication();
} // namespace Mystic
