#pragma once

#include "Hazel/Graphics/GraphicsApi.h"

namespace Hazel
{
	class OpenGL : public GraphicsApi
	{
	public:
		virtual std::shared_ptr<GraphicsContext> CreateContext(GLFWwindow *window) override;
	};
}