#pragma once

#include "Hazel/Core/Geometry/MvpMatrix.h"

namespace Hazel
{
	struct TransformComponent
	{
		Transform Transform;

		glm::mat4 GetModel() const
		{
			return Transform.ToMatrix();
		}

		glm::mat4 GetView() const
		{
			return MvpMatrix::GetView(Transform);
		}
	};
}