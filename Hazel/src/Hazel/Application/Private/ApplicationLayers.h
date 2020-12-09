#pragma once

#include "LayerStack.h"
#include "LayerContext.h"
#include "Hazel/ImGui/ImGuiLayer.h"

namespace Hazel
{
	class ApplicationLayers
	{
	private:
		LayerStack layers;
		std::shared_ptr<ImGuiLayer> imGuiLayer;

	public:
		void PushImGuiLayer();
		void Attach(LayerContext &context);
		void Detach();
		void DispatchEvent(Event &e);
		void Update();
		void RenderImGui();
		void ClearMouseScrollOffset();

		void PushLayer(const std::shared_ptr<Layer> &layer)
		{
			layers.PushLayer(layer);
		}

		void PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			layers.PushOverlay(overlay);
		}
	};
}