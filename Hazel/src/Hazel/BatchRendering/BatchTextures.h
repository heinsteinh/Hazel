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
		inline BatchTextures(GraphicsContext &graphicsContext, size_t maxTextureSlotCount)
			: graphicsContext(&graphicsContext),
			textures(maxTextureSlotCount),
			whiteTexture(TextureBuilder(graphicsContext).BuildFlatTexture(glm::vec4(1.0f)))
		{
			textures.Add(whiteTexture);
		}

		inline void Bind() const
		{
			for (size_t i = 0; i < textures.GetTextureCount(); i++)
			{
				graphicsContext->SetTexture(textures.GetTexture(i), static_cast<uint32_t>(i));
			}
		}

		inline const BatchTextureArray &GetTextures() const
		{
			return textures;
		}

		inline void Clear()
		{
			textures.SetTextureCount(1);
		}

		inline std::optional<uint32_t> Add(const std::shared_ptr<Texture> &texture)
		{
			if (!texture)
			{
				return 0;
			}
			auto slot = textures.Add(texture);
			return slot ? static_cast<uint32_t>(slot.value()) : std::optional<uint32_t>();
		}
	};
}