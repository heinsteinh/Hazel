#pragma once

#include "Texture.h"
#include "TextureCoordinates.h"

namespace Hazel
{
	class SubTexture
	{
	private:
		std::shared_ptr<Texture> texture;
		glm::vec2 shift{0.0f};
		glm::vec2 scale{0.0f};
		float aspectRatio = 0.0f;

	public:
		SubTexture() = default;

		inline SubTexture(const std::shared_ptr<Texture> &texture)
			: texture(texture)
		{
		}

		inline SubTexture(const std::shared_ptr<Texture> &texture, const TextureCoordinates &coordinates)
			: texture(texture)
		{
			SetCoordinates(coordinates);
		}

		inline void SetCoordinates(const TextureCoordinates &coordinates)
		{
			if (texture)
			{
				auto size = texture->GetSize();
				shift = coordinates.GetShift(size);
				scale = coordinates.GetScale(size);
				aspectRatio = coordinates.GetAspectRatio();
			}
		}

		inline glm::vec2 MapCoordinates(const glm::vec2 &coordinates) const
		{
			return texture ? shift + coordinates * scale : glm::vec2(0.0f);
		}

		constexpr float GetAspectRatio() const
		{
			return aspectRatio;
		}

		inline operator bool() const
		{
			return static_cast<bool>(texture);
		}

		constexpr operator const std::shared_ptr<Texture> &() const
		{
			return texture;
		}
	};
}