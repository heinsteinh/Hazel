#include "BatchTextures.h"

namespace Hazel
{
	BatchTextures::BatchTextures(GraphicsContext &graphicsContext, size_t maxTextureSlotCount)
		: graphicsContext(&graphicsContext),
		textures(maxTextureSlotCount),
		whiteTexture(TextureFactory::CreateFlatTexture(graphicsContext, glm::vec4(1.0f)))
	{
		Add(whiteTexture.get());
	}

	std::optional<size_t> BatchTextures::Add(Texture *texture)
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
}