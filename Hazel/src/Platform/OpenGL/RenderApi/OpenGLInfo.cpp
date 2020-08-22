#include "OpenGLInfo.h"

#include "glad/glad.h"

namespace Hazel
{
	size_t OpenGLInfo::GetMaxTextures() const
	{
		int result;
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &result);
		return result;
	}
}