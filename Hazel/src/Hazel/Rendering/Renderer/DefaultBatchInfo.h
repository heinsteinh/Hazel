#pragma once

#include "BatchInfo.h"
#include "Vertex.h"

namespace Hazel
{
	class DefaultBatchInfo
	{
	public:
		static inline BatchInfo Create(RenderApiFactory &factory)
		{
			return {factory, 40000, 60000, 32, Vertex::Layout};
		}

		DefaultBatchInfo() = delete;
	};
}