#pragma once

#include "ApplicationInfo.h"
#include "Hazel/Graphics/GraphicsApiFactory.h"
#include "Hazel/Layers/LayersContext.h"
#include "ApplicationLayers.h"
#include "Hazel/Time/Chrono.h"

namespace Hazel
{
	class ApplicationContext
	{
	private:
		ApplicationInfo info;
		LayersContext layersContext;
		ApplicationLayers layers;
		Chrono chrono;

	public:
		inline void CreateApplicationWindow()
		{
			if (!info.GraphicsApi)
			{
				info.GraphicsApi = GraphicsApiFactory::CreateOpenGLInstance();
			}
			layersContext.CreateApplicationWindow(info.GetWindowInfo());
		}

		inline void SetupImGui()
		{
			if (info.ImGuiEnabled)
			{
				layers.PushImGuiLayer();
				layersContext.EnableImGuiRender(IsImGuiRenderEnabled());
			}
		}

		inline void AttachLayers()
		{
			layers.AttachLayers(layersContext);
		}

		inline ApplicationInfo &GetInfo()
		{
			return info;
		}

		inline const ApplicationInfo &GetInfo() const
		{
			return info;
		}

		inline GraphicsApi &GetGraphicsApi() const
		{
			return *info.GraphicsApi;
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

		inline void EnableImGuiRender(bool imGuiRenderEnabled)
		{
			layersContext.EnableImGuiRender(imGuiRenderEnabled);
		}

		inline Window &GetWindow() const
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