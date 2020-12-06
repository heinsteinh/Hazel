#include "ApplicationLayers.h"

#include "Hazel/Utils/Reversed.h"
#include "Hazel/Input/InputUpdater.h"

namespace Hazel
{
	void ApplicationLayers::PushImGuiLayer()
	{
		imGuiLayer = std::make_shared<ImGuiLayer>();
		layers.PushOverlay(imGuiLayer);
	}

	void ApplicationLayers::AttachLayers(LayerContext &context)
	{
		for (const auto &layer : layers)
		{
			layer->Attach(&context);
			layer->OnAttach();
		}
	}

	void ApplicationLayers::DetachLayers()
	{
		for (const auto &layer : layers)
		{
			layer->OnDetach();
			layer->Detach();
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
			InputUpdater::UpdateInput(layer->GetInput(), e);
			layer->OnEvent(e);
		}
	}

	void ApplicationLayers::UpdateLayers()
	{
		for (const auto &layer : layers)
		{
			layer->OnUpdate();
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

	void ApplicationLayers::ResetMouseScrollOffset()
	{
		for (const auto &layer : layers)
		{
			layer->GetInput().ResetMouseScrollOffset();
		}
	}
}