#include "GraphicsApiFactory.h"

#include "OpenGL/OpenGL.h"
#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	std::unique_ptr<GraphicsApi> GraphicsApiFactory::Create(AvailableGraphicsApi graphicsApi)
	{
		switch (graphicsApi)
		{
		case AvailableGraphicsApi::OpenGL:
			return std::make_unique<OpenGL>();
		}
		HZ_ASSERT(false, "Invalid API");
	}
}