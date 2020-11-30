#pragma once

#include "Hazel/Textures/Texture.h"

namespace Hazel
{
	class OpenGLTexture : public Texture
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLTexture(const TextureInfo &info);
		virtual ~OpenGLTexture();

		void Bind(size_t slot = 0) const;

		virtual void BufferData(const void *data) override;
		virtual void *GetHandle() const override;

		uint32_t GetId() const
		{
			return id;
		}
	};
}