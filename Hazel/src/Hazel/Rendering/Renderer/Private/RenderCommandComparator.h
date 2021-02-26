#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Renderer/RenderCommand.h"

namespace Hazel
{
	class RenderCommandComparator
	{
	public:
		static constexpr auto TieForOrthographicProjection(const RenderCommand &command)
		{
			return std::tie(
				command.Transparency,
				command.Transform.Translation.z,
				command.Mesh->PrimitiveTopology,
				command.Shader);
		}

		static constexpr auto TieForPerspectiveProjection(const RenderCommand &command, const float &cameraDistance)
		{
			return std::tie(
				command.Transparency,
				cameraDistance,
				command.Mesh->PrimitiveTopology,
				command.Shader);
		}

		static constexpr bool CompareForOrthographicProjection(const RenderCommand &left, const RenderCommand &right)
		{
			return TieForOrthographicProjection(left) < TieForOrthographicProjection(right);
		}

		static constexpr bool CompareForPerspectiveProjection(const RenderCommand &left, const RenderCommand &right, const glm::vec3 &cameraPosition)
		{
			return TieForPerspectiveProjection(left, glm::distance(left.Transform.Translation, cameraPosition))
				< TieForPerspectiveProjection(left, glm::distance(right.Transform.Translation, cameraPosition));
		}
	};
}