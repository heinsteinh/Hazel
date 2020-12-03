#pragma once

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
		BatchTextures(GraphicsContext &graphicsContext, size_t maxTextureSlotCount);

		std::optional<size_t> Add(Texture *texture);

		const BatchTextureArray &GetTextures() const
		{
			return textures;
		}

		void Clear()
		{
			textures.SetTextureCount(1);
		}
	};
}