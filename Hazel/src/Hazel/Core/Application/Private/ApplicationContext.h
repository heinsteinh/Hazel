#pragma once

#include <memory>

#include "Hazel/Core/Time/Chrono.h"
#include "ApplicationSettings.h"
#include "Hazel/Rendering/GraphicsApi/GraphicsApi.h"
#include "Hazel/Core/Window/Window.h"
#include "Hazel/Core/Events/EventSystem.h"
#include "ApplicationLayers.h"

namespace Hazel
{
	struct ApplicationContext
	{
		Chrono Chrono;
		float DeltaTime = 0.0f;
		ApplicationSettings Settings;
		std::shared_ptr<GraphicsApi> GraphicsApi;
		std::unique_ptr<Window> Window;
		EventSystem EventSystem;
		ApplicationLayers Layers;
	};
}