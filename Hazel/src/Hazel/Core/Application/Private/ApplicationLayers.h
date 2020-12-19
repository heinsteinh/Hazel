#pragma once

#include "LayerStack.h"
#include "Hazel/Core/Events/Event.h"

namespace Hazel
{
	class GuiLayer;
	struct ApplicationContext;

	class ApplicationLayers
	{
	private:
		LayerStack layers;
		std::shared_ptr<GuiLayer> guiLayer;

	public:
		void PushLayer(const std::shared_ptr<Layer> &layer);
		void PushOverlay(const std::shared_ptr<Layer> &overlay);
		void PushGuiLayer();
		void OnAttach(ApplicationContext &context);
		void OnDetach();
		void OnNewFrame();
		void OnEvent(Event &e);
		void OnUpdate();
		void OnGui();
	};
}