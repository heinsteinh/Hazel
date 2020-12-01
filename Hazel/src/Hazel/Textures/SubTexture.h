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
		float aspectRatio = 1.0f;

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
			return translation + scale * coordinates;
		}

		float GetAspectRatio() const
		{
			return aspectRatio;
		}

		Texture *GetSource() const
		{
			return texture.get();
		}

		const std::shared_ptr<Texture> &GetSourceForSharing() const
		{
			return texture;
		}

		operator bool() const
		{
			return static_cast<bool>(texture);
		}

		operator Texture *() const
		{
			return texture.get();
		}
	};
}