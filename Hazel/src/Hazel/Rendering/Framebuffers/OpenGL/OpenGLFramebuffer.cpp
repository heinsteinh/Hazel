#include "OpenGLFramebuffer.h"

#include "glad/glad.h"

#include "Hazel/Core/Logging/Log.h"
#include "OpenGLFramebufferStatus.h"

namespace Hazel
{
	OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferInfo &info)
		: Framebuffer(info)
	{
		glCreateFramebuffers(1, &id);
		Log::Debug("Framebuffer successfully created with id {}.", id);
	}

	OpenGLFramebuffer::~OpenGLFramebuffer()
	{
		glDeleteFramebuffers(1, &id);
		Log::Debug("Framebuffer {} destruction.", id);
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

	void OpenGLFramebuffer::Bind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, id);
		auto size = GetSize();
		glViewport(0, 0, static_cast<int>(size.x), static_cast<int>(size.y));
	}

	void OpenGLFramebuffer::Unbind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	Texture &OpenGLFramebuffer::GetColorAttachment() const
	{
		return *colorAttachment;
	}

	Texture &OpenGLFramebuffer::GetDepthAttachment() const
	{
		return *depthAttachment;
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