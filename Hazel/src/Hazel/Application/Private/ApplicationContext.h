#pragma once

#include "Hazel/GraphicsApi/GraphicsApiFactory.h"
#include "ApplicationLayers.h"
#include "LayerContext.h"
#include "Hazel/Time/Chrono.h"

namespace Hazel
{
	class ApplicationContext
	{
	private:
		std::shared_ptr<GraphicsApi> graphicsApi;
		WindowInfo windowInfo;
		LayerContext layerContext;
		ApplicationLayers layers;
		Chrono chrono;

	public:
		const std::shared_ptr<GraphicsApi> &GetGraphicsApi() const
		{
			return graphicsApi;
		}

		void SetGraphicsApi(const std::shared_ptr<GraphicsApi> &graphicsApi)
		{
			this->graphicsApi = graphicsApi;
			windowInfo.GraphicsApi = graphicsApi.get();
		}

		ApplicationSettings &GetSettings()
		{
			return layerContext.GetSettings();
		}

		const ApplicationSettings &GetSettings() const
		{
			return layerContext.GetSettings();
		}

		WindowInfo &GetWindowInfo()
		{
			return windowInfo;
		}

		const WindowInfo &GetWindowInfo() const
		{
			return windowInfo;
		}

		void CreateApplicationWindow()
		{
			layerContext.CreateApplicationWindow(windowInfo);
		}

		Window &GetWindow() const
		{
			return layerContext.GetWindow();
		}

		GraphicsContext &GetGraphicsContext() const
		{
			return GetWindow().GetGraphicsContext();
		}

		void SetEventCallback(const EventSystem::Callback &callback)
		{
			layerContext.SetEventCallback(callback);
		}

		void PollEvents()
		{
			layerContext.PollEvents();
		}

		void AttachLayers()
		{
			layers.AttachLayers(layerContext);
		}

		ApplicationLayers &GetLayers()
		{
			return layers;
		}

		const ApplicationLayers &GetLayers() const
		{
			return layers;
		}

		float GetDeltaTime()
		{
			return chrono.Reset();
		}
	};
}