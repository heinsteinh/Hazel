#include "ImGuiLayer.h"

#include "imgui.h"

namespace Hazel
{
	ImGuiLayer::ImGuiLayer(ImGuiDrawer &drawer)
		: renderer(drawer)
	{
	}

	void ImGuiLayer::Begin()
	{
		renderer.Begin();
	}

	void ImGuiLayer::End()
	{
		renderer.End();
	}

	void ImGuiLayer::OnContextCurrent()
	{
		renderer.OnContextCurrent();
	}

	const std::string &ImGuiLayer::GetName() const
	{
		return name;
	}

	void ImGuiLayer::OnAttach()
	{
		renderer.Init();
	}

	void ImGuiLayer::OnDetach()
	{
		renderer.Shutdown();
	}

	void ImGuiLayer::OnEvent(Event &e)
	{
		if (e.IsInCategory(EventCategory::Keyboard) && ImGui::GetIO().WantCaptureKeyboard)
		{
			e.Discard();
		}
		else if (e.IsInCategory(EventCategory::Mouse) && ImGui::GetIO().WantCaptureMouse)
		{
			e.Discard();
		}
	}

	void ImGuiLayer::OnWindowResized(WindowResizeEvent &e)
	{
		renderer.SetDisplaySize(e.GetSize());
	}
}