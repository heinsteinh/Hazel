#pragma once

#include "Helpers/ApplicationContext.h"

namespace Hazel
{
	class Application
	{
	private:
		ApplicationContext context;

	public:
		Application();
		virtual ~Application();

		void Run();

		void SetGraphicsApi(const std::shared_ptr<GraphicsApi> &graphicsApi)
		{
			context.SetGraphicsApi(graphicsApi);
		}

		void SetWindowTitle(const std::string &title)
		{
			context.SetWindowTitle(title);
		}

		void SetWindowResolution(Size resolution)
		{
			context.SetWindowResolution(resolution);
		}

		void SetVerticalSynchronization(bool verticalSynchronization)
		{
			context.SetVerticalSynchronization(verticalSynchronization);
		}

		void EnableImGui(bool imGuiEnabled)
		{
			context.EnableImGui(imGuiEnabled);
		}

		void EnableImGuiRender(bool imGuiRenderEnabled)
		{
			context.EnableImGuiRender(imGuiRenderEnabled);
		}

		void PushLayer(const std::shared_ptr<Layer> &layer)
		{
			context.GetLayers().PushLayer(layer);
		}

		void PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			context.GetLayers().PushOverlay(overlay);
		}
	};

	std::unique_ptr<Application> CreateApplication(int argc, char *argv[]);
}