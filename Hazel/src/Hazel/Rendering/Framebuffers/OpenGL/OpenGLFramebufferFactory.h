#pragma once

#include "OpenGLFramebuffer.h"
#include "Hazel/Rendering/Textures/OpenGL/OpenGLTexture.h"

namespace Hazel
{
	class OpenGLFramebufferFactory
	{
	public:
		static std::shared_ptr<OpenGLFramebuffer> CreateFramebuffer(const FramebufferInfo &info)
		{
			auto framebuffer = std::make_shared<OpenGLFramebuffer>(info);
			TextureInfo textureInfo;
			textureInfo.Size = info.Size;
			textureInfo.Format = TextureFormat::Rgba8;
			framebuffer->SetColorAttachment(std::make_shared<OpenGLTexture>(textureInfo));
			textureInfo.Format = TextureFormat::DepthStencil;
			framebuffer->SetDepthAttachment(std::make_shared<OpenGLTexture>(textureInfo));
			if (!framebuffer->IsComplete())
			{
				throw FramebufferCreationException("Framebuffer creation failed with status " + framebuffer->GetStatusName());
			}
			return framebuffer;
		}
	};
}