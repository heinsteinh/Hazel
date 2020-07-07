#pragma once

#include "GameObject.h"
#include "RectangleDrawData.h"

namespace Hazel
{
	class RectangularSprite : public GameObject
	{
	public:
		inline RectangularSprite(const glm::vec4 &color, const std::shared_ptr<Texture2D> &texture)
			: GameObject(RectangleDrawData::Get())
		{
			auto &drawData = GetDrawData();
			for (auto &mesh : drawData.Meshes)
			{
				mesh.Color = color;
			}
			drawData.Texture = texture;
		}

		inline void SetColor(const glm::vec4 &color)
		{
			for (auto &mesh : GetDrawData().Meshes)
			{
				mesh.Color = color;
			}
		}

		inline void SetTexture(const std::shared_ptr<Texture2D> &texture)
		{
			GetDrawData().Texture = texture;
		}
	};
}