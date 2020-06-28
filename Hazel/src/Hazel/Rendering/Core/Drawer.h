#pragma once

#include "Hazel/Utils/Rectangle.h"

namespace Hazel
{
	class Drawer
	{
	public:
		virtual ~Drawer() = default;

		virtual void SetViewport(const Rectangle &viewport) = 0;
		virtual void SetClearColor(const glm::vec4 &color) = 0;
		virtual void Clear() = 0;
		virtual void DrawIndexed(size_t count) = 0;
	};
}