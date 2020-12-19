#pragma once

#include "Hazel/Rendering/Framebuffers/OpenGL/OpenGLFramebuffer.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBinder.h"

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

		void SetFramebuffer(Framebuffer *framebuffer)
		{
			OpenGLBinder::Bind(this->framebuffer, framebuffer);
		}
	};
}