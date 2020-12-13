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
		void PushLayer(const std::shared_ptr<Layer> &layer);
		void PushOverlay(const std::shared_ptr<Layer> &overlay);
		void PushImGuiLayer();
		void OnAttach(LayerContext &context);
		void OnDetach();
		void OnNewFrame();
		void OnEvent(Event &e);
		void OnUpdate();
		void OnImGuiRender();
	};
}