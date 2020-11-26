#pragma once

#include "VertexInfo.h"

namespace Hazel
{
	struct Mesh
	{
		std::vector<uint32_t> Indices;
		std::vector<VertexInfo> Vertices;

		void SetColor(const glm::vec4 &color)
		{
			for (auto &vertex : Vertices)
			{
				vertex.Color = color;
			}
		}
	};
}