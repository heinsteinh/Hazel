#pragma once

#include "Hazel/Rendering/GuiRenderer/GuiRenderer.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBindingContext.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLImGuiRenderer : public GuiRenderer
	{
	private:
		OpenGLBindingContext *context;

	public:
		OpenGLImGuiRenderer(GLFWwindow *window, OpenGLBindingContext &context);
		virtual ~OpenGLImGuiRenderer();

		virtual void CreateNewFrame() override;
		virtual void RenderDrawData() override;
	};
}