#pragma once

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class TextureRegion
	{
	public:
		static constexpr glm::vec2 GetNormalizedTranslation(const Rectangle &region, const glm::vec2 &textureSize)
		{
			if (Size::IsEmpty(textureSize))
			{
				return glm::vec2(0.0f);
			}
			return {
				region.Left / textureSize.x,
				region.Bottom / textureSize.y
			};
		}

		static constexpr glm::vec2 GetScaleRatio(const Rectangle &region, const glm::vec2 &textureSize)
		{
			if (Size::IsEmpty(textureSize))
			{
				return glm::vec2(0.0f);
			}
			return {
				region.GetWidth() / textureSize.x,
				region.GetHeight() / textureSize.y
			};
		}
	};
}