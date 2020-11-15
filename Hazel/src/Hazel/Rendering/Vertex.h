#pragma once

#include "Hazel/Buffers/VertexAttributes.h"

namespace Hazel
{
	struct Vertex
	{
		static inline const VertexAttributes Attributes = {
			{"a_Position", ShaderDataType::Float3},
			{"a_Color", ShaderDataType::Float4},
			{"a_TextureCoordinate", ShaderDataType::Float2},
			{"a_TextureIndex", ShaderDataType::Float}
		};

		glm::vec3 Position{0.0f};
		glm::vec4 Color{1.0f};
		glm::vec2 TextureCoordinate{0.0f};
		float TextureIndex = 0.0f;
	};
}