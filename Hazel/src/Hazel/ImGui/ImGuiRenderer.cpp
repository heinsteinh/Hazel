#include "ImGuiRenderer.h"

#include "GLFW/glfw3.h"

#include "imgui.h"

namespace Hazel
{
	ImGuiRenderer::ImGuiRenderer(ImGuiDrawer &drawer)
		: drawer(drawer)
	{
	}

	ImGuiRenderer::~ImGuiRenderer()
	{
		Shutdown();
	}

	void ImGuiRenderer::OnContextCurrent()
	{
		context.MakeCurrent();
	}

	void ImGuiRenderer::Init()
	{
		context.Init();
		drawer.Init();
	}

	void ImGuiRenderer::Shutdown()
	{
		drawer.Shutdown();
		context.Shutdown();
	}

	void ImGuiRenderer::Begin()
	{
		drawer.CreateNewFrame();
		ImGui::NewFrame();
	}

	void ImGuiRenderer::End()
	{
		ImGui::Render();
		drawer.RenderDrawData();
		UpdateWindows();
	}

	void ImGuiRenderer::SetDisplaySize(Size size)
	{
		ImGui::GetIO().DisplaySize = {size.Width, size.Height};
	}

	void ImGuiRenderer::UpdateWindows()
	{
		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow *backup = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup);
		}
	}
}