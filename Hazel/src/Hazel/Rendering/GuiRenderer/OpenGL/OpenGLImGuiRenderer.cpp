#include "OpenGLImGuiRenderer.h"

#include "GLFW/glfw3.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#pragma warning(push)
#pragma warning(disable : 4996)
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "backends/imgui_impl_glfw.cpp"
#include "backends/imgui_impl_opengl3.cpp"
#pragma warning(pop)

namespace Hazel
{
	OpenGLImGuiRenderer::OpenGLImGuiRenderer(GLFWwindow *window, OpenGLBindingContext &context)
		: context(&context)
	{
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	OpenGLImGuiRenderer::~OpenGLImGuiRenderer()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
	}

	void OpenGLImGuiRenderer::CreateNewFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
	}

	void OpenGLImGuiRenderer::RenderDrawData()
	{
		auto framebuffer = context->GetFramebuffer();
		if (framebuffer)
		{
			context->SetFramebuffer({});
		}
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow *currentContext = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(currentContext);
		}
	}
}