#include "mcpch.h"

#include "Mystic/Memory/LinearAllocator.h"

#include <iostream>
#include <iomanip>

namespace Mystic
{
	void WhatsBehindThatPointer(const void *pointer, std::size_t size)
	{
		const std::byte *bytePointer = reinterpret_cast<const std::byte *>(pointer);
		const std::ptrdiff_t pointerInteger =
				reinterpret_cast<std::ptrdiff_t>(pointer);

		int rows = 1;
		if (size > 8)
			rows = size / 8;

		for (int i = 0; i < rows; i++)
		{
			const int rowIndex = i * 8;

			std::cout << "[0x" << std::hex << std::setfill('0')
								<< std::setw(sizeof(void *)) << (pointerInteger + rowIndex)
								<< " ... 0x" << std::hex << std::setfill('0')
								<< std::setw(sizeof(void *)) << (pointerInteger + rowIndex + 7)
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

	static int count = 0;
	void LinearAllocator::Init(std::size_t allocationSize)
	{
		if (m_StartPtr != nullptr)
		{
			FreePool(); // FIXME: Not Sure
		}
		m_StartPtr = malloc(allocationSize);
		memset(m_StartPtr, 0, allocationSize);
		MC_CORE_INFO("Allocate %zu Bytes in memory.", allocationSize)
		m_Offset = 0;
		m_TotalSize = allocationSize;
		WhatsBehindThatPointer(m_StartPtr, allocationSize);
	}

	std::size_t LinearAllocator::alignMemory(std::size_t baseAddress, std::size_t alignment)
	{
		const std::size_t multiplier = (baseAddress / alignment) + 1;
		const std::size_t alignedAddress = multiplier * alignment;
		const std::size_t padding = alignedAddress - baseAddress;
		return padding;
	}

	void *LinearAllocator::allocate(std::size_t size, std::size_t alignment)
	{
		count++;
		MC_CORE_TRACE("Enter allocate %d time to allocate %zu memory", count, size)

		std::size_t padding = 0;
		const std::size_t currentAddres = m_Offset + (std::size_t)m_StartPtr;
		if (alignment != 0 && m_Offset % alignment != 0)
		{
			std::cout << "Entered alignmen";
			padding = alignMemory(currentAddres, alignment);
		}

		if (m_Offset + size + padding >= m_TotalSize)
		{
			MC_CORE_CRITICAL("Memory Full. Please Allocate More Memory. \n Max Memory allowed : %zu\n Required Memory : %zu Bytes", m_TotalSize, (m_Offset + size + padding) - m_TotalSize);
			return nullptr;
		}

		MC_CORE_TRACE("Current memory address %zu", currentAddres)

		m_Offset += size;
		const std::size_t nextPtr = currentAddres + padding;

		MC_CORE_TRACE("Padding is : %zu Alignment : %zu", padding, alignment)
		MC_CORE_TRACE("Next Address : %zu \n Offset is : %zu", nextPtr, m_Offset)

		return (void *)nextPtr;
	}

	void LinearAllocator::deallocate(void *ptr)
	{
		MC_TRACE("Linear Allocator does not support individual deallocations\n", false)
	}

	void LinearAllocator::deallocate(void *ptr, std::size_t size)
	{
		MC_TRACE("Linear Allocator does not support individual deallocations\n", false)
	}

	void LinearAllocator::ResetPool()
	{
		MC_CORE_WARN("ResetPool Called, current Offset is : %zu", m_Offset)
		m_Offset = 0;
		// memset(m_StartPtr, 0, m_TotalSize); // FIXME: Not sure cause it maight casue perfgormance lag
		MC_CORE_WARN("memory Add : %zu", std::size_t(m_StartPtr))
	}

	void LinearAllocator::FreePool()
	{
		free(m_StartPtr);
		m_StartPtr = nullptr;
	}

	void LinearAllocator::Print()
	{
		using namespace std;
		MC_WARN("PRINTIG HEAP DATA", true)
		std::cout << sizeof(m_StartPtr) << endl;
		std::cout << m_StartPtr << endl;
		cout << &m_StartPtr << endl;
		cout << *&m_StartPtr << endl;
		cout << sizeof(*&m_StartPtr) << endl;

		WhatsBehindThatPointer(m_StartPtr, m_TotalSize);
	}
} // namespace Mystic
