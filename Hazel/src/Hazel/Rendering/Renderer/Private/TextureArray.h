#pragma once

#include <vector>
#include <optional>
#include <memory>

#include "Hazel/Rendering/Textures/Texture.h"

namespace Hazel
{
	class TextureArray
	{
	private:
		size_t textureCount = 0;
		std::vector<std::weak_ptr<Texture>> textures;

	public:
		TextureArray(size_t slotCount = 0)
			: textures(slotCount)
		{
		}

		size_t TextureArray::GetTextureCount() const
		{
			return textureCount;
		}

		void SetTextureCount(size_t textureCount)
		{
			this->textureCount = textureCount;
		}

		size_t TextureArray::GetSlotCount() const
		{
			return textures.size();
		}

		void TextureArray::SetSlotCount(size_t slotCount)
		{
			textures.resize(slotCount);
		}

		const std::weak_ptr<Texture> &GetTexture(size_t slot) const
		{
			return textures[slot];
		}

		void Clear()
		{
			SetTextureCount(0);
		}

		std::optional<size_t> Add(const std::shared_ptr<Texture> &texture)
		{
			auto last = textures.begin() + textureCount;
			auto i = std::find_if(textures.begin(), last, [&](auto &currentTexture)
			{
				return currentTexture.lock() == texture;
			});
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