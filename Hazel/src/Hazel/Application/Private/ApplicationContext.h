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
		AvailableGraphicsApi api = AvailableGraphicsApi::OpenGL;
		std::shared_ptr<GraphicsApi> graphicsApi;
		WindowInfo windowInfo;
		LayerContext layerContext;
		ApplicationLayers layers;
		Chrono chrono;

	public:
		const GraphicsApi &GetGraphicsApi() const
		{
			return *graphicsApi;
		}

		void SetGraphicsApi(AvailableGraphicsApi api)
		{
			this->api = api;
		}

		void LoadGraphicsApi()
		{
			graphicsApi = GraphicsApiFactory::Create(api);
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