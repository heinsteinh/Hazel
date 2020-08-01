#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/Textures/ColorFormat.h"

namespace Hazel
{
	class OpenGLColorFormat
	{
	public:
		static constexpr uint32_t FromColorFormat(ColorFormat format)
		{
			switch (format)
			{
			case ColorFormat::Rgb:
				return GL_RGB;
			case ColorFormat::Rgba:
				return GL_RGBA;
			}
			return 0;
		}

		OpenGLColorFormat() = delete;
	};
}