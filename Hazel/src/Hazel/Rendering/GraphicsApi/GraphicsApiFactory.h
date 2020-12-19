#pragma once

#include "AvailableGraphicsApi.h"
#include "GraphicsApi.h"

namespace Hazel
{
	class GraphicsApiFactory
	{
	public:
		static std::shared_ptr<GraphicsApi> Create(AvailableGraphicsApi graphicsApi);
	};
}