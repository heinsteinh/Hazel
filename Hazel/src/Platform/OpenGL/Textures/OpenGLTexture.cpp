#include "OpenGLTexture.h"

#include "glad/glad.h"

#include "Helpers/OpenGLTextureStorageFormat.h"
#include "Helpers/OpenGLTextureFiltering.h"
#include "Helpers/OpenGLTextureWrapping.h"
#include "Helpers/OpenGLTextureFormat.h"

namespace Hazel
{
	OpenGLTexture::OpenGLTexture(const TextureInfo &info)
		: info(info)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &id);
		Log::Info("Texture created with id {}.", id);
		glTextureStorage2D(
			id,
			1,
			OpenGLTextureStorageFormat::FromTextureFormat(info.Format),
			static_cast<int>(info.Size.Width),
			static_cast<int>(info.Size.Height));
		glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, OpenGLTextureFiltering::FromTextureFiltering(info.MinFilter));
		glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, OpenGLTextureFiltering::FromTextureFiltering(info.MagFilter));
		glTextureParameteri(id, GL_TEXTURE_WRAP_S, OpenGLTextureWrapping::FromTextureWrapping(info.SWrap));
		glTextureParameteri(id, GL_TEXTURE_WRAP_T, OpenGLTextureWrapping::FromTextureWrapping(info.TWrap));
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

	const TextureInfo &OpenGLTexture::GetInfo() const
	{
		return info;
	}

	void OpenGLTexture::SetData(const void *data)
	{
		glTextureSubImage2D(
			id,
			0,
			0,
			0,
			static_cast<int>(info.Size.Width),
			static_cast<int>(info.Size.Height),
			OpenGLTextureFormat::FromTextureFormat(info.Format),
			GL_UNSIGNED_BYTE,
			data);
	}

	void *OpenGLTexture::GetHandle() const
	{
		return reinterpret_cast<void *>(static_cast<size_t>(id));
	}
}