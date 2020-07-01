#include "LayerManager.h"

#include "Hazel/Utils/Reversed.h"

namespace Hazel
{
	LayerManager::LayerManager(ImGuiDrawingContext &imGuiContext)
		: imGuiLayer(std::make_shared<ImGuiLayer>(imGuiContext))
	{
		PushOverlay(imGuiLayer);
	}

	void LayerManager::PushLayer(const std::shared_ptr<Layer> &layer)
	{
		layers.PushLayer(layer);
		layer->OnAttach();
	}

	void LayerManager::PushOverlay(const std::shared_ptr<Layer> &overlay)
	{
		layers.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void LayerManager::OnUpdate()
	{
		if (updateLayers)
		{
			UpdateLayers();
		}
		if (showImGui)
		{
			RenderImGui();
		}
	}

	void LayerManager::OnEvent(Event &e)
	{
		Log::Debug("{}", e);
		for (const auto &layer : layers)
		{
			e.Dispatch(layer.get());
		}
	}

	void LayerManager::EnableLayersUpdate(bool update)
	{
		updateLayers = update;
	}

	void LayerManager::ShowImGui(bool show)
	{
		showImGui = show;
	}

	void LayerManager::UpdateLayers()
	{
		Log::Trace("Update Layers");
		auto deltaTime = chrono.Reset();
		for (const auto &layer : Reversed(layers))
		{
			layer->OnUpdate(deltaTime);
		}
	}

	void LayerManager::RenderImGui()
	{
		Log::Trace("Render ImGui");
		imGuiLayer->Begin();
		for (const auto &layer : Reversed(layers))
		{
			layer->OnImGuiRender();
		}
		imGuiLayer->End();
	}
}