#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/Textures/TextureWrapping.h"

namespace Hazel
{
	class OpenGLTextureWrapping
	{
	public:
		static constexpr uint32_t GetTextureWrapping(TextureWrapping wrapping)
		{
			switch (wrapping)
			{
			case TextureWrapping::Repeat:
				return GL_REPEAT;
			case TextureWrapping::MirroredRepeat:
				return GL_MIRRORED_REPEAT;
			case TextureWrapping::ClampToEdge:
				return GL_CLAMP_TO_EDGE;
			case TextureWrapping::ClampToBorder:
				return GL_CLAMP_TO_BORDER;
			}
			return GL_REPEAT;
		}
	};
}