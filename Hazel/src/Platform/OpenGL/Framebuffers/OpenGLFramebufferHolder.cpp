#include "OpenGLFramebufferHolder.h"

#include "glad/glad.h"

#include "OpenGLFramebufferAttachmentType.h"
#include "OpenGLFramebufferStatus.h"

namespace Hazel
{
	OpenGLFramebufferHolder::OpenGLFramebufferHolder(const FramebufferInfo &info)
		: dimensions(info.Dimensions),
		colorAttachment(std::make_shared<OpenGLTexture>(TextureInfo{dimensions, TextureFormat::Rgba})),
		depthAttachment(std::make_shared<OpenGLTexture>(TextureInfo{dimensions, TextureFormat::DepthStencil}))
	{
		glCreateFramebuffers(1, &id);
		SetAttachment(FramebufferAttachmentType::Color, colorAttachment->GetOpenGLId());
		SetAttachment(FramebufferAttachmentType::DepthStencil, depthAttachment->GetOpenGLId());
	}

	OpenGLFramebufferHolder::OpenGLFramebufferHolder(OpenGLFramebufferHolder &&other) noexcept
		: id(std::exchange(other.id, 0)),
		dimensions(std::exchange(other.dimensions, Size()))
	{
	}

	OpenGLFramebufferHolder::~OpenGLFramebufferHolder()
	{
		if (id)
		{
			glDeleteFramebuffers(1, &id);
		}
	}

	void OpenGLFramebufferHolder::Bind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, id);
		glViewport(0, 0, static_cast<int>(dimensions.Width), static_cast<int>(dimensions.Height));
	}

	void OpenGLFramebufferHolder::Unbind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	uint32_t OpenGLFramebufferHolder::GetStatus() const
	{
		return glCheckNamedFramebufferStatus(id, GL_FRAMEBUFFER);
	}

	bool OpenGLFramebufferHolder::IsComplete() const
	{
		return GetStatus() == GL_FRAMEBUFFER_COMPLETE;
	}

	const std::string &OpenGLFramebufferHolder::GetStatusName() const
	{
		return OpenGLFramebufferStatus::getStatusName(GetStatus());
	}

	void OpenGLFramebufferHolder::SetAttachment(FramebufferAttachmentType attachmentType, uint32_t attachmentId)
	{
		glNamedFramebufferTexture(
			id,
			OpenGLFramebufferAttachmentType::FromAttachmentType(attachmentType),
			attachmentId,
			0);
	}

	OpenGLFramebufferHolder &OpenGLFramebufferHolder::operator=(OpenGLFramebufferHolder &&other) noexcept
	{
		std::swap(id, other.id);
		std::swap(dimensions, other.dimensions);
		return *this;
	}
}