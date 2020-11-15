#pragma once

#include "Hazel/Textures/Texture.h"

namespace Hazel
{
	class OpenGLTexture : public Texture
	{
	private:
		uint32_t id;
		TextureInfo info;

	public:
		OpenGLTexture(const TextureInfo &info);
		virtual ~OpenGLTexture();

		void Bind(uint32_t slot = 0) const;

		virtual const TextureInfo &GetInfo() const override;
		virtual void SetData(const void *data) override;
		virtual void *GetHandle() const override;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}