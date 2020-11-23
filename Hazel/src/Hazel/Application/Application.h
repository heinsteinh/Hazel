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

		inline void SetGraphicsApi(const std::shared_ptr<GraphicsApi> &graphicsApi)
		{
			context.SetGraphicsApi(graphicsApi);
		}

		inline void SetWindowTitle(const std::string &title)
		{
			context.SetWindowTitle(title);
		}

		inline void SetWindowResolution(Size resolution)
		{
			context.SetWindowResolution(resolution);
		}

		inline void SetVerticalSynchronization(bool verticalSynchronization)
		{
			context.SetVerticalSynchronization(verticalSynchronization);
		}

		inline void EnableImGui(bool imGuiEnabled)
		{
			context.EnableImGui(imGuiEnabled);
		}

		inline void EnableImGuiRender(bool imGuiRenderEnabled)
		{
			context.EnableImGuiRender(imGuiRenderEnabled);
		}

		inline void PushLayer(const std::shared_ptr<Layer> &layer)
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