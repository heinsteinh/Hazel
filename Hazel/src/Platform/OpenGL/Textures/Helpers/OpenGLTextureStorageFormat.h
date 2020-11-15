#pragma once

#include "glad/glad.h"

#include "Hazel/Textures/TextureFormat.h"

namespace Hazel
{
	class OpenGLTextureStorageFormat
	{
	public:
		static constexpr uint32_t FromTextureFormat(TextureFormat format)
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