#pragma once

#include "Mystic/Core/Base.h"
#include <iostream>
namespace Mystic
{
	class MemoryUtils
	{
	public:
		MemoryUtils() {}

		static const std::size_t ConvertToBytes(const std::string &memorySize)
		{
			const char *mem = memorySize.c_str();
			int length = memorySize.size();
			char unit = mem[length - 1];

			std::string number = memorySize;
			number.pop_back();
			double num = std::stod(number);

			switch (unit)
			{
			case 'G':
				return 1024 * 1024 * 1024 * num;
				break;
			case 'M':
				return 1024 * 1024 * num;
				break;
			case 'K':
				return 1024 * num;
			default:
				return num;
				break;
			}
		}
	};
} // namespace Mystic
