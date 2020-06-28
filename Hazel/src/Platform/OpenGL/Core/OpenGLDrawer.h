#pragma once

#include "Hazel/Rendering/Core/Drawer.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLDrawer : public Drawer
	{
	public:
		virtual void SetViewport(const Rectangle &viewport) override;
		virtual void SetClearColor(const glm::vec4 &color) override;
		virtual void Clear() override;
		virtual void DrawIndexed(size_t count) override;
	};
}