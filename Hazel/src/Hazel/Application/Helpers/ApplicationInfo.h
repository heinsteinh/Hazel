#pragma once

#include "Hazel/Window/WindowInfo.h"
#include "Hazel/Layers/LayerStack.h"

namespace Hazel
{
	struct ApplicationInfo
	{
		std::shared_ptr<GraphicsApi> GraphicsApi;
		std::string Title = "Hazel";
		Size Resolution = {1280.0f, 720.0f};
		bool VerticalSynchronization = true;
		bool ImGuiEnabled = true;
		bool ImGuiRenderEnabled = true;

		inline WindowInfo GetWindowInfo() const
		{
			WindowInfo info;
			info.GraphicsApi = GraphicsApi.get();
			info.Title = Title;
			info.Resolution = Resolution;
			info.VerticalSynchronization = VerticalSynchronization;
			return info;
		}
	};
}