#include "ImGuiLayer.h"

#include "imgui.h"

#include "Private/ImGuiEventFilter.h"

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
		return IsImGuiKeyboardFilterEnabled() && ImGui::GetIO().WantCaptureKeyboard;
	}

	bool ImGuiLayer::WantCaptureMouse() const
	{
		return IsImGuiMouseFilterEnabled() && ImGui::GetIO().WantCaptureMouse;
	}

	bool ImGuiLayer::WantBlockEvent(Event &e) const
	{
		return WantCaptureKeyboard() && e.IsInCategory(EventCategory::Keyboard)
			|| WantCaptureMouse() && e.IsInCategory(EventCategory::Mouse);
	}

	void ImGuiLayer::OnAttach()
	{
		context = std::make_unique<ImGuiContextHolder>();
		renderer = GetGraphicsContext().CreateImGuiRenderer();
	}

	void ImGuiLayer::OnDetach()
	{
		context = nullptr;
		renderer = nullptr;
	}

	void ImGuiLayer::OnEvent(Event &e)
	{
		if (ImGuiEventFilter::CanBlockEvent(e) && WantBlockEvent(e))
		{
			e.Discard();
		}
	}
}