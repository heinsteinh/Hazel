#pragma once

#include "Hazel/Framebuffers/Framebuffer.h"
#include "OpenGLFramebufferHolder.h"

namespace Hazel
{
	class OpenGLFramebuffer : public Framebuffer
	{
	private:
		OpenGLFramebufferHolder holder;
		FramebufferInfo info;

	public:
		OpenGLFramebuffer(const FramebufferInfo &info);
		virtual ~OpenGLFramebuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual const FramebufferInfo &GetInfo() const override;
		virtual void *GetColorAttachement() const override;
	};
}