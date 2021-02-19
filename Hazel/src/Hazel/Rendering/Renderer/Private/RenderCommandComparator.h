#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Renderer/RenderCommand.h"

namespace Hazel
{
	class RenderCommandComparator
	{
	public:
		static bool ComparePipeline(const RenderCommand &left, const RenderCommand &right)
		{
			return left.Mesh->PrimitiveTopology < right.Mesh->PrimitiveTopology
				|| left.Shader < right.Shader;
		}

		static bool CompareTransparency(const RenderCommand &left, const RenderCommand &right)
		{
			return left.Transparency < right.Transparency;
		}

		static bool CompareZCoordinate(const RenderCommand &left, const RenderCommand &right)
		{
			return left.Transform.Translation.z < right.Transform.Translation.z;
		}

		static bool CompareCameraDistance(const RenderCommand &left, const RenderCommand &right, const glm::vec3 &cameraPosition)
		{
			return glm::distance(left.Transform.Translation, cameraPosition) > glm::distance(right.Transform.Translation, cameraPosition);
		}
	};
}