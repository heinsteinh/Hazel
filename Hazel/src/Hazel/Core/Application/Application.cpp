#include "Application.h"

#include "Hazel/Core/Logging/Log.h"
#include "Private/ApplicationMainLoop.h"

namespace Hazel
{
	Application::Application()
	{
		Log::Debug("Application created.");
	}

	Application::~Application()
	{
		Log::Info("Application destroyed.");
	}

	void Application::Run()
	{
		Log::Info("Application started.");
		ApplicationMainLoop::Run(info, context, layers);
		Log::Info("Application stopped.");
	}

	void Application::Close()
	{
		Log::Info("Exiting application");
		context.Settings.Running = false;
	}

	void Application::SetGraphicsApi(AvailableGraphicsApi graphicsApi)
	{
		info.GraphicsApi = graphicsApi;
	}

	void Application::SetWindowTitle(const std::string &title)
	{
		info.WindowInfo.Title = title;
	}

	void Application::SetWindowResolution(const glm::vec2 &resolution)
	{
		info.WindowInfo.Resolution = resolution;
	}

	void Application::SetVerticalSynchronization(bool verticalSynchronization)
	{
		info.WindowInfo.VerticalSynchronization = verticalSynchronization;
	}

	void Application::EnableGui(bool guiEnabled)
	{
		context.Settings.GuiEnabled = guiEnabled;
	}

	void Application::EnableGuiRender(bool guiRenderingEnabled)
	{
		context.Settings.GuiRenderingEnabled = guiRenderingEnabled;
	}

	void Application::SetClearColor(const glm::vec4 &clearColor)
	{
		info.ClearColor = clearColor;
	}

	void Application::PushLayer(const std::shared_ptr<Layer> &layer)
	{
		layers.Stack.PushLayer(layer);
	}

	void Application::PushOverlay(const std::shared_ptr<Layer> &overlay)
	{
		layers.Stack.PushOverlay(overlay);
	}
}