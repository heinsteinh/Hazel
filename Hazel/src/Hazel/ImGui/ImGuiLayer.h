#pragma once

#include "Hazel/Layers/Layer.h"
#include "ImGuiDrawingContext.h"
#include "ImGuiRenderer.h"

namespace Hazel
{
	class ImGuiLayer : public Layer
	{
	private:
		static inline const std::string name = "ImGui";

		ImGuiDrawingContext &context;
		ImGuiRenderer renderer;

	public:
		ImGuiLayer(ImGuiDrawingContext &context);

		void Begin();
		void End();

		virtual const std::string &GetName() const override;
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnKeyEvent(KeyEvent &e) override;
		virtual void OnMouseEvent(MouseEvent &e) override;
		virtual void OnWindowResized(WindowResizeEvent &e) override;
	};
}