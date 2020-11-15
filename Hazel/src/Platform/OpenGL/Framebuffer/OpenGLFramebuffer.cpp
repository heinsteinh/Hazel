#include "OpenGLFramebuffer.h"

#include "glad/glad.h"

#include "OpenGLFramebufferStatus.h"

namespace Hazel
{
	OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferInfo &info)
		: info(info)
	{
		glCreateFramebuffers(1, &id);
		Log::Debug("Framebuffer successfully created with id {}.", id);
	}

	OpenGLFramebuffer::~OpenGLFramebuffer()
	{
		glDeleteFramebuffers(1, &id);
		Log::Debug("Framebuffer {} destruction.", id);
	}

	void OpenGLFramebuffer::Bind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, id);
		glViewport(0, 0, static_cast<int>(info.Size.Width), static_cast<int>(info.Size.Height));
	}

	void OpenGLFramebuffer::Unbind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	uint32_t OpenGLFramebuffer::GetStatus() const
	{
		return glCheckNamedFramebufferStatus(id, GL_FRAMEBUFFER);
	}

	bool OpenGLFramebuffer::IsComplete() const
	{
		return GetStatus() == GL_FRAMEBUFFER_COMPLETE;
	}

	const std::string &OpenGLFramebuffer::GetStatusName() const
	{
		return OpenGLFramebufferStatus::GetStatusName(GetStatus());
	}

	void OpenGLFramebuffer::SetColorAttachment(const std::shared_ptr<OpenGLTexture> &colorAttachment)
	{
		this->colorAttachment = colorAttachment;
		Attach(GL_COLOR_ATTACHMENT0, colorAttachment);
	}

	void OpenGLFramebuffer::SetDepthAttachment(const std::shared_ptr<OpenGLTexture> &depthAttachment)
	{
		this->depthAttachment = depthAttachment;
		Attach(GL_DEPTH_STENCIL_ATTACHMENT, depthAttachment);
	}

	const FramebufferInfo &OpenGLFramebuffer::GetInfo() const
	{
		return info;
	}

	std::shared_ptr<Texture> OpenGLFramebuffer::GetColorAttachement() const
	{
		return colorAttachment;
	}

	std::shared_ptr<Texture> OpenGLFramebuffer::GetDepthAttachement() const
	{
		return depthAttachment;
	}

	void OpenGLFramebuffer::Attach(int attachmentType, const std::shared_ptr<OpenGLTexture> &texture)
	{
		glNamedFramebufferTexture(
			id,
			attachmentType,
			texture->GetId(),
			0);
	}
}