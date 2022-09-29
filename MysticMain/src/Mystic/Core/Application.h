#pragma once

#include "Mystic/Core/Base.h"

int main(int argc, const char **argv);

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
