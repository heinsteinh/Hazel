#pragma once

#include <vector>
#include <optional>

#include "Hazel/Rendering/Textures/Texture.h"

namespace Hazel
{
	class TextureArray
	{
	private:
		size_t textureCount = 0;
		std::vector<Texture *> textures;

	public:
		TextureArray(size_t slotCount = 0)
			: textures(slotCount)
		{
		}

		size_t TextureArray::GetSlotCount() const
		{
			return textures.size();
		}

		void TextureArray::SetSlotCount(size_t slotCount)
		{
			textures.resize(slotCount, nullptr);
		}

		size_t TextureArray::GetTextureCount() const
		{
			return textureCount;
		}

		void SetTextureCount(size_t textureCount)
		{
			this->textureCount = textureCount;
		}

		Texture *GetTexture(size_t slot) const
		{
			return textures[slot];
		}

		void Clear()
		{
			SetTextureCount(0);
		}

		std::optional<size_t> Add(Texture *texture)
		{
			auto last = textures.begin() + textureCount;
			auto i = std::find(textures.begin(), last, texture);
			if (i == last)
			{
				if (textureCount == GetSlotCount())
				{
					return std::nullopt;
				}
				textures[textureCount] = texture;
				return textureCount++;
			}
			return i - textures.begin();
		}
	};
}