#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Layers/Layer.h"
#include "ImGuiContext.h"
#include "ImGuiRenderer.h"

namespace Hazel
{
	class ImGuiLayer : public Layer
	{
	private:
		ImGuiContext context;
		ImGuiRenderer renderer;

	public:
		ImGuiLayer(const Window &window);

		void Begin();
		void End();
		void OnContextCurrent();

		virtual const std::string &GetName() const override;
		virtual void OnKeyEvent(KeyEvent &e) override;
		virtual void OnMouseEvent(MouseEvent &e) override;
		virtual void OnWindowResized(WindowResizeEvent &e) override;
	};
}