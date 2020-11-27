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
		void AttachLayers(LayerContext &context);
		void DispatchEvent(Event &e);
		void UpdateLayers(float deltaTime);
		void RenderImGui();

		void PushLayer(const std::shared_ptr<Layer> &layer)
		{
			layers.PushLayer(layer);
		}

		void PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			layers.PushOverlay(overlay);
		}

		void EnableImGuiEventFilter(bool imguiEventFilterEnabled)
		{
			imGuiLayer->EnableEventFilter(imguiEventFilterEnabled);
		}
	};
}