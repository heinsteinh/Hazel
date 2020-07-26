#include "ImGuiLayer.h"

#include "imgui.h"

namespace Hazel
{
	ImGuiLayer::ImGuiLayer(ImGuiContext &context)
		: context(context)
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

	const std::string &ImGuiLayer::GetName() const
	{
		return name;
	}

	void ImGuiLayer::OnAttach()
	{
		context.Init();
	}

	void ImGuiLayer::OnDetach()
	{
		context.Shutdown();
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