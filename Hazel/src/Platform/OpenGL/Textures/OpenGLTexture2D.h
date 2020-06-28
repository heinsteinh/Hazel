#pragma once

#include "Hazel/Rendering/Textures/Texture2D.h"
#include "Hazel/Rendering/Textures/TextureInfo.h"

namespace Hazel
{
	class OpenGLTexture2D : public Texture2D
	{
	private:
		unsigned int id = 0;
		size_t width = 0;
		size_t height = 0;
		ColorFormat colorFormat;

	public:
		OpenGLTexture2D(const TextureInfo &info);
		virtual ~OpenGLTexture2D();

		virtual size_t GetWidth() const override;
		virtual size_t GetHeight() const override;
		virtual void SetData(const void *data) override;
		virtual void Bind(unsigned int slot = 0) const override;

	private:
		void Init(const TextureInfo &info);
		void Create();
		void SetParameters(const TextureInfo &info);
	};
}