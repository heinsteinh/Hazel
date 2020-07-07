#include "OpenGLTexture2D.h"

#include "glad/glad.h"

#include "OpenGLTextureBuilder.h"
#include "OpenGLColorFormat.h"

namespace Hazel
{
	OpenGLTexture2D::OpenGLTexture2D(const TextureInfo &info)
		: id(OpenGLTextureBuilder::Build(info)),
		width(info.Width),
		height(info.Height),
		colorFormat(info.ColorFormat)
	{
		Log::Info("Texture successfully created with id {}.", id);
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
		glTextureSubImage2D(
			id,
			0,
			0,
			0,
			static_cast<int>(width),
			static_cast<int>(height),
			OpenGLColorFormat::FromColorFormat(colorFormat),
			GL_UNSIGNED_BYTE,
			data);
	}

	void OpenGLTexture2D::Bind(size_t slot) const
	{
		glBindTextureUnit(static_cast<unsigned int>(slot), id);
	}
}