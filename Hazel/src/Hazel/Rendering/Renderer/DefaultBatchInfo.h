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
			return {factory, 40000, 10000, 48, Vertex::Layout};
		}

		DefaultBatchInfo() = delete;
	};
}