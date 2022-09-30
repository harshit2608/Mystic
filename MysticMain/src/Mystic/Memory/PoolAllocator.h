#pragma once

#include "Mystic/Core/Base.h"
#include "Systems/Configuration.h"

namespace Mystic
{
	// Multiple Chunks makeup  a block
	// Chunk is the smallest unit in the PoolAllocator
	struct Chunk
	{
		Chunk *next;
	};

	class PoolAllocator
	{
	public:
		PoolAllocator() = default;
		PoolAllocator(size_t chunksPerBlock) : m_ChunksPerBlock(chunksPerBlock) {}

		void Init(Config &configVals);
		void *allocate(size_t size);
		void deallocate(void *ptr);
		void deallocate(void *ptr, size_t size);
		void ResetPool();

	private:
		size_t m_ChunksPerBlock;
		Chunk *m_Alloc = nullptr;
		Chunk *allocateBlock(size_t chunkSize);
	};
} // namespace Mystic
