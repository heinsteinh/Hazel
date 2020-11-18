#include "OpenGLTexture.h"

#include "glad/glad.h"

#include "Helpers/OpenGLTextureFiltering.h"
#include "Helpers/OpenGLTextureWrapping.h"
#include "Helpers/OpenGLTextureFormat.h"

namespace Hazel
{
	OpenGLTexture::OpenGLTexture(const TextureInfo &info)
		: Texture(info)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &id);
		Log::Debug("Texture created with id {}.", id);
		glTextureStorage2D(
			id,
			1,
			OpenGLTextureFormat::GetStorageFormat(GetFormat()),
			static_cast<int>(GetWidth()),
			static_cast<int>(GetHeight()));
		glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, OpenGLTextureFiltering::GetTextureFiltering(info.MinFilter));
		glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, OpenGLTextureFiltering::GetTextureFiltering(info.MagFilter));
		glTextureParameteri(id, GL_TEXTURE_WRAP_S, OpenGLTextureWrapping::GetTextureWrapping(info.SWrap));
		glTextureParameteri(id, GL_TEXTURE_WRAP_T, OpenGLTextureWrapping::GetTextureWrapping(info.TWrap));
	}

	OpenGLTexture::~OpenGLTexture()
	{
		glDeleteTextures(1, &id);
		Log::Info("Texture {} destroyed.", id);
	}

	void OpenGLTexture::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, id);
	}

	void OpenGLTexture::SetData(const void *data)
	{
		glTextureSubImage2D(
			id,
			0,
			0,
			0,
			static_cast<int>(GetWidth()),
			static_cast<int>(GetHeight()),
			OpenGLTextureFormat::GetTextureFormat(GetFormat()),
			GL_UNSIGNED_BYTE,
			data);
	}

	void *OpenGLTexture::GetHandle() const
	{
		return reinterpret_cast<void *>(static_cast<size_t>(id));
	}
}