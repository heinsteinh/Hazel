#pragma once

#include <memory>

#include "Hazel/Core/Window/Window.h"
#include "Hazel/Core/Time/Chrono.h"
#include "Hazel/Core/Application/ApplicationSettings.h"
#include "Hazel/Rendering/GraphicsApi/GraphicsApi.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "ApplicationLayerStack.h"

namespace Hazel
{
	class GuiLayer;

	struct ApplicationPrivate
	{
		Chrono Chrono;
		float DeltaTime = 0.0f;
		ApplicationSettings Settings;
		std::unique_ptr<GraphicsApi> GraphicsApi;
		std::unique_ptr<Window> Window;
		std::unique_ptr<GraphicsContext> GraphicsContext;
		bool GuiEnabled = true;
		ApplicationLayerStack Layers;
		GuiLayer *GuiLayer = nullptr;
	};
}