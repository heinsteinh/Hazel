#pragma once

#include "Hazel/ImGui/ImGuiRenderer.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLImGuiRenderer : public ImGuiRenderer
	{
	public:
		OpenGLImGuiRenderer(GLFWwindow *window);
		virtual ~OpenGLImGuiRenderer();

		virtual void CreateNewFrame() override;
		virtual void RenderDrawData() override;
	};
}