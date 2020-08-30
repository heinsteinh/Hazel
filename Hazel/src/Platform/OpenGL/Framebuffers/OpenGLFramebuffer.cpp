#include "OpenGLFramebuffer.h"

#include "glad/glad.h"

#include "OpenGLFramebufferBuilder.h"

namespace Hazel
{
	OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferInfo &info)
		: holder(OpenGLFramebufferBuilder::Build(info)),
		info(info)
	{
		Log::Info("Framebuffer successfully created with id {}.", holder.GetId());
	}

	OpenGLFramebuffer::~OpenGLFramebuffer()
	{
		Log::Info("Framebuffer {} destruction.", holder.GetId());
	}

	void OpenGLFramebuffer::Bind() const
	{
		holder.Bind();
	}

	void OpenGLFramebuffer::Unbind() const
	{
		holder.Unbind();
	}

	const FramebufferInfo &OpenGLFramebuffer::GetInfo() const
	{
		return info;
	}

	void *OpenGLFramebuffer::GetColorAttachement() const
	{
		return (void *)holder.GetColorAttachmentId();
	}
}