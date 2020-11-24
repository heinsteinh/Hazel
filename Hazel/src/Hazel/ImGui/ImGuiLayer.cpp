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
		return e.IsInCategory(EventCategory::Keyboard) && WantCaptureKeyboard()
			|| e.IsInCategory(EventCategory::Mouse) && WantCaptureMouse();
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
		e.Dispatch([this](WindowResizeEvent &e)
		{
			auto size = e.GetSize();
			ImGui::GetIO().DisplaySize = {size.Width, size.Height};
		});
		if (WantBlockEvent(e))
		{
			e.Discard();
		}
	}
}