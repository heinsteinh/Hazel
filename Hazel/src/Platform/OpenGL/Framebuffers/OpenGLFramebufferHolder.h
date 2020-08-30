#pragma once

#include "Hazel/Framebuffers/FramebufferInfo.h"
#include "Hazel/Framebuffers/FramebufferAttachmentType.h"
#include "Platform/OpenGL/Textures/OpenGLTexture.h"

namespace Hazel
{
	class OpenGLFramebufferHolder
	{
	private:
		uint32_t id = 0;
		Size dimensions;
		std::shared_ptr<OpenGLTexture> colorAttachment;
		std::shared_ptr<OpenGLTexture> depthAttachment;

	public:
		OpenGLFramebufferHolder(const FramebufferInfo &info);
		OpenGLFramebufferHolder(const OpenGLFramebufferHolder &other) = delete;
		OpenGLFramebufferHolder(OpenGLFramebufferHolder &&other) noexcept;
		~OpenGLFramebufferHolder();

		void Bind() const;
		void Unbind() const;
		uint32_t GetStatus() const;
		bool IsComplete() const;
		const std::string &GetStatusName() const;

		OpenGLFramebufferHolder &operator=(const OpenGLFramebufferHolder &other) = delete;
		OpenGLFramebufferHolder &operator=(OpenGLFramebufferHolder &&other) noexcept;

		constexpr uint32_t GetId() const
		{
			return id;
		}

		constexpr uint32_t GetColorAttachmentId() const
		{
			return colorAttachment->GetOpenGLId();
		}

	private:
		void SetAttachment(FramebufferAttachmentType attachmentType, uint32_t attachmentId);
	};
}