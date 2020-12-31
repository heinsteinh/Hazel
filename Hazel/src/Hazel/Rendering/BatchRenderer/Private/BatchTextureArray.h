#pragma once

#include "Hazel/Rendering/Textures/Texture.h"

namespace Hazel
{
	class BatchTextureArray
	{
	private:
		size_t textureCount = 0;
		std::vector<Texture *> textures;

	public:
		BatchTextureArray(size_t maxTextureCount = 0);

		void SetTextureCount(size_t textureCount);
		std::optional<size_t> Add(Texture *texture);

		size_t BatchTextureArray::GetMaxTextureCount() const
		{
			return textures.size();
		}

		void BatchTextureArray::SetMaxTextureCount(size_t textureCount)
		{
			textures.resize(textureCount);
		}

		size_t BatchTextureArray::GetTextureCount() const
		{
			return textureCount;
		}

		Texture *GetTexture(size_t slot) const
		{
			return textures[slot];
		}

		void Clear()
		{
			SetTextureCount(0);
		}

	private:
		std::optional<size_t> TryAdd(Texture *texture);
	};
}