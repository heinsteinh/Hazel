#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class BaseApplication
	{
	private:
		ApplicationContext context;

	public:
		virtual ~BaseApplication() = default;

		void SetGraphicsApi(AvailableGraphicsApi api)
		{
			context.SetGraphicsApi(api);
		}

		void SetWindowTitle(const std::string &title)
		{
			context.GetWindowInfo().Title = title;
		}

		void SetWindowResolution(const glm::vec2 &resolution)
		{
			context.GetWindowInfo().Resolution = resolution;
		}

		void SetVerticalSynchronization(bool verticalSynchronization)
		{
			context.GetWindowInfo().VerticalSynchronization = verticalSynchronization;
		}

		void EnableGui(bool guiEnabled)
		{
			context.GetSettings().GuiEnabled = guiEnabled;
		}

		void EnableGuiRender(bool guiRenderingEnabled)
		{
			context.GetSettings().GuiRenderingEnabled = guiRenderingEnabled;
		}

		void PushLayer(const std::shared_ptr<Layer> &layer)
		{
			context.GetLayers().PushLayer(layer);
		}

		void PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			context.GetLayers().PushOverlay(overlay);
		}

		void SetClearColor(const glm::vec4 &clearColor)
		{
			context.SetClearColor(clearColor);
		}

	protected:
		ApplicationContext &GetContext()
		{
			return context;
		}
	};
}