#pragma once

#include "Hazel/Graphics/GraphicsContext.h"
#include "Hazel/Textures/Texture.h"

namespace Hazel
{
	class BatchTextures
	{
	private:
		size_t size = 0;
		std::vector<std::shared_ptr<Texture>> textures;

	public:
		inline BatchTextures(size_t maxTextures = 0)
			: textures(maxTextures)
		{
		}

		inline size_t GetMaxSize() const
		{
			return textures.size();
		}

		inline void SetMaxSize(size_t size)
		{
			textures.resize(size);
		}

		constexpr size_t GetSize() const
		{
			return size;
		}

		inline void Clear()
		{
			Resize(0);
		}

		inline void Resize(size_t size)
		{
			this->size = size;
			for (size_t i = size; i < textures.size(); i++)
			{
				textures[i] = nullptr;
			}
		}

		inline std::optional<size_t> Add(const std::shared_ptr<Texture> &texture)
		{
			auto last = textures.begin() + size;
			auto i = std::find(textures.begin(), last, texture);
			if (i == last)
			{
				return TryAdd(texture);
			}
			return i - textures.begin();
		}

		inline void Bind(GraphicsContext &graphicsContext) const
		{
			for (size_t i = 0; i < size; i++)
			{
				graphicsContext.SetTexture(textures[i], static_cast<uint32_t>(i));
			}
		}

	private:
		inline std::optional<size_t> TryAdd(const std::shared_ptr<Texture> &texture)
		{
			if (size == GetMaxSize())
			{
				return {};
			}
			textures[size] = texture;
			return size++;
		}
	};
}