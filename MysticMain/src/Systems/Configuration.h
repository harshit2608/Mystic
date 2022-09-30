#pragma once

#include "Mystic/Core/Base.h"

namespace Mystic
{
	struct Config
	{
		size_t ChunkSize;
		size_t TotalChunks;
		size_t TotalSize;
	};

	class MC_API Configuration
	{
	public:
		static bool ReadConfig();
		static bool ReadConfig(const std::string &filepath);

	private:
		static bool Deserialize(const std::string &filepath);
	};
} // namespace Mystic
