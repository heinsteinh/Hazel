#pragma once

#include "TextureArray.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"

namespace Hazel
{
	class RendererTextures
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		TextureArray textures;
		std::shared_ptr<Texture> whiteTexture;

	public:
		RendererTextures(GraphicsContext &graphicsContext, size_t slotCount)
			: graphicsContext(&graphicsContext),
			textures(slotCount),
			whiteTexture(TextureFactory::CreateFlatTexture(graphicsContext, glm::vec4(1.0f)))
		{
			textures.Add(whiteTexture.get());
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

		std::optional<size_t> Add(Texture *texture)
		{
			if (!texture)
			{
				return 0;
			}
			return textures.Add(texture);
		}

		void Bind() const
		{
			for (size_t slot = 0; slot < textures.GetTextureCount(); slot++)
			{
				graphicsContext->SetTexture(textures.GetTexture(slot), slot);
			}
		}

		void Clear()
		{
			textures.SetTextureCount(1);
		}
	};
}