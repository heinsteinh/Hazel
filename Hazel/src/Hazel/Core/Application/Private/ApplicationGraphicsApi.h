#pragma once

#include "Hazel/Core/Application/AvailableGraphicsApi.h"
#include "Hazel/Core/Exceptions/AssertionException.h"
#include "Hazel/Rendering/GraphicsApi/OpenGL/OpenGLGraphicsApi.h"

namespace Hazel
{
	class ApplicationGraphicsApi
	{
	public:
		static std::unique_ptr<GraphicsApi> Create(AvailableGraphicsApi graphicsApi)
		{
			switch (graphicsApi)
			{
			case AvailableGraphicsApi::OpenGL:
				return std::make_unique<OpenGLGraphicsApi>();
			}
			HZ_ASSERT(false, "Invalid API");
			return nullptr;
		}
	};
}