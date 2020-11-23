#include "ApplicationLayers.h"

#include "Hazel/Utils/Reversed.h"

namespace Hazel
{
	void ApplicationLayers::PushImGuiLayer()
	{
		imGuiLayer = std::make_shared<ImGuiLayer>();
		layers.PushOverlay(imGuiLayer);
	}

	void ApplicationLayers::AttachLayers(LayersContext &context)
	{
		for (const auto &layer : layers)
		{
			layer->SetContext(context);
			layer->OnAttach();
		}
	}

	void ApplicationLayers::DispatchEvent(Event &e)
	{
		for (const auto &layer : Reversed(layers))
		{
			if (e.IsHandled())
			{
				return;
			}
			layer->UpdateInput(e);
			layer->OnEvent(e);
		}
	}

	void ApplicationLayers::UpdateLayers(float deltaTime)
	{
		for (const auto &layer : layers)
		{
			layer->OnUpdate(deltaTime);
		}
	}

	void ApplicationLayers::RenderImGui()
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