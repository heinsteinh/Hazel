#include "OpenGLTextureHolder.h"

#include "glad/glad.h"

#include "OpenGLTextureFormat.h"
#include "OpenGLTextureStorageFormat.h"
#include "OpenGLTextureFiltering.h"
#include "OpenGLTextureWrapping.h"

namespace Hazel
{
	OpenGLTextureHolder::OpenGLTextureHolder(const TextureInfo &info)
		: width(static_cast<int>(info.Dimensions.Width)),
		height(static_cast<int>(info.Dimensions.Height)),
		format(info.Format)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &id);
		glTextureStorage2D(
			id,
			1,
			OpenGLTextureStorageFormat::FromTextureFormat(format),
			width,
			height);
		SetParameters(info);
	}

	OpenGLTextureHolder::OpenGLTextureHolder(OpenGLTextureHolder &&other) noexcept
		: id(std::exchange(other.id, 0)),
		width(std::exchange(other.width, 0)),
		height(std::exchange(other.height, 0)),
		format(std::exchange(other.format, TextureFormat::Unknown))
	{
	}

	OpenGLTextureHolder::~OpenGLTextureHolder()
	{
		if (id)
		{
			glDeleteTextures(1, &id);
		}
	}

	void OpenGLTextureHolder::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, id);
	}

	void OpenGLTextureHolder::SetParameters(const TextureInfo &info)
	{
		glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, OpenGLTextureFiltering::FromTextureFiltering(info.MinFilter));
		glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, OpenGLTextureFiltering::FromTextureFiltering(info.MagFilter));
		glTextureParameteri(id, GL_TEXTURE_WRAP_S, OpenGLTextureWrapping::FromTextureWrapping(info.SWrap));
		glTextureParameteri(id, GL_TEXTURE_WRAP_T, OpenGLTextureWrapping::FromTextureWrapping(info.TWrap));
	}

	void OpenGLTextureHolder::SetData(const void *data)
	{
		glTextureSubImage2D(
			id,
			0,
			0,
			0,
			width,
			height,
			OpenGLTextureFormat::FromTextureFormat(format),
			GL_UNSIGNED_BYTE,
			data);
	}
	OpenGLTextureHolder &OpenGLTextureHolder::operator=(OpenGLTextureHolder &&other) noexcept
	{
		std::swap(id, other.id);
		std::swap(width, other.width);
		std::swap(height, other.height);
		std::swap(format, other.format);
		return *this;
	}
}