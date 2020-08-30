#include "OpenGLImGuiDrawer.h"

#include "imgui.h"

#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

namespace Hazel
{
	OpenGLImGuiDrawer::OpenGLImGuiDrawer(GLFWwindow *window)
		: window(window)
	{
	}

	OpenGLImGuiDrawer::~OpenGLImGuiDrawer()
	{
		Shutdown();
	}

	void OpenGLImGuiDrawer::Init()
	{
		if (!initialized)
		{
			ImGui_ImplGlfw_InitForOpenGL(window, true);
			ImGui_ImplOpenGL3_Init("#version 410");
			initialized = true;
		}
	}

	void OpenGLImGuiDrawer::Shutdown()
	{
		if (initialized)
		{
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
			initialized = false;
		}
	}

	void OpenGLImGuiDrawer::CreateNewFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
	}

	void OpenGLImGuiDrawer::RenderDrawData()
	{
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}