#pragma once

#include "OpenGLFramebuffer.h"
#include "Hazel/Rendering/Textures/OpenGL/OpenGLTexture.h"

namespace Hazel
{
	class OpenGLFramebufferBuilder
	{
	public:
		static std::shared_ptr<OpenGLFramebuffer> Build(const FramebufferInfo &info)
		{
			auto framebuffer = std::make_shared<OpenGLFramebuffer>(info);
			framebuffer->SetColorAttachment(std::make_shared<OpenGLTexture>(TextureInfo{info.Size, TextureFormat::Rgba8}));
			framebuffer->SetDepthAttachment(std::make_shared<OpenGLTexture>(TextureInfo{info.Size, TextureFormat::DepthStencil}));
			if (!framebuffer->IsComplete())
			{
				throw FramebufferCreationException("Framebuffer creation failed with status " + framebuffer->GetStatusName());
			}
			return framebuffer;
		}
	};
}