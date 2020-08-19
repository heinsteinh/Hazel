#pragma once

#include "Hazel/Rendering/Textures/Texture2D.h"
#include "Hazel/Rendering/Textures/TextureInfo.h"

namespace Hazel
{
	class OpenGLTexture2D : public Texture2D
	{
	private:
		uint32_t id = 0;
		float width = 0;
		float height = 0;
		ColorFormat colorFormat;

	public:
		OpenGLTexture2D(const TextureInfo &info);
		virtual ~OpenGLTexture2D();

		virtual float GetWidth() const override;
		virtual float GetHeight() const override;
		virtual void SetData(const void *data) override;
		virtual void Bind(uint32_t slot = 0) const override;
	};
}