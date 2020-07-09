#pragma once

#include "BatchInfo.h"

namespace Hazel
{
	class DefaultBatchInfo
	{
	public:
		static inline BatchInfo Create(RenderApiFactory &factory)
		{
			return {factory, 40000, 60000, 32};
		}

		DefaultBatchInfo() = delete;
	};
}