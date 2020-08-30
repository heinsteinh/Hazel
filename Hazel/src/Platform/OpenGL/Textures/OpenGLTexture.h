#pragma once

#include "Hazel/Textures/Texture.h"
#include "OpenGLTextureHolder.h"

namespace Hazel
{
	class OpenGLTexture : public Texture
	{
	private:
		OpenGLTextureHolder holder;
		TextureInfo info;

	public:
		OpenGLTexture(const TextureInfo &info);
		virtual ~OpenGLTexture();

		virtual const TextureInfo &GetInfo() const override;
		virtual void SetData(const void *data) override;
		virtual void Bind(uint32_t slot = 0) const override;
		virtual void *GetId() const override;

		constexpr uint32_t GetOpenGLId() const
		{
			return holder.GetId();
		}
	};
}