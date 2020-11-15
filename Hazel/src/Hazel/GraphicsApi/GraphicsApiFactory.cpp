#include "GraphicsApiFactory.h"

#include "Platform/OpenGL/GraphicsApi/OpenGL.h"

namespace Hazel
{
	std::shared_ptr<GraphicsApi> GraphicsApiFactory::CreateOpenGLInstance()
	{
		return std::make_shared<OpenGL>();
	}
}