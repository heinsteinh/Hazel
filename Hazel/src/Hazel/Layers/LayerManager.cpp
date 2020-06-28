#include "LayerManager.h"

#include "Hazel/Utils/Reversed.h"

namespace Hazel
{
	LayerManager::LayerManager(const Window &window)
		: window(window),
		imGuiLayer(MakeShared<ImGuiLayer>(window))
	{
		PushOverlay(imGuiLayer);
	}

	void LayerManager::PushLayer(const SharedPtr<Layer> &layer)
	{
		layers.PushLayer(layer);
		layer->OnAttach();
	}

	void LayerManager::PushOverlay(const SharedPtr<Layer> &overlay)
	{
		layers.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void LayerManager::OnUpdate()
	{
		if (!window.IsMinimized())
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
			e.Dispatch(layer.get());
		}
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