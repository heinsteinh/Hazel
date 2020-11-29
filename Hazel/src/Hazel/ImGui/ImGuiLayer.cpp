#include "ImGuiLayer.h"

#include "imgui.h"

namespace Hazel
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGui")
	{
	}

	void ImGuiLayer::BeginRender()
	{
		renderer->CreateNewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::EndRender()
	{
		ImGui::Render();
		renderer->RenderDrawData();
	}

	bool ImGuiLayer::WantCaptureKeyboard() const
	{
		return ImGui::GetIO().WantCaptureKeyboard;
	}

	bool ImGuiLayer::WantCaptureMouse() const
	{
		return ImGui::GetIO().WantCaptureMouse;
	}

	bool ImGuiLayer::WantBlockEvent(Event &e) const
	{
		return e.IsInCategory(EventCategory::Keyboard) && WantCaptureKeyboard() && IsImGuiKeyboardFilterEnabled()
			|| e.IsInCategory(EventCategory::Mouse) && WantCaptureMouse() && IsImGuiMouseFilterEnabled();
	}

	void ImGuiLayer::OnAttach()
	{
		imGuiContext = std::make_unique<ImGuiContextHolder>();
		renderer = GetGraphicsContext().CreateImGuiRenderer();
	}

	void ImGuiLayer::OnDetach()
	{
		imGuiContext = nullptr;
		renderer = nullptr;
	}

	void ImGuiLayer::OnEvent(Event &e)
	{
		if (WantBlockEvent(e))
		{
			e.Discard();
		}
	}
}