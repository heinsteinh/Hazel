#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Mesh/VertexLayout.h"

namespace Hazel
{
	struct Uniform2D
	{
		static inline const VertexLayout Layout = {
			ShaderDataType::Mat4
		};

		static constexpr size_t ViewProjectionIndex = 0;

		glm::mat4 ViewProjection{1.0f};
	};
}