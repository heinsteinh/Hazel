#pragma once

#include "Hazel/Rendering/Textures/Texture.h"

namespace Hazel
{
	class TextureBatch
	{
	private:
		size_t size = 0;
		std::unordered_map<std::shared_ptr<Texture>, size_t> textures;

	public:
		inline TextureBatch(size_t maxTextures)
			: textures(maxTextures)
		{
		}

		inline void Clear()
		{
			size = 0;
		}

		inline size_t Add(const std::shared_ptr<Texture> &texture)
		{
			auto i = textures.find(texture);
			if (i == textures.end())
			{
				assert(size < textures.size());
				return textures[texture] = size++;
			}
			return i->second;
		}

		inline void Bind() const
		{
			for (const auto &[texture, index] : textures)
			{
				texture->Bind(static_cast<unsigned int>(index));
			}
		}
	};
}