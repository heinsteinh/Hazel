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

		ImGuiContext &context;
		ImGuiRenderer renderer;

	public:
		ImGuiLayer(ImGuiContext &context);

		void Begin();
		void End();

		virtual const std::string &GetName() const override;
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event &e) override;
		virtual void OnWindowResized(WindowResizeEvent &e) override;
	};
}