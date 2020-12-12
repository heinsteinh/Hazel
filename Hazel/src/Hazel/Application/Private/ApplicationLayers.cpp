#include "ApplicationLayers.h"

#include "Hazel/Utils/Reversed.h"
#include "Hazel/Input/InputEventDispatcher.h"

namespace Hazel
{
	void ApplicationLayers::PushImGuiLayer()
	{
		imGuiLayer = std::make_shared<ImGuiLayer>();
		layers.PushOverlay(imGuiLayer);
	}

	void ApplicationLayers::Attach(LayerContext &context)
	{
		for (const auto &layer : layers)
		{
			layer->Attach(&context);
			layer->OnAttach();
		}
	}

	void ApplicationLayers::Detach()
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
			InputEventDispatcher::Dispatch(layer->GetInput(), e);
			layer->OnEvent(e);
		}
	}

	void ApplicationLayers::Update()
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

	void ApplicationLayers::ClearMouseScrollOffset()
	{
		for (const auto &layer : layers)
		{
			layer->GetInput().ClearMouseScrollOffset();
		}
	}
}