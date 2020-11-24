#pragma once

#include "Platform/OpenGL/Framebuffers/OpenGLFramebuffer.h"
#include "Platform/OpenGL/GraphicsContext/OpenGLBinder.h"

namespace Hazel
{
	class OpenGLFramebufferHolder
	{
	private:
		OpenGLFramebuffer *framebuffer = nullptr;

	public:
		inline OpenGLFramebuffer *GetFramebuffer() const
		{
			return framebuffer;
		}

		inline void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer)
		{
			OpenGLBinder::Bind(this->framebuffer, framebuffer);
		}
	};
}