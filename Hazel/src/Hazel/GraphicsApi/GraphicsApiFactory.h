#pragma once

#include "GraphicsApi.h"
#include "AvailableGraphicsApi.h"

namespace Hazel
{
	class GraphicsApiFactory
	{
	public:
		static std::shared_ptr<GraphicsApi> Create(AvailableGraphicsApi api);
	};
}