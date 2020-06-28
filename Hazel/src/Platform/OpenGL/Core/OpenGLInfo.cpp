#include "OpenGLInfo.h"

#include "glad/glad.h"

namespace Hazel
{
	size_t OpenGLInfo::GetMaxTextureUnits() const
	{
		int textureUnits = 0;
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &textureUnits);
		return textureUnits;
	}
}