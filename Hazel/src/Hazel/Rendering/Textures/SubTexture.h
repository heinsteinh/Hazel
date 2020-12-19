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
		Rectangle region;

	public:
		SubTexture() = default;

		SubTexture(const std::shared_ptr<Texture> &texture)
			: texture(texture)
		{
			if (texture)
			{
				region = Rectangle::FromBottomLeftAndSize(translation, texture->GetSize());
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
				this->region = region;
				auto &textureSize = texture->GetSize();
				translation = TextureRegion::GetNormalizedTranslation(region, textureSize);
				scale = TextureRegion::GetScaleRatio(region, textureSize);
			}
		}

		const Rectangle &GetRegion() const
		{
			return region;
		}

		Texture *GetSource() const
		{
			return texture.get();
		}

		const std::shared_ptr<Texture> &GetSourceForSharing() const
		{
			return texture;
		}

		glm::vec2 GetSourceCoordinates(const glm::vec2 &coordinates) const
		{
			return translation + scale * coordinates;
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