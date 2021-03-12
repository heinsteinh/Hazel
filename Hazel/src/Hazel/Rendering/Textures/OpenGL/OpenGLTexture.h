#pragma once

#include "Hazel/Rendering/Textures/Texture.h"

namespace Hazel
{
	class OpenGLTexture : public Texture
	{
	private:
		uint32_t id;
		uint32_t slot = 0;

	public:
		OpenGLTexture(const TextureInfo &info);
		virtual ~OpenGLTexture();

		void Bind() const;
		void Unbind() const;

		virtual void BufferData(const void *data, const Box2D &region) override;

		uint32_t GetId() const
		{
			return id;
		}

		uint32_t GetSlot() const
		{
			return slot;
		}

		void SetSlot(uint32_t slot)
		{
			this->slot = slot;
		}
	};
}