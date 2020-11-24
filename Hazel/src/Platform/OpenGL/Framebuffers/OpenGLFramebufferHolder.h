#pragma once

#include "Platform/OpenGL/Framebuffers/OpenGLFramebuffer.h"

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
			if (framebuffer && this->framebuffer != framebuffer.get())
			{
				HZ_ASSERT(typeid(*framebuffer) == typeid(OpenGLFramebuffer), "Not an OpenGL type.");
				this->framebuffer = static_cast<OpenGLFramebuffer *>(framebuffer.get());
				this->framebuffer->Bind();
			}
		}
	};
}