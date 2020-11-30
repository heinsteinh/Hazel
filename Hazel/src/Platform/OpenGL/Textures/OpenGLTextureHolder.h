#pragma once

#include "Platform/OpenGL/Textures/OpenGLTexture.h"

namespace Hazel
{
	class OpenGLTextureHolder
	{
	private:
		std::vector<OpenGLTexture *> textures;

	public:
		size_t GetMaxTextureSlotCount() const
		{
			return textures.size();
		}

		void SetMaxTextureSlotCount(size_t maxTextureSlotCount)
		{
			textures.resize(maxTextureSlotCount, nullptr);
		}

		OpenGLTexture *GetTexture(size_t slot) const
		{
			HZ_ASSERT(slot < textures.size(), "Not enough texture slots.");
			return textures[slot];
		}

		void SetTexture(const std::shared_ptr<Texture> &texture, size_t slot)
		{
			HZ_ASSERT(slot < textures.size(), "Not enough texture slots.");
			auto &currentTexture = textures[slot];
			if (texture && currentTexture != texture.get())
			{
				HZ_ASSERT(typeid(*texture) == typeid(OpenGLTexture), "Not an OpenGL type.");
				currentTexture = static_cast<OpenGLTexture *>(texture.get());
				currentTexture->Bind(slot);
			}
		}
	};
}