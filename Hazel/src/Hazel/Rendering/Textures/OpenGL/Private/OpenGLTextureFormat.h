#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/Textures/TextureFormat.h"

namespace Hazel
{
	class OpenGLTextureFormat
	{
	public:
		static constexpr uint32_t GetTextureFormat(TextureFormat format)
		{
			switch (format)
			{
			case TextureFormat::Rgb8:
				return GL_RGB;
			case TextureFormat::Rgba8:
				return GL_RGBA;
			case TextureFormat::DepthStencil:
				return GL_DEPTH_STENCIL;
			}
			return GL_RGBA;
		}

		static constexpr uint32_t GetStorageFormat(TextureFormat format)
		{
			switch (format)
			{
			case TextureFormat::Rgb8:
				return GL_RGB8;
			case TextureFormat::Rgba8:
				return GL_RGBA8;
			case TextureFormat::DepthStencil:
				return GL_DEPTH24_STENCIL8;
			}
			return GL_RGBA8;
		}
	};
}