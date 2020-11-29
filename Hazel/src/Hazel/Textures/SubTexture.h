#pragma once

#include "Texture.h"
#include "TextureRegion.h"

namespace Hazel
{
	class SubTexture
	{
	private:
		std::shared_ptr<Texture> texture;
		glm::vec2 translation{0.0f};
		glm::vec2 scale{1.0f};
		float aspectRatio = 0.0f;

	public:
		SubTexture() = default;

		SubTexture(const std::shared_ptr<Texture> &texture)
			: texture(texture)
		{
			if (texture)
			{
				aspectRatio = texture->GetAspectRatio();
			}
		}

		SubTexture(const std::shared_ptr<Texture> &texture, const Rectangle &region)
			: texture(texture)
		{
			SetRegion(region);
		}

		void SetRegion(const Rectangle &region)
		{
			if (texture)
			{
				auto textureSize = texture->GetSize();
				translation = TextureRegion::GetNormalizedTranslation(region, textureSize);
				scale = TextureRegion::GetScaleRatio(region, textureSize);
				aspectRatio = region.GetAspectRatio();
			}
		}

		glm::vec2 GetSourceCoordinates(const glm::vec2 &coordinates) const
		{
			return texture ? translation + scale * coordinates : glm::vec2(0.0f);
		}

		constexpr float GetAspectRatio() const
		{
			return aspectRatio;
		}

		operator bool() const
		{
			return static_cast<bool>(texture);
		}

		constexpr operator const std::shared_ptr<Texture> &() const
		{
			return texture;
		}
	};
}