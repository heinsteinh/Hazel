#pragma once

#include "Platform/OpenGL/Textures/OpenGLTexture.h"

namespace Hazel
{
	class OpenGLTextureHolder
	{
	private:
		std::vector<OpenGLTexture *> textures;

	public:
		inline void InitTextureSlots(size_t slotCount)
		{
			textures.resize(slotCount, nullptr);
		}

		inline size_t GetTextureSlotCount() const
		{
			return textures.size();
		}

		inline OpenGLTexture *GetTexture(uint32_t slot) const
		{
			return textures[slot];
		}

		inline void SetTexture(const std::shared_ptr<Texture> &texture, uint32_t slot)
		{
			HZ_ASSERT(slot < textures.size(), "Not enough texture slots.");
			if (texture && textures[slot] != texture.get())
			{
				HZ_ASSERT(typeid(*texture) == typeid(OpenGLTexture), "Not an OpenGL type.");
				textures[slot] = static_cast<OpenGLTexture *>(texture.get());
				textures[slot]->Bind(slot);
			}
		}
	};
}