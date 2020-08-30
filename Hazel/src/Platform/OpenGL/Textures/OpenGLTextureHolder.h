#pragma once

#include "Hazel/Textures/TextureInfo.h"

namespace Hazel
{
	class OpenGLTextureHolder
	{
	private:
		uint32_t id = 0;
		int width = 0;
		int height = 0;
		TextureFormat format = TextureFormat::Unknown;

	public:
		OpenGLTextureHolder(const TextureInfo &info);
		OpenGLTextureHolder(const OpenGLTextureHolder &other) = delete;
		OpenGLTextureHolder(OpenGLTextureHolder &&other) noexcept;
		~OpenGLTextureHolder();

		void Bind(uint32_t slot = 0) const;
		void SetParameters(const TextureInfo &info);
		void SetData(const void *data);

		OpenGLTextureHolder &operator=(const OpenGLTextureHolder &other) = delete;
		OpenGLTextureHolder &operator=(OpenGLTextureHolder &&other) noexcept;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}