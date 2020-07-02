#pragma once

#include "Hazel/Utils/Transform.h"
#include "Mesh.h"
#include "Vertex.h"

namespace Hazel
{
	class VertexBuilder
	{
	private:
		glm::mat4 matrix{1.0f};

	public:
		inline VertexBuilder(const Transform &transform)
			: matrix(transform.ToMatrix())
		{
		}

		inline Vertex Build(const Mesh &mesh, int textureIndex)
		{
			return {
				static_cast<glm::vec3>(matrix * mesh.Position),
				mesh.Color,
				mesh.TextureCoordinate,
				textureIndex
			};
		}
	};
}