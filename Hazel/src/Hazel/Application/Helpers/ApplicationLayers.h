#pragma once

#include "Hazel/Layers/LayerStack.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Layers/LayersContext.h"

namespace Hazel
{
	class ApplicationLayers
	{
	private:
		LayerStack layers;
		std::shared_ptr<ImGuiLayer> imGuiLayer;

	public:
		void PushImGuiLayer();
		void AttachLayers(LayersContext &context);
		void DispatchEvent(Event &e);
		void UpdateLayers(float deltaTime);
		void RenderImGui();

		inline void PushLayer(const std::shared_ptr<Layer> &layer)
		{
			layers.PushLayer(layer);
		}

		inline void PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			layers.PushOverlay(overlay);
		}
	};
}