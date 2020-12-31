#pragma once

#include <memory>

#include "Private/ApplicationInfo.h"
#include "Private/ApplicationContext.h"
#include "Private/ApplicationLayers.h"

namespace Hazel
{
	class Application
	{
	private:
		ApplicationInfo info;
		ApplicationContext context;
		ApplicationLayers layers;

	public:
		Application();
		virtual ~Application();

		void Run();
		void Close();
		void SetGraphicsApi(AvailableGraphicsApi graphicsApi);
		void SetWindowTitle(const std::string &title);
		void SetWindowResolution(const glm::vec2 &resolution);
		void SetVerticalSynchronization(bool verticalSynchronization);
		void EnableGui(bool guiEnabled);
		void EnableGuiRender(bool guiRenderingEnabled);
		void SetClearColor(const glm::vec4 &clearColor);
		void PushLayer(const std::shared_ptr<Layer> &layer);
		void PushOverlay(const std::shared_ptr<Layer> &overlay);
	};

	std::unique_ptr<Application> CreateApplication(int argc, char **argv);
}