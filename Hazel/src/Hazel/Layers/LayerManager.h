#pragma once

#include "Hazel/Window/Window.h"
#include "LayerStack.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Utils/Chrono.h"

namespace Hazel
{
	class LayerManager
	{
	private:
		const Window &window;
		Chrono chrono;
		LayerStack layers;
		std::shared_ptr<ImGuiLayer> imGuiLayer;
		bool showImGui = true;

	public:
		LayerManager(const Window &window);

		void PushLayer(const std::shared_ptr<Layer> &layer);
		void PushOverlay(const std::shared_ptr<Layer> &overlay);
		void OnUpdate();
		void OnContextCurrent();
		void OnEvent(Event &e);
		void ShowImGui(bool show);

	private:
		void UpdateLayers();
		void RenderImGui();
	};
}