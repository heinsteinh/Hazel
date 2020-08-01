#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/Textures/ColorFormat.h"

namespace Hazel
{
	class OpenGLStorageColorFormat
	{
	public:
		static constexpr uint32_t FromColorFormat(ColorFormat format)
		{
			switch (format)
			{
			case ColorFormat::Rgb:
				return GL_RGB8;
			case ColorFormat::Rgba:
				return GL_RGBA8;
			}
			return 0;
		}

		OpenGLStorageColorFormat() = delete;
	};
}