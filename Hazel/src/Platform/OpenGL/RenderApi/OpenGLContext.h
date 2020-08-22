#pragma once

#include "Hazel/RenderApi/GraphicsContext.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLContext : public GraphicsContext
	{
	private:
		GLFWwindow *window = nullptr;

	public:
		OpenGLContext(GLFWwindow *window);

		virtual void MakeCurrent() override;
		virtual void SwapBuffers() override;
	};
}