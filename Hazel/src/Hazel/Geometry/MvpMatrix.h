#pragma once

#include "Transform.h"

namespace Hazel
{
	class MvpMatrix
	{
	public:
		static glm::mat4 GetView(const Transform &cameraTransform);
		static glm::mat4 GetViewProjection(const glm::mat4 &view, const glm::mat4 &projection);
	};
}