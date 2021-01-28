#include "GuiLayer.h"

#include "imgui.h"

#include "Private/GuiEventFilter.h"

namespace Hazel
{
	GuiLayer::GuiLayer()
		: Layer("GUI")
	{
	}

	void GuiLayer::BeginRender()
	{
		renderer->CreateNewFrame();
		ImGui::NewFrame();
	}

	void GuiLayer::EndRender()
	{
		ImGui::Render();
		renderer->RenderDrawData();
	}

	bool GuiLayer::WantCaptureKeyboard() const
	{
		return IsGuiKeyboardFilterEnabled() && ImGui::GetIO().WantCaptureKeyboard;
	}

	bool GuiLayer::WantCaptureMouse() const
	{
		return IsGuiMouseFilterEnabled() && ImGui::GetIO().WantCaptureMouse;
	}

	bool GuiLayer::WantBlockEvent(Event &e) const
	{
		return WantCaptureKeyboard() && e.IsInCategory(EventCategory::Keyboard)
			|| WantCaptureMouse() && e.IsInCategory(EventCategory::Mouse);
	}

	void GuiLayer::OnAttach()
	{
		context = std::make_unique<GuiContext>();
		renderer = GetGraphicsContext().CreateGuiRenderer();
	}

	void GuiLayer::OnDetach()
	{
		context.reset();
		renderer.reset();
	}

	void GuiLayer::OnEvent(Event &e)
	{
		if (GuiEventFilter::CanBlockEvent(e.GetType()) && WantBlockEvent(e))
		{
			e.Discard();
		}
	}
}