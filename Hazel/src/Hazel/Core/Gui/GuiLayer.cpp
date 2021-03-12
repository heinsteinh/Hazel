#include "GuiLayer.h"

#include "imgui.h"

#include "Hazel/Rendering/GuiRenderer/GuiRenderer.h"
#include "Private/GuiEventFilter.h"
#include "Private/GuiContext.h"

namespace Hazel
{
	GuiLayer::GuiLayer()
		: ApplicationLayer("GUI")
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

	void GuiLayer::OnAttach()
	{
		context = std::make_unique<GuiContext>();
		renderer = GetApplication().GetGraphicsContext().CreateGuiRenderer();
	}

	void GuiLayer::OnDetach()
	{
		context = nullptr;
		renderer = nullptr;
	}

	void GuiLayer::OnEvent(Event &e)
	{
		if (GuiEventFilter::CanBlockEvent(e.Type) && WantBlockEvent(e))
		{
			e.Blocked = true;
		}
	}

	bool GuiLayer::CanBlockKeyboard() const
	{
		return GetApplication().GetSettings().GuiKeyboardFilterEnabled;
	}

	bool GuiLayer::CanBlockMouse() const
	{
		return GetApplication().GetSettings().GuiMouseFilterEnabled;
	}

	bool GuiLayer::WantCaptureKeyboard() const
	{
		return CanBlockKeyboard() && ImGui::GetIO().WantCaptureKeyboard;
	}

	bool GuiLayer::WantCaptureMouse() const
	{
		return CanBlockMouse() && ImGui::GetIO().WantCaptureMouse;
	}

	bool GuiLayer::WantBlockEvent(Event &e) const
	{
		return WantCaptureKeyboard() && e.Categories & EventCategory::Keyboard
			|| WantCaptureMouse() && e.Categories & EventCategory::Mouse;
	}
}