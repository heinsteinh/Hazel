#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/Textures/TextureFiltering.h"

namespace Hazel
{
	class OpenGLTextureFiltering
	{
	public:
		static constexpr uint32_t FromTextureFiltering(TextureFiltering filtering)
		{
			switch (filtering)
			{
			case TextureFiltering::Nearest:
				return GL_NEAREST;
			case TextureFiltering::Linear:
				return GL_LINEAR;
			}
			return 0;
		}

		OpenGLTextureFiltering() = delete;
	};
}