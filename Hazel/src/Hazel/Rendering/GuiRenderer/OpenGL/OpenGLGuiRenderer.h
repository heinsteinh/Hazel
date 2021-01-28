#pragma once

#include "Hazel/Rendering/GuiRenderer/GuiRenderer.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBindingContext.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLGuiRenderer : public GuiRenderer
	{
	private:
		OpenGLBindingContext *context;

	public:
		OpenGLGuiRenderer(GLFWwindow *window, OpenGLBindingContext &context);
		virtual ~OpenGLGuiRenderer();

		virtual void CreateNewFrame() override;
		virtual void RenderDrawData(const std::shared_ptr<Framebuffer> &framebuffer = {}) override;
	};
}