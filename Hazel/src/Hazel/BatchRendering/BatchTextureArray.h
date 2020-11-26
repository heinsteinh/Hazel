#pragma once

#include "Hazel/Textures/Texture.h"

namespace Hazel
{
	class BatchTextureArray
	{
	private:
		size_t textureCount = 0;
		std::vector<std::shared_ptr<Texture>> textures;

	public:
		BatchTextureArray(size_t maxTextureCount = 0)
			: textures(maxTextureCount)
		{
		}

		size_t GetMaxTextureCount() const
		{
			return textures.size();
		}

		void SetMaxTextureCount(size_t textureCount)
		{
			textures.resize(textureCount);
		}

		constexpr size_t GetTextureCount() const
		{
			return textureCount;
		}

		void Clear()
		{
			SetTextureCount(0);
		}

		void SetTextureCount(size_t textureCount)
		{
			this->textureCount = textureCount;
			for (size_t i = textureCount; i < textures.size(); i++)
			{
				textures[i] = nullptr;
			}
		}

		const std::shared_ptr<Texture> &GetTexture(size_t slot) const
		{
			return textures[slot];
		}

		std::optional<size_t> Add(const std::shared_ptr<Texture> &texture)
		{
			auto last = textures.begin() + textureCount;
			auto i = std::find(textures.begin(), last, texture);
			if (i == last)
			{
				return TryAdd(texture);
			}
			return i - textures.begin();
		}

	private:
		std::optional<size_t> TryAdd(const std::shared_ptr<Texture> &texture)
		{
			if (textureCount == GetMaxTextureCount())
			{
				return {};
			}
			textures[textureCount] = texture;
			return textureCount++;
		}
	};
}