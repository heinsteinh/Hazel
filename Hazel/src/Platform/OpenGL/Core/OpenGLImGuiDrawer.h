#pragma once

#include "Hazel/Rendering/RenderApi/ImGuiDrawer.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLImGuiDrawer : public ImGuiDrawer
	{
	private:
		GLFWwindow *window = nullptr;
		bool initialized = false;

	public:
		OpenGLImGuiDrawer(GLFWwindow *window);
		virtual ~OpenGLImGuiDrawer();

		virtual void Init() override;
		virtual void Shutdown() override;
		virtual void CreateNewFrame() override;
		virtual void RenderDrawData() override;
	};
}