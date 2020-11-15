#pragma once

#include "glad/glad.h"

namespace Hazel
{
	class OpenGLInfo
	{
	public:
		static inline size_t GetMaxTextures()
		{
			int result;
			glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &result);
			return result;
		}
	};
}