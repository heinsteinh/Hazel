#pragma once

#include "Hazel/Geometry/MvpMatrix.h"

namespace Hazel
{
	struct TransformComponent
	{
		Transform Transform;

		glm::mat4 GetModel() const
		{
			return MvpMatrix::GetModel(Transform);
		}

		glm::mat4 GetView() const
		{
			return MvpMatrix::GetView(Transform);
		}
	};
}