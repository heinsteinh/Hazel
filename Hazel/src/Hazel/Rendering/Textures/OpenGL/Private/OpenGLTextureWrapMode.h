#pragma once

#include <cstdint>

#include "glad/glad.h"

#include "Hazel/Rendering/Textures/TextureWrapMode.h"

namespace Hazel
{
	class OpenGLTextureWrapMode
	{
	public:
		static constexpr uint32_t GetTextureWrapping(TextureWrapMode mode)
		{
			switch (mode)
			{
			case TextureWrapMode::Repeat:
				return GL_REPEAT;
			case TextureWrapMode::MirroredRepeat:
				return GL_MIRRORED_REPEAT;
			case TextureWrapMode::ClampToEdge:
				return GL_CLAMP_TO_EDGE;
			case TextureWrapMode::ClampToBorder:
				return GL_CLAMP_TO_BORDER;
			}
			return GL_REPEAT;
		}
	};
}