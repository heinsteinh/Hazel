#pragma once

#include "Hazel/Rendering/Textures/Texture.h"
#include "Vertex.h"

namespace Hazel
{
	struct Mesh
	{
		glm::vec4 Position = {0.0f, 0.0f, 0.0f, 1.0f};
		glm::vec2 TextureCoordinate{0.0f};
		glm::vec4 Color{1.0f};;
		SharedPtr<Texture> Texture;

		constexpr Vertex ToVertex(int textureIndex = 0) const
		{
			return {
				{Position.x, Position.y, Position.z},
				Color,
				TextureCoordinate,
				textureIndex
			};
		}
	};
}