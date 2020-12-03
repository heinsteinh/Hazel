#include "BatchTextureArray.h"

namespace Hazel
{
	BatchTextureArray::BatchTextureArray(size_t maxTextureCount)
		: textures(maxTextureCount)
	{
	}

	void BatchTextureArray::SetTextureCount(size_t textureCount)
	{
		this->textureCount = textureCount;
		for (size_t i = textureCount; i < textures.size(); i++)
		{
			textures[i] = nullptr;
		}
	}

	std::optional<size_t> BatchTextureArray::Add(Texture *texture)
	{
		auto last = textures.begin() + textureCount;
		auto i = std::find(textures.begin(), last, texture);
		if (i == last)
		{
			return TryAdd(texture);
		}
		return i - textures.begin();
	}

	std::optional<size_t> BatchTextureArray::TryAdd(Texture *texture)
	{
		if (textureCount == GetMaxTextureCount())
		{
			return {};
		}
		textures[textureCount] = texture;
		return textureCount++;
	}
}