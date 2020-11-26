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
		const std::shared_ptr<GraphicsApi> &GetGraphicsApi() const
		{
			return graphicsApi;
		}

		void SetGraphicsApi(const std::shared_ptr<GraphicsApi> &graphicsApi)
		{
			this->graphicsApi = graphicsApi;
			windowInfo.GraphicsApi = graphicsApi.get();
		}

		bool IsImGuiEnabled() const
		{
			return imGuiEnabled;
		}

		void EnableImGui(bool imGuiEnabled)
		{
			this->imGuiEnabled = imGuiEnabled;
		}

		bool IsRunning() const
		{
			return layerContext.IsRunning();
		}

		void SetRunning(bool running)
		{
			layerContext.SetRunning(running);
		}

		bool IsImGuiRenderEnabled() const
		{
			return layerContext.IsImGuiRenderEnabled();
		}

		void EnableImGuiRender(bool imGuiRenderEnabled)
		{
			layerContext.EnableImGuiRender(imGuiRenderEnabled);
		}

		void SetWindowTitle(const std::string &title)
		{
			windowInfo.Title = title;
		}

		void SetWindowResolution(Size resolution)
		{
			windowInfo.Resolution = resolution;
		}

		void SetVerticalSynchronization(bool verticalSynchronization)
		{
			windowInfo.VerticalSynchronization = verticalSynchronization;
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
			return layerContext.GetGraphicsContext();
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