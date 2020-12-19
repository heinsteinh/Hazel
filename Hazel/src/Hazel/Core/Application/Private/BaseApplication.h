#pragma once

#include "glm/glm.hpp"

#include "ApplicationInfo.h"
#include "ApplicationContext.h"

namespace Hazel
{
	class BaseApplication
	{
	private:
		ApplicationInfo info;
		ApplicationContext context;

	public:
		virtual ~BaseApplication() = default;

		void SetGraphicsApi(AvailableGraphicsApi graphicsApi)
		{
			info.GraphicsApi = graphicsApi;
		}

		void SetWindowTitle(const std::string &title)
		{
			info.WindowInfo.Title = title;
		}

		void SetWindowResolution(const glm::vec2 &resolution)
		{
			info.WindowInfo.Resolution = resolution;
		}

		void SetVerticalSynchronization(bool verticalSynchronization)
		{
			info.WindowInfo.VerticalSynchronization = verticalSynchronization;
		}

		void EnableGui(bool guiEnabled)
		{
			context.Settings.GuiEnabled = guiEnabled;
		}

		void EnableGuiRender(bool guiRenderingEnabled)
		{
			context.Settings.GuiRenderingEnabled = guiRenderingEnabled;
		}

		void PushLayer(const std::shared_ptr<Layer> &layer)
		{
			context.Layers.PushLayer(layer);
		}

		void PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			context.Layers.PushOverlay(overlay);
		}

		void SetClearColor(const glm::vec4 &clearColor)
		{
			info.ClearColor = clearColor;
		}

	protected:
		ApplicationInfo &GetInfo()
		{
			return info;
		}

		ApplicationContext &GetContext()
		{
			return context;
		}
	};
}