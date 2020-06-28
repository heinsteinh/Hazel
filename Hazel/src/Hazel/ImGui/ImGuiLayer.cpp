#include "ImGuiLayer.h"

#include "imgui.h"

namespace Hazel
{
	ImGuiLayer::ImGuiLayer(const Window &window)
		: context(window)
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
		context.MakeCurrent();
	}

	const std::string &ImGuiLayer::GetName() const
	{
		return name;
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