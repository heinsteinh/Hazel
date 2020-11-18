#include "OpenGL.h"

#include "OpenGLGraphicsContext.h"

namespace Hazel
{
	std::shared_ptr<GraphicsContext> OpenGL::CreateContext(GLFWwindow *window)
	{
		return std::make_shared<OpenGLGraphicsContext>(window);
	}
}