#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLId.h"
#include "Hazel/Rendering/Textures/TextureInfo.h"
#include "OpenGLTextureFormat.h"
#include "OpenGLTextureFilterMode.h"
#include "OpenGLTextureWrapMode.h"

namespace Hazel
{
	class OpenGLTextureFactory
	{
	public:
		static void *CreateTexture(uint32_t &id, const TextureInfo &info)
		{
			glCreateTextures(GL_TEXTURE_2D, 1, &id);
			glTextureStorage2D(
				id,
				1,
				OpenGLTextureFormat::GetStorageFormat(info.Format),
				static_cast<int>(info.Size.x),
				static_cast<int>(info.Size.y));
			glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, OpenGLTextureFilterMode::GetTextureFiltering(info.MinFilterMode));
			glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, OpenGLTextureFilterMode::GetTextureFiltering(info.MagFilterMode));
			glTextureParameteri(id, GL_TEXTURE_WRAP_S, OpenGLTextureWrapMode::GetTextureWrapping(info.WrapModeU));
			glTextureParameteri(id, GL_TEXTURE_WRAP_T, OpenGLTextureWrapMode::GetTextureWrapping(info.WrapModeV));
			return OpenGLId::GetHandle(id);
		}
	};
}