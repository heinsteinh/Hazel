#pragma once

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class TextureRegion
	{
	public:
		static constexpr glm::vec2 GetNormalizedTranslation(const Rectangle &region, Size textureSize)
		{
			if (textureSize.IsEmpty())
			{
				return glm::vec2(0.0f);
			}
			return {
				region.Left / textureSize.Width,
				region.Bottom / textureSize.Height
			};
		}

		static constexpr glm::vec2 GetScaleRatio(const Rectangle &region, Size textureSize)
		{
			if (textureSize.IsEmpty())
			{
				return glm::vec2(0.0f);
			}
			return {
				region.GetWidth() / textureSize.Width,
				region.GetHeight() / textureSize.Height
			};
		}
	};
}