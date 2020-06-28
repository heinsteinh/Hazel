#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Rendering/Core/GraphicsContext.h"

namespace Hazel
{
	class OpenGLContext : public GraphicsContext
	{
	private:
		GLFWwindow *window = nullptr;

	public:
		OpenGLContext(const Window &window);

		virtual void MakeCurrent() override;
		virtual void SwapBuffers() override;
	};
}