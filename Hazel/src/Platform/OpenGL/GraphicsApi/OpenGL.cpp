#include "OpenGL.h"

#include "Platform/OpenGL/GraphicsContext/OpenGLGraphicsContext.h"

namespace Hazel
{
	std::shared_ptr<GraphicsContext> OpenGL::CreateContext(GLFWwindow *window)
	{
		return std::make_shared<OpenGLGraphicsContext>(window);
	}
}