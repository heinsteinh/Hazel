#include "OpenGLTexture.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLTexture::OpenGLTexture(const TextureInfo &info)
		: holder(info),
		info(info)
	{
		Log::Info("Texture successfully created with id {}.", holder.GetId());
	}

	OpenGLTexture::~OpenGLTexture()
	{
		Log::Info("Texture {} destruction.", holder.GetId());
	}

	const TextureInfo &OpenGLTexture::GetInfo() const
	{
		return info;
	}

	void OpenGLTexture::SetData(const void *data)
	{
		holder.SetData(data);
	}

	void OpenGLTexture::Bind(uint32_t slot) const
	{
		holder.Bind(slot);
	}

	void *OpenGLTexture::GetId() const
	{
		return (void *)holder.GetId();
	}
}