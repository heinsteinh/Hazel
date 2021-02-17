#include "GraphicsApiFactory.h"

#include "OpenGL/OpenGLGraphicsApi.h"
#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	std::unique_ptr<GraphicsApi> GraphicsApiFactory::CreateApi(AvailableGraphicsApi graphicsApi)
	{
		switch (graphicsApi)
		{
		case AvailableGraphicsApi::OpenGL:
			return std::make_unique<OpenGLGraphicsApi>();
		}
		HZ_ASSERT(false, "Invalid API");
		return nullptr;
	}
}