#pragma once

#include "BatchInfo.h"
#include "BatchTextureArray.h"
#include "Hazel/GraphicsContext/GraphicsContext.h"
#include "Hazel/Textures/TextureBuilder.h"

namespace Hazel
{
	class BatchTextures
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		BatchTextureArray textures;
		std::shared_ptr<Texture> whiteTexture;

	public:
		BatchTextures(GraphicsContext &graphicsContext, size_t maxTextureSlotCount)
			: graphicsContext(&graphicsContext),
			textures(maxTextureSlotCount),
			whiteTexture(TextureBuilder::CreateFlatTexture(graphicsContext, glm::vec4(1.0f)))
		{
			Add(whiteTexture.get());
		}

		const BatchTextureArray &GetTextures() const
		{
			return textures;
		}

		void Clear()
		{
			textures.SetTextureCount(1);
		}

		std::optional<size_t> Add(Texture *texture)
		{
			if (!texture)
			{
				return 0;
			}
			auto slot = textures.Add(texture);
			if (slot)
			{
				graphicsContext->SetTexture(texture, slot.value());
			}
			return slot;
		}
	};
}