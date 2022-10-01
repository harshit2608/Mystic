#pragma once

#include "Mystic/Core/Base.h"
#include <iostream>
namespace Mystic
{
	class MemoryUtils
	{
	public:
		MemoryUtils() = default;

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

		static void WhatsBehindThatPointer(const void* pointer, std::size_t size)
		{
			const std::byte* bytePointer = reinterpret_cast<const std::byte*>(pointer);
			const std::ptrdiff_t pointerInteger =
				reinterpret_cast<std::ptrdiff_t>(pointer);

			int rows = 1;
			if (size > 8)
				rows = size / 8;

			for (int i = 0; i < rows; i++)
			{
				const int rowIndex = i * 8;

				std::cout << "[0x" << std::hex << std::setfill('0')
					<< std::setw(sizeof(void*)) << (pointerInteger + rowIndex)
					<< " ... 0x" << std::hex << std::setfill('0')
					<< std::setw(sizeof(void*)) << (pointerInteger + rowIndex + 7)
					<< "] ";

				for (int j = 0; j < 8; j++)
				{
					const int index = rowIndex + j;
					if (index > size)
						std::cout << "00 ";

					else
						std::cout << std::hex << std::setfill('0') << std::setw(2)
						<< static_cast<const int>(bytePointer[index]) << " ";
				}

				std::cout << std::endl;
			}
		}
	};
} // namespace Mystic
