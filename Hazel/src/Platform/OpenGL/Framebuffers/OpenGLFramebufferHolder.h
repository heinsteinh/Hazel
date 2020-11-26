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
		OpenGLFramebuffer *GetFramebuffer() const
		{
			return framebuffer;
		}

		void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer)
		{
			OpenGLBinder::Bind(this->framebuffer, framebuffer);
		}
	};
}