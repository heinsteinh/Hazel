#pragma once

#include "Hazel/Application/ApplicationInfo.h"
#include "Hazel/Graphics/GraphicsApiFactory.h"
#include "Hazel/Layers/LayersContext.h"
#include "ApplicationLayers.h"
#include "Hazel/Time/Chrono.h"

namespace Hazel
{
	class ApplicationContext
	{
	private:
		std::shared_ptr<GraphicsApi> graphicsApi;
		LayersContext layersContext;
		ApplicationLayers layers;
		Chrono chrono;

	public:
		inline ApplicationContext(ApplicationInfo &info)
			: graphicsApi(info.GraphicsApi ? info.GraphicsApi : GraphicsApiFactory::CreateOpenGLInstance()),
			layersContext({graphicsApi.get(), info.Title, info.Resolution}),
			layers(info.Layers)
		{
			layersContext.GetWindow().SetVerticalSynchronization(info.VerticalSynchronization);
			if (info.ImGuiEnabled)
			{
				layers.PushImGuiLayer();
				layersContext.EnableImGuiRender(info.ImGuiRenderEnabled);
			}
			layers.AttachLayers(layersContext);
		}

		inline GraphicsApi &GetGraphicsApi() const
		{
			return *graphicsApi;
		}

		inline bool IsRunning() const
		{
			return layersContext.IsRunning();
		}

		inline void SetRunning(bool running)
		{
			layersContext.SetRunning(running);
		}

		inline bool IsImGuiRenderEnabled() const
		{
			return layersContext.IsImGuiRenderEnabled();
		}

		inline Window &GetWindow()
		{
			return layersContext.GetWindow();
		}

		inline const Window &GetWindow() const
		{
			return layersContext.GetWindow();
		}

		inline GraphicsContext &GetGraphicsContext() const
		{
			return layersContext.GetGraphicsContext();
		}

		inline void SetEventCallback(const EventSystem::Callback &callback)
		{
			layersContext.SetEventCallback(callback);
		}

		inline void PollEvents()
		{
			layersContext.PollEvents();
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