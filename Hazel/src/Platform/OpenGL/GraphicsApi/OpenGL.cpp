#include "OpenGL.h"

#include "glad/glad.h"

#include "Platform/OpenGL/GraphicsContext/OpenGLGraphicsContext.h"
#include "Helpers/OpenGLLoader.h"

namespace Hazel
{
	std::shared_ptr<GraphicsContext> OpenGL::CreateContext(GLFWwindow *window)
	{
		auto result = std::make_shared<OpenGLGraphicsContext>(window);
		static OpenGLLoader loader;
		return result;
	}
}