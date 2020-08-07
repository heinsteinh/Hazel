#pragma once

#include "Hazel/Layers/Layer.h"
#include "ImGuiContext.h"
#include "ImGuiRenderer.h"

namespace Hazel
{
	class ImGuiLayer : public Layer
	{
	private:
		static inline const std::string name = "ImGui";

		ImGuiRenderer renderer;

	public:
		ImGuiLayer(ImGuiDrawer &drawer);

		void Begin();
		void End();
		void OnContextCurrent();

		virtual const std::string &GetName() const override;
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event &e) override;
		virtual void OnWindowResized(WindowResizeEvent &e) override;
	};
}