#pragma once

#include "glad/glad.h"

#include "Hazel/Textures/TextureFormat.h"

namespace Hazel
{
	class OpenGLTextureFormat
	{
	public:
		static constexpr uint32_t GetTextureFormat(TextureFormat format)
		{
			switch (format)
			{
			case TextureFormat::Rgb:
				return GL_RGB;
			case TextureFormat::Rgba:
				return GL_RGBA;
			case TextureFormat::DepthStencil:
				return GL_DEPTH_STENCIL;
			}
			return 0;
		}

		static constexpr uint32_t GetStorageFormat(TextureFormat format)
		{
			switch (format)
			{
			case TextureFormat::Rgb:
				return GL_RGB8;
			case TextureFormat::Rgba:
				return GL_RGBA8;
			case TextureFormat::DepthStencil:
				return GL_DEPTH24_STENCIL8;
			}
			return 0;
		}
	};
}