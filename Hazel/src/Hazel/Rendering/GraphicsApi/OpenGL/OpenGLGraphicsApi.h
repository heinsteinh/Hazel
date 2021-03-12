#pragma once

#include "Hazel/Rendering/GraphicsApi/GraphicsApi.h"

namespace Hazel
{
	class OpenGLGraphicsApi : public GraphicsApi
	{
	public:
		virtual std::unique_ptr<Window> CreateNewWindow(const ApplicationInfo &applicationInfo) override;
		virtual std::unique_ptr<GraphicsContext> CreateGraphicsContext(const Window &window) override;
	};
}