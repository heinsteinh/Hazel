#pragma once

#include "LayerStack.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Time/Chrono.h"

namespace Hazel
{
	class LayerManager
	{
	private:
		Chrono chrono;
		LayerStack layers;
		std::shared_ptr<ImGuiLayer> imGuiLayer;
		bool updateLayers = true;
		bool showImGui = true;

	public:
		LayerManager(ImGuiContext &imGuiContext);

		void PushLayer(const std::shared_ptr<Layer> &layer);
		void PushOverlay(const std::shared_ptr<Layer> &overlay);
		void OnUpdate();
		void OnEvent(Event &e);
		void EnableLayersUpdate(bool update);
		void ShowImGui(bool show);

	private:
		void UpdateLayers();
		void RenderImGui();
	};
}