#include "GraphicsApiFactory.h"

#include "Platform/OpenGL/GraphicsApi/OpenGL.h"

namespace Hazel
{
	std::shared_ptr<GraphicsApi> GraphicsApiFactory::Create(AvailableGraphicsApi api)
	{
		switch (api)
		{
		case AvailableGraphicsApi::OpenGL:
			return std::make_shared<OpenGL>();
		}
		HZ_ASSERT(false, "Invalid API");
	}
}