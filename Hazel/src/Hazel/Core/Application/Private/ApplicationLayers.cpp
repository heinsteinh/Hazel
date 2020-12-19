#include "ApplicationLayers.h"

#include "ApplicationContext.h"
#include "Hazel/Core/Utils/Reversed.h"
#include "Hazel/Core/Input/InputManager.h"
#include "Hazel/Core/Gui/GuiLayer.h"

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

	void ApplicationLayers::PushGuiLayer()
	{
		guiLayer = std::make_shared<GuiLayer>();
		layers.PushOverlay(guiLayer);
	}

	void ApplicationLayers::OnAttach(ApplicationContext &context)
	{
		for (const auto &layer : layers)
		{
			layer->Attach(context);
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

	void ApplicationLayers::OnGui()
	{
		if (guiLayer)
		{
			guiLayer->BeginRender();
			for (const auto &layer : layers)
			{
				layer->OnGui();
			}
			guiLayer->EndRender();
		}
	}
}