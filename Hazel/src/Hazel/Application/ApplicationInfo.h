#pragma once

#include "Hazel/Graphics/GraphicsApi.h"
#include "Hazel/Geometry/Size.h"
#include "Hazel/Layers/LayerStack.h"
#include "Hazel/Window/WindowInfo.h"

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
		LayerStack Layers;
	};
}