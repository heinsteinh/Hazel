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
		bool imGuiEnabled = true;
		WindowInfo windowInfo;
		LayerContext layerContext;
		ApplicationLayers layers;
		Chrono chrono;

	public:
		inline const std::shared_ptr<GraphicsApi> &GetGraphicsApi() const
		{
			return graphicsApi;
		}

		inline void SetGraphicsApi(const std::shared_ptr<GraphicsApi> &graphicsApi)
		{
			this->graphicsApi = graphicsApi;
			windowInfo.GraphicsApi = graphicsApi.get();
		}

		inline bool IsImGuiEnabled() const
		{
			return imGuiEnabled;
		}

		inline void EnableImGui(bool imGuiEnabled)
		{
			this->imGuiEnabled = imGuiEnabled;
		}

		inline bool IsRunning() const
		{
			return layerContext.IsRunning();
		}

		inline void SetRunning(bool running)
		{
			layerContext.SetRunning(running);
		}

		inline bool IsImGuiRenderEnabled() const
		{
			return layerContext.IsImGuiRenderEnabled();
		}

		inline void EnableImGuiRender(bool imGuiRenderEnabled)
		{
			layerContext.EnableImGuiRender(imGuiRenderEnabled);
		}

		inline void SetWindowTitle(const std::string &title)
		{
			windowInfo.Title = title;
		}

		inline void SetWindowResolution(Size resolution)
		{
			windowInfo.Resolution = resolution;
		}

		inline void SetVerticalSynchronization(bool verticalSynchronization)
		{
			windowInfo.VerticalSynchronization = verticalSynchronization;
		}

		inline void CreateApplicationWindow()
		{
			layerContext.CreateApplicationWindow(windowInfo);
		}

		inline Window &GetWindow() const
		{
			return layerContext.GetWindow();
		}

		inline GraphicsContext &GetGraphicsContext() const
		{
			return layerContext.GetGraphicsContext();
		}

		inline void SetEventCallback(const EventSystem::Callback &callback)
		{
			layerContext.SetEventCallback(callback);
		}

		inline void PollEvents()
		{
			layerContext.PollEvents();
		}

		inline void AttachLayers()
		{
			layers.AttachLayers(layerContext);
		}

		inline ApplicationLayers &GetLayers()
		{
			return layers;
		}

		inline const ApplicationLayers &GetLayers() const
		{
			return layers;
		}

		inline float GetDeltaTime()
		{
			return chrono.Reset();
		}
	};
}