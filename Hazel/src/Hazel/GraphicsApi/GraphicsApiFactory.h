#pragma once

#include "GraphicsApi.h"

namespace Hazel
{
	class GraphicsApiFactory
	{
	public:
		static std::shared_ptr<GraphicsApi> CreateOpenGLInstance();
	};
}