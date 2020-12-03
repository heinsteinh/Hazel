#pragma once

#include "Transform.h"
#include "ProjectionInfo.h"

namespace Hazel
{
	class MvpMatrix
	{
	public:
		static glm::mat4 GetModel(const Transform &objectTransform);
		static glm::mat4 GetView(const Transform &cameraTransform);
		static glm::mat4 GetOrthographicProjection(const ProjectionInfo &info);
		static glm::mat4 GetViewProjection(const glm::mat4 &view, const glm::mat4 &projection);
	};
}