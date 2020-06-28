#include "OpenGLTexture2D.h"

#include "glad/glad.h"

#include "OpenGLColorFormat.h"
#include "OpenGLStorageColorFormat.h"
#include "OpenGLTextureFiltering.h"
#include "OpenGLTextureWrapping.h"

namespace Hazel
{
	OpenGLTexture2D::OpenGLTexture2D(const TextureInfo &info)
		: width(info.Width),
		height(info.Height),
		colorFormat(info.ColorFormat)
	{
		Init(info);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &id);
	}

	size_t OpenGLTexture2D::GetWidth() const
	{
		return width;
	}

	size_t OpenGLTexture2D::GetHeight() const
	{
		return height;
	}

	void OpenGLTexture2D::SetData(const void *data)
	{
		glTextureSubImage2D(id, 0, 0, 0, static_cast<int>(width), static_cast<int>(height),
			OpenGLColorFormat::FromColorFormat(colorFormat), GL_UNSIGNED_BYTE, data);
	}

	void OpenGLTexture2D::Bind(unsigned int slot) const
	{
		glBindTextureUnit(slot, id);
	}

	void OpenGLTexture2D::Init(const TextureInfo &info)
	{
		Create();
		SetParameters(info);
		Log::Info("Texture successfuly loaded with id {}", id);
	}

	void OpenGLTexture2D::Create()
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &id);
		glTextureStorage2D(
			id,
			1,
			OpenGLStorageColorFormat::FromColorFormat(colorFormat),
			static_cast<int>(width),
			static_cast<int>(height));
	}

	void OpenGLTexture2D::SetParameters(const TextureInfo &info)
	{
		glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, OpenGLTextureFiltering::FromTextureFiltering(info.MinFilter));
		glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, OpenGLTextureFiltering::FromTextureFiltering(info.MagFilter));
		glTextureParameteri(id, GL_TEXTURE_WRAP_S, OpenGLTextureWrapping::FromTextureWrapping(info.SWrap));
		glTextureParameteri(id, GL_TEXTURE_WRAP_T, OpenGLTextureWrapping::FromTextureWrapping(info.TWrap));
	}
}