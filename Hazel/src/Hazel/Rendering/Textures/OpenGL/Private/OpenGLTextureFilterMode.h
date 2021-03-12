#pragma once

#include <cstdint>

#include "glad/glad.h"

#include "Hazel/Rendering/Textures/TextureFilterMode.h"

namespace Hazel
{
	class OpenGLTextureFilterMode
	{
	public:
		static constexpr uint32_t GetTextureFiltering(TextureFilterMode mode)
		{
			switch (mode)
			{
			case TextureFilterMode::Nearest:
				return GL_NEAREST;
			case TextureFilterMode::Linear:
				return GL_LINEAR;
			}
			return GL_LINEAR;
		}
	};
}