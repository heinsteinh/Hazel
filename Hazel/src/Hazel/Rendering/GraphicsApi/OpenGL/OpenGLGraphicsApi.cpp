#include "OpenGLGraphicsApi.h"

#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLGraphicsContext.h"

namespace Hazel
{
	std::shared_ptr<GraphicsContext> OpenGLGraphicsApi::CreateContext(GLFWwindow *window)
	{
		return std::make_shared<OpenGLGraphicsContext>(window);
	}
}