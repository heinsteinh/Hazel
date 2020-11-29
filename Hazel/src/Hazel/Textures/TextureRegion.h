#pragma once

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class TextureRegion
	{
	public:
		static constexpr glm::vec2 GetNormalizedTranslation(const Rectangle &region, const glm::vec2 &textureSize)
		{
			return Size::IsEmpty(textureSize)
				? glm::vec2(0.0f)
				: region.GetBottomLeft() / textureSize;
		}

		static constexpr glm::vec2 GetScaleRatio(const Rectangle &region, const glm::vec2 &textureSize)
		{
			return Size::IsEmpty(textureSize)
				? glm::vec2(0.0f)
				: region.GetSize() / textureSize;
		}
	};
}