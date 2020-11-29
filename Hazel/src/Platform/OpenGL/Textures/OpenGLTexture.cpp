#include "OpenGLTexture.h"

#include "glad/glad.h"

#include "Private/OpenGLTextureFiltering.h"
#include "Private/OpenGLTextureWrapping.h"
#include "Private/OpenGLTextureFormat.h"

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
			OpenGLTextureFormat::GetStorageFormat(info.Format),
			static_cast<int>(info.Size.x),
			static_cast<int>(info.Size.y));
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

	void OpenGLTexture::BufferData(const void *data)
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