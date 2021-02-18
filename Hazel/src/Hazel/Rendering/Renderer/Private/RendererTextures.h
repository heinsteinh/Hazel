#pragma once

#include "TextureArray.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Rendering/Textures/SubTexture.h"

namespace Hazel
{
	class RendererTextures
	{
	private:
		TextureArray textures;
		std::shared_ptr<Texture> whiteTexture;

	public:
		RendererTextures(GraphicsContext &graphicsContext, size_t slotCount)
			: textures(slotCount),
			whiteTexture(TextureFactory::CreateFlatTexture(graphicsContext, glm::vec4(1.0f)))
		{
			textures.Add(whiteTexture);
		}

		size_t GetSlotCount() const
		{
			return textures.GetSlotCount();
		}

		void SetSlotCount(size_t slotCount)
		{
			textures.SetSlotCount(slotCount);
		}

		size_t GetTextureCount() const
		{
			return textures.GetTextureCount();
		}

		const std::weak_ptr<Texture> &GetTexture(size_t slot) const
		{
			return textures.GetTexture(slot);
		}

		std::optional<size_t> Add(const std::shared_ptr<Texture> &texture)
		{
			return texture ? textures.Add(texture) : 0;
		}

		void Clear()
		{
			textures.SetTextureCount(1);
		}
	};
}