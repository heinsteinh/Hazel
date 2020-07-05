#pragma once

#include "Hazel/Rendering/Textures/Texture.h"

namespace Hazel
{
	class TextureBatch
	{
	private:
		size_t size = 0;
		size_t maxTextures = 0;
		std::vector<std::shared_ptr<Texture>> textures;

	public:
		inline TextureBatch(size_t maxTextures)
			: maxTextures(maxTextures),
			textures(maxTextures)
		{
		}

		inline void Clear()
		{
			size = 0;
		}

		inline size_t Add(const std::shared_ptr<Texture> &texture)
		{
			auto last = textures.begin() + size;
			auto i = std::find(textures.begin(), last, texture);
			if (i == last)
			{
				assert(size < maxTextures);
				textures[size] = texture;
				return size++;
			}
			return i - textures.begin();
		}

		inline void Bind() const
		{
			for (size_t i = 0; i < size; i++)
			{
				textures[i]->Bind(static_cast<unsigned int>(i));
			}
		}
	};
}