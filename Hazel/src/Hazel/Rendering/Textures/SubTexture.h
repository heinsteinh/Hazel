#pragma once

#include <memory>

#include "glm/glm.hpp"

#include "Texture.h"
#include "Hazel/Core/Geometry/Rectangle.h"

namespace Hazel
{
	class SubTexture
	{
	private:
		std::shared_ptr<Texture> texture;
		Rectangle region;
		glm::vec2 translation{0.0f};
		glm::vec2 scale{1.0f};

	public:
		SubTexture() = default;

		SubTexture(const std::shared_ptr<Texture> &texture)
			: texture(texture)
		{
			if (texture)
			{
				region = Rectangle::FromBottomLeftAndSize(glm::vec2(0.0f), texture->GetSize());
			}
		}

		SubTexture(const std::shared_ptr<Texture> &texture, const Rectangle &region)
			: texture(texture),
			region(region)
		{
			RecomputeTransform();
		}

		const std::shared_ptr<Texture> &GetSource() const
		{
			return texture;
		}

		void SetSource(const std::shared_ptr<Texture> &texture)
		{
			this->texture = texture;
			RecomputeTransform();
		}

		const Rectangle &GetRegion() const
		{
			return region;
		}

		void SetRegion(const Rectangle &region)
		{
			this->region = region;
			RecomputeTransform();
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

	private:
		void RecomputeTransform()
		{
			if (texture && !texture->IsEmpty())
			{
				auto &textureSize = texture->GetSize();
				translation = region.GetBottomLeft() / textureSize;
				scale = region.GetSize() / textureSize;
			}
			else
			{
				translation = glm::vec2(0.0f);
				scale = glm::vec2(1.0f);
			}
		}
	};
}