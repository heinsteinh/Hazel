#include "OpenGL.h"

#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLGraphicsContext.h"

namespace Hazel
{
	std::shared_ptr<GraphicsContext> OpenGL::CreateContext(GLFWwindow *window)
	{
		return std::make_shared<OpenGLGraphicsContext>(window);
	}
}