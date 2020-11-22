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
		ApplicationLayers(const LayerStack &layers);

		void PushImGuiLayer();
		void AttachLayers(LayersContext &context);
		void DispatchEvent(Event &e);
		void UpdateLayers(float deltaTime);
		void RenderImGui();
	};
}