#pragma once

#include "Hazel/Core/Window/Window.h"
#include "Hazel/Core/Application/ApplicationInfo.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"

struct GLFWwindow;

namespace Hazel
{
	class GraphicsApi
	{
	public:
		virtual ~GraphicsApi() = default;

		virtual std::unique_ptr<Window> CreateNewWindow(const ApplicationInfo &applicationInfo) = 0;
		virtual std::unique_ptr<GraphicsContext> CreateGraphicsContext(const Window &window) = 0;
	};
}