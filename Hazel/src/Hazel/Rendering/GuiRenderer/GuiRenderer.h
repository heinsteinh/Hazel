#pragma once

#include "Hazel/Rendering/Framebuffers/Framebuffer.h"

namespace Hazel
{
	class GuiRenderer
	{
	public:
		virtual ~GuiRenderer() = default;

		virtual void CreateNewFrame() = 0;
		virtual void RenderDrawData(const std::shared_ptr<Framebuffer> &framebuffer = {}) = 0;
	};
}