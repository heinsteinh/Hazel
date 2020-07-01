#include "ImGuiLayer.h"

#include "imgui.h"

namespace Hazel
{
	ImGuiLayer::ImGuiLayer(ImGuiDrawingContext &context)
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

	void ImGuiLayer::OnKeyEvent(KeyEvent &e)
	{
		if (ImGui::GetIO().WantCaptureKeyboard)
		{
			e.Discard();
		}
	}

	void ImGuiLayer::OnMouseEvent(MouseEvent &e)
	{
		if (ImGui::GetIO().WantCaptureMouse)
		{
			e.Discard();
		}
	}

	void ImGuiLayer::OnWindowResized(WindowResizeEvent &e)
	{
		renderer.SetDisplaySize(e.GetSize());
	}
}