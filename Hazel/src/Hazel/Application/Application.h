#pragma once

#include "Helpers/ApplicationInfo.h"

namespace Hazel
{
	class ApplicationContext;

	class Application
	{
	private:
		ApplicationInfo info;
		std::unique_ptr<ApplicationContext> context;

	public:
		Application();
		virtual ~Application();

		void Run();

		inline void SetGraphicsApi(const std::shared_ptr<GraphicsApi> &graphicsApi)
		{
			info.GraphicsApi = graphicsApi;
		}

		inline void SetTitle(const std::string &title)
		{
			info.Title = title;
		}

		inline void SetResolution(Size resolution)
		{
			info.Resolution = resolution;
		}

		inline void SetVerticalSynchronization(bool verticalSynchronization)
		{
			info.VerticalSynchronization = verticalSynchronization;
		}

		inline void EnableImGui(bool imGuiEnabled)
		{
			info.ImGuiEnabled = imGuiEnabled;
		}

		inline void RenderImGui(bool imGuiRenderEnabled)
		{
			info.ImGuiRenderEnabled = imGuiRenderEnabled;
		}

		inline void PushLayer(const std::shared_ptr<Layer> &layer)
		{
			info.Layers.PushLayer(layer);
		}

		void PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			info.Layers.PushOverlay(overlay);
		}
	};

	std::unique_ptr<Application> CreateApplication(int argc, char *argv[]);
}