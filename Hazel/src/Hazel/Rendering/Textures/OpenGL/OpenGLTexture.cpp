#include "OpenGLTexture.h"

#include "glad/glad.h"

#include "Hazel/Core/Logging/Log.h"
#include "Private/OpenGLTextureFactory.h"

namespace Hazel
{
	OpenGLTexture::OpenGLTexture(const TextureInfo &info)
		: Texture(OpenGLTextureFactory::CreateTexture(id, info), info)
	{
		Log::Debug("Texture created with id {}.", id);
	}

	OpenGLTexture::~OpenGLTexture()
	{
		glDeleteTextures(1, &id);
		Log::Info("Texture {} destroyed.", id);
	}

	void OpenGLTexture::Bind() const
	{
		glBindTextureUnit(slot, id);
	}

	void OpenGLTexture::Unbind() const
	{
		glBindTextureUnit(slot, 0);
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
}