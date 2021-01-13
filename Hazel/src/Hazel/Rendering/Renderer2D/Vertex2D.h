#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/GraphicsBuffers/VertexLayout.h"

namespace Hazel
{
	struct Vertex2D
	{
		static inline const VertexLayout Layout = {
			{ShaderDataType::Float3},
			{ShaderDataType::Float4},
			{ShaderDataType::Float2},
			{ShaderDataType::Float}
		};

		static constexpr size_t PositionIndex = 0;
		static constexpr size_t ColorIndex = 1;
		static constexpr size_t TextureCoordinatesIndex = 2;
		static constexpr size_t TextureSlotIndex = 3;

		glm::vec3 Position{0.0f};
		glm::vec4 Color{1.0f};
		glm::vec2 TextureCoordinates{0.0f};
		float TextureSlot = 0.0f;
	};
}