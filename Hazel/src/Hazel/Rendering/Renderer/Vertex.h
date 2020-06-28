#pragma once

#include "Hazel/Rendering/Buffers/BufferLayout.h"

namespace Hazel
{
	struct Vertex
	{
		static inline const BufferLayout Layout = {
			{"a_Position", ShaderDataType::Float3},
			{"a_Color", ShaderDataType::Float4},
			{"a_TextureCoordinate", ShaderDataType::Float2},
			{"a_TextureIndex", ShaderDataType::Integer}
		};

		glm::vec3 Position{0.0f};
		glm::vec4 Color{0.0f};
		glm::vec2 TextureCoordinate{0.0f};
		int TextureIndex = 0;
	};
}