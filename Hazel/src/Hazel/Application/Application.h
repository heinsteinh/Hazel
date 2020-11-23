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
			context.GetInfo().GraphicsApi = graphicsApi;
		}

		inline void SetTitle(const std::string &title)
		{
			context.GetInfo().Title = title;
		}

		inline void SetResolution(Size resolution)
		{
			context.GetInfo().Resolution = resolution;
		}

		inline void SetVerticalSynchronization(bool verticalSynchronization)
		{
			context.GetInfo().VerticalSynchronization = verticalSynchronization;
		}

		inline void EnableImGui(bool imGuiEnabled)
		{
			context.GetInfo().ImGuiEnabled = imGuiEnabled;
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