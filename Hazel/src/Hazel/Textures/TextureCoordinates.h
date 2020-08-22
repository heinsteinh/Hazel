#pragma once

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class TextureCoordinates
	{
	private:
		Rectangle rectangle;

	public:
		inline TextureCoordinates(const glm::vec2 &bottomLeft = glm::vec2(0.0f), Size size = Size())
			: rectangle({
				bottomLeft.x,
				bottomLeft.x + size.Width,
				bottomLeft.y,
				bottomLeft.y + size.Height})
		{
		}

		inline TextureCoordinates(Size size)
			: TextureCoordinates(glm::vec2(0.0f), size)
		{
		}

		constexpr glm::vec2 GetShift(Size textureSize) const
		{
			if (textureSize.IsEmpty())
			{
				return glm::vec2(0.0f);
			}
			return {
				rectangle.Left / textureSize.Width,
				rectangle.Bottom / textureSize.Height
			};
		}

		constexpr glm::vec2 GetScale(Size textureSize) const
		{
			if (textureSize.IsEmpty())
			{
				return glm::vec2(0.0f);
			}
			return {
				rectangle.GetWidth() / textureSize.Width,
				rectangle.GetHeight() / textureSize.Height
			};
		}

		constexpr Size GetSize() const
		{
			return rectangle.GetSize();
		}

		constexpr float GetAspectRatio() const
		{
			return rectangle.GetAspectRatio();
		}
	};
}