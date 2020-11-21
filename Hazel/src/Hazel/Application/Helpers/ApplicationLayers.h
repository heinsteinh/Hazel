#pragma once

#include "Hazel/Layers/LayersContext.h"
#include "Hazel/Layers/LayerStack.h"
#include "Hazel/ImGui/ImGuiLayer.h"

namespace Hazel
{
	class ApplicationLayers
	{
	private:
		LayersContext &context;
		LayerStack layers;
		std::shared_ptr<ImGuiLayer> imGuiLayer;

	public:
		ApplicationLayers(LayersContext &context);

		void PushImGuiLayer();
		void PushLayer(const std::shared_ptr<Layer> &layer);
		void PushOverlay(const std::shared_ptr<Layer> &overlay);
		void DispatchEvent(Event &e);
		void UpdateLayers(float deltaTime);
		void RenderImGui();
	};
}