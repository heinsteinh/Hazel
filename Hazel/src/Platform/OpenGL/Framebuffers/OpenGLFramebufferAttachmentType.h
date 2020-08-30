#pragma once

#include "glad/glad.h"

#include "Hazel/Framebuffers/FramebufferAttachmentType.h"

namespace Hazel
{
	class OpenGLFramebufferAttachmentType
	{
	public:
		static constexpr uint32_t FromAttachmentType(FramebufferAttachmentType attachmentType, uint32_t slot = 0)
		{
			switch (attachmentType)
			{
			case FramebufferAttachmentType::Color:
				return GL_COLOR_ATTACHMENT0 + slot;
			case FramebufferAttachmentType::DepthStencil:
				return GL_DEPTH_STENCIL_ATTACHMENT;
			}
			return 0;
		}

		OpenGLFramebufferAttachmentType() = delete;
	};
}