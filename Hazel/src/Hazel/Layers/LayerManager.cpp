#include "LayerManager.h"

#include "Hazel/Utils/Reversed.h"
#include "Hazel/Events/EventDispatcher.h"

namespace Hazel
{
	LayerManager::LayerManager(Window &window)
		: window(window.GetProperties()),
		imGuiLayer(std::make_shared<ImGuiLayer>(window.GetImGuiDrawer()))
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
		if (updateLayers && !window.IsMinimized())
		{
			UpdateLayers();
		}
		if (showImGui)
		{
			RenderImGui();
		}
	}

	void LayerManager::OnContextCurrent()
	{
		imGuiLayer->OnContextCurrent();
	}

	void LayerManager::OnEvent(Event &e)
	{
		Log::Debug("{}", e);
		for (const auto &layer : layers)
		{
			EventDispatcher(layer.get()).Dispatch(e);
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