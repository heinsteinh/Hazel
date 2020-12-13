#include "ApplicationLayers.h"

#include "Hazel/Utils/Reversed.h"
#include "Hazel/Input/InputManager.h"

namespace Hazel
{
	void ApplicationLayers::PushLayer(const std::shared_ptr<Layer> &layer)
	{
		layers.PushLayer(layer);
	}

	void ApplicationLayers::PushOverlay(const std::shared_ptr<Layer> &overlay)
	{
		layers.PushOverlay(overlay);
	}

	void ApplicationLayers::PushImGuiLayer()
	{
		imGuiLayer = std::make_shared<ImGuiLayer>();
		layers.PushOverlay(imGuiLayer);
	}

	void ApplicationLayers::OnAttach(LayerContext &context)
	{
		for (const auto &layer : layers)
		{
			layer->Attach(&context);
			layer->OnAttach();
		}
	}

	void ApplicationLayers::OnDetach()
	{
		for (const auto &layer : layers)
		{
			layer->OnDetach();
			layer->Detach();
		}
	}

	void ApplicationLayers::OnNewFrame()
	{
		for (const auto &layer : layers)
		{
			InputManager::OnNewFrame(layer->GetInput());
		}
	}

	void ApplicationLayers::OnEvent(Event &e)
	{
		for (const auto &layer : Reversed(layers))
		{
			if (e.IsHandled())
			{
				return;
			}
			InputManager::OnEvent(layer->GetInput(), e);
			layer->OnEvent(e);
		}
	}

	void ApplicationLayers::OnUpdate()
	{
		for (const auto &layer : layers)
		{
			layer->OnUpdate();
		}
	}

	void ApplicationLayers::OnImGuiRender()
	{
		if (imGuiLayer)
		{
			imGuiLayer->BeginRender();
			for (const auto &layer : layers)
			{
				layer->OnImGuiRender();
			}
			imGuiLayer->EndRender();
		}
	}
}