#pragma once

#include "Hazel/GraphicsBuffers/VertexAttributes.h"

namespace Hazel
{
	struct Vertex
	{
		static inline const VertexAttributes Attributes = {
			{ShaderDataType::Float3},
			{ShaderDataType::Float4},
			{ShaderDataType::Float2},
			{ShaderDataType::Float}
		};

		glm::vec3 Position{0.0f};
		glm::vec4 Color{1.0f};
		glm::vec2 TextureCoordinate{0.0f};
		float TextureIndex = 0.0f;
	};
}