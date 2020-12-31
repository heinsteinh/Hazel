#pragma once

#include "AvailableGraphicsApi.h"
#include "GraphicsApi.h"

namespace Hazel
{
	class GraphicsApiFactory
	{
	public:
		static std::unique_ptr<GraphicsApi> Create(AvailableGraphicsApi graphicsApi);
	};
}