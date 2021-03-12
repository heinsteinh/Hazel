#include "OpenGLGraphicsApi.h"

#include "GLFW/glfw3.h"

#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLGraphicsContext.h"

namespace Hazel
{
	std::unique_ptr<Window> OpenGLGraphicsApi::CreateNewWindow(const ApplicationInfo &applicationInfo)
	{
		glfwWindowHint(GLFW_SAMPLES, applicationInfo.Samples);
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		WindowInfo windowInfo;
		windowInfo.Title = applicationInfo.Title;
		windowInfo.Resolution = applicationInfo.Resolution;
		return std::make_unique<Window>(windowInfo);
	}

	std::unique_ptr<GraphicsContext> OpenGLGraphicsApi::CreateGraphicsContext(const Window &window)
	{
		return std::make_unique<OpenGLGraphicsContext>(window.GetHandle());
	}
}