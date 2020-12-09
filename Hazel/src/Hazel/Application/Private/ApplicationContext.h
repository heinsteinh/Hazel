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
		glm::vec4 clearColor{0.0f};
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

		const glm::vec4 &GetClearColor() const
		{
			return clearColor;
		}

		void SetClearColor(const glm::vec4 &clearColor)
		{
			this->clearColor = clearColor;
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
			GetGraphicsContext().SetClearColor(clearColor);
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
			layers.Attach(layerContext);
		}

		ApplicationLayers &GetLayers()
		{
			return layers;
		}

		const ApplicationLayers &GetLayers() const
		{
			return layers;
		}

		void ComputeDeltaTime()
		{
			layerContext.SetDeltaTime(chrono.Reset());
		}

		float GetDeltaTime() const
		{
			return layerContext.GetDeltaTime();
		}
	};
}